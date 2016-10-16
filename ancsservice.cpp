#include "ancsservice.h"

static void processNotifiation(QLowEnergyCharacteristic characteristic, QByteArray data, QLowEnergyService* service) {
    if (characteristic.uuid() == ancsNotificationSourceCharUUid)
    {
        QByteArray uid = data.right(4);
        QTextStream(stdout) << "Received Notification: " << data.toHex() << "(" << data.size() << ")" << endl;
        QTextStream(stdout) << "\tUID: " << uid.toHex() << endl;
        QTextStream(stdout) << "\tEventID: " << static_cast<unsigned>(data[0]) << endl;
        QTextStream(stdout) << "\tEventFlags: 0x" << hex <<  static_cast<unsigned>(data[1]) << endl;
        QTextStream(stdout) << "\tCategoryID: " << static_cast<unsigned>(data[2]) << endl;
        QTextStream(stdout) << "\tCategoryCount: " << static_cast<unsigned>(data[3]) << endl;

        QByteArray dataRequest;
        dataRequest.append(ANCSService::CommandID::GetNotificationAttributes);
        dataRequest.append(uid);
        dataRequest.append(ANCSService::NotificationAttributeID::AppIdentifier);
        dataRequest.append(ANCSService::NotificationAttributeID::Title);
        dataRequest.append(2, 0xFF); // Max Size (0xFFFF)
        dataRequest.append(ANCSService::NotificationAttributeID::Subtitle);
        dataRequest.append(2, 0xFF); // Max Size (0xFFFF)
        dataRequest.append(ANCSService::NotificationAttributeID::Message);
        dataRequest.append(2, 0xFF); // Max Size (0xFFFF)
        dataRequest.append(ANCSService::NotificationAttributeID::Date);
        dataRequest.append(ANCSService::NotificationAttributeID::PositiveActionLabel);
        dataRequest.append(ANCSService::NotificationAttributeID::NegativeActionLabel);

        service->writeCharacteristic(service->characteristic(ancsControlPointCharUUid), dataRequest);
    }
    else if (characteristic.uuid() == ancsDataSourceCharUUid)
    {
        QTextStream(stdout) << "Received Data Source: " << data.toHex() << "(" << data.size() << ")" << endl;
        QByteArray uid = data.mid(1, 4);
        QTextStream(stdout) << "\tUID: " << uid.toHex() << endl;
        data.remove(0, 5);
        system("notify-send 'Hello world!' 'This is an example notification.' --icon=dialog-information");
        while (!data.isEmpty())
        {
            uint8_t attrID = data[0];
            QTextStream(stdout) << "\tAttributeID: " << static_cast<unsigned>(attrID) << endl;
            data.remove(0,1);

            uint16_t attrLength = data[0] | (data[1] << 8);
            data.remove(0,2);

            QByteArray attr = data.left(attrLength);
            QTextStream(stdout) << "\tData: " << attr.toStdString().c_str() << endl;
            data.remove(0, attrLength);

        }
    }
}

ANCSService::ANCSService(QObject *parent) : QObject(parent), ancsService(nullptr), leController(nullptr)
{
}


void ANCSService::start()
{
    leController = QLowEnergyController::createPeripheral();
    if (!leController)
    {
        // @TODO: Deal with failed QLowEnergyController create peripheral
    }

    QObject::connect(
        leController,
        static_cast<void(QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
        this,
        &ANCSService::leError
    );

    QObject::connect(leController, &QLowEnergyController::disconnected, this, &ANCSService::onDisconnected);
    QObject::connect(leController, &QLowEnergyController::connected, this, &ANCSService::onConnected);

    QObject::connect(leController, &QLowEnergyController::serviceDiscovered, this, &ANCSService::onServiceDiscovered);
    startAdvertising();
}

void ANCSService::stop()
{
    if (ancsService)
    {
        delete ancsService;
    }
    if (leController)
    {
        leController->stopAdvertising();
        leController->disconnectFromDevice();
    }
}

void ANCSService::startAdvertising()
{
    QLowEnergyAdvertisingData advertisingData;
    QLowEnergyAdvertisingParameters params;
    // @TODO: Add solicited UUIDs in Qt Bluetooth library

    // Needed to do this manually to get service solication (0x15)
    advertisingData.setRawData(QByteArray::fromHex("020a070201060509414e43531115d0002d121e4b0fa4994eceb531f40579"));
    // Set very small advertising interval to be discovered
    params.setInterval(20,20);

    leController->startAdvertising(params, advertisingData, advertisingData);
}

void ANCSService::leError(QLowEnergyController::Error error)
{
    stop();
    emit finished(-1);
}

void ANCSService::onServiceDiscovered(const QBluetoothUuid &newService)
{
    // Only deal with ancsServiceUuid
    if (newService != ancsServiceUuid) return;

    Q_ASSERT(ancsService == nullptr);
    ancsService = leController->createServiceObject(newService);
    QObject::connect(ancsService, &QLowEnergyService::stateChanged, this, &ANCSService::onServiceStateChanged);
    ancsService->discoverDetails();
}

void ANCSService::onServiceStateChanged(QLowEnergyService::ServiceState newState)
{
    Q_ASSERT(ancsService == nullptr);
    // @TODO: Deal with other states
    if (newState == QLowEnergyService::ServiceDiscovered)
    {
        QObject::connect(ancsService, &QLowEnergyService::characteristicChanged,[&](QLowEnergyCharacteristic characteristic, QByteArray data){
            processNotifiation(characteristic, data, ancsService);
        });

        // enable notifications
        QLowEnergyDescriptor notification;
        auto ancsNotification = ancsService->characteristic(ancsNotificationSourceCharUUid);
        auto ancsData = ancsService->characteristic(ancsDataSourceCharUUid);

        notification = ancsData.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
        ancsService->writeDescriptor(notification, QByteArray::fromHex("0100"));
        notification = ancsNotification.descriptor(QBluetoothUuid::ClientCharacteristicConfiguration);
        ancsService->writeDescriptor(notification, QByteArray::fromHex("0100"));
    }
}

void ANCSService::onDisconnected()
{
    stop();
    start();
}

void ANCSService::onConnected()
{
    // Stop advertising
    leController->stopAdvertising();
    // @TODO: Fix this hack in QT Bluetooth lib
    leController->switchRole();

    leController->discoverServices();
}
