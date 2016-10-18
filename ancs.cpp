#include "ancs.h"

void ANCS::onANCSCharacteristicChanged(QLowEnergyCharacteristic characteristic, QByteArray data) {
    Q_ASSERT(ancsService);

    if (characteristic.uuid() == ancsNotificationSourceCharUUid)
    {
        QByteArray uid = data.right(4);

        QByteArray dataRequest;
        dataRequest.append(ANCSNotification::CommandID::GetNotificationAttributes);
        dataRequest.append(uid);
        dataRequest.append(ANCSNotification::NotificationAttributeID::AppIdentifier);
        dataRequest.append(ANCSNotification::NotificationAttributeID::Title);
        dataRequest.append(2, 0xFF); // Max Size (0xFFFF)
        dataRequest.append(ANCSNotification::NotificationAttributeID::Subtitle);
        dataRequest.append(2, 0xFF); // Max Size (0xFFFF)
        dataRequest.append(ANCSNotification::NotificationAttributeID::Message);
        dataRequest.append(2, 0xFF); // Max Size (0xFFFF)
        dataRequest.append(ANCSNotification::NotificationAttributeID::Date);
        dataRequest.append(ANCSNotification::NotificationAttributeID::PositiveActionLabel);
        dataRequest.append(ANCSNotification::NotificationAttributeID::NegativeActionLabel);

        ancsService->writeCharacteristic(ancsService->characteristic(ancsControlPointCharUUid), dataRequest);
    }
    else if (characteristic.uuid() == ancsDataSourceCharUUid)
    {
        ANCSNotification notification;
        notification.UpdateData(data);
        notifications.append(notification);
        emit newNotification(notifications[notifications.size() - 1]);
    }
}

ANCS::ANCS(QObject *parent) : QObject(parent), ancsService(nullptr), leController(nullptr)
{
}


void ANCS::start()
{
    leController = QLowEnergyController::createPeripheral();
    if (!leController)
    {
        QTextStream(stderr) << "Unable to createPeripheral" << endl;
        emit finished(-1);
        return;
    }

    QObject::connect(
        leController,
        static_cast<void(QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
        this,
        &ANCS::leError
    );

    QObject::connect(leController, &QLowEnergyController::disconnected, this, &ANCS::onDisconnected);
    QObject::connect(leController, &QLowEnergyController::connected, this, &ANCS::onConnected);

    QObject::connect(leController, &QLowEnergyController::serviceDiscovered, this, &ANCS::onServiceDiscovered);
    startAdvertising();
}

void ANCS::stop()
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

void ANCS::startAdvertising()
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

void ANCS::leError(QLowEnergyController::Error error)
{
    stop();
    QTextStream(stderr) << "LEControllerError: " << leController->errorString() << endl;
    emit finished(-1);
}

void ANCS::onServiceDiscovered(const QBluetoothUuid &newService)
{
    // Only deal with ancsServiceUuid
    if (newService != ancsServiceUuid) return;

    Q_ASSERT(ancsService == nullptr);
    ancsService = leController->createServiceObject(newService);
    QObject::connect(ancsService, &QLowEnergyService::stateChanged, this, &ANCS::onServiceStateChanged);
    ancsService->discoverDetails();
}

void ANCS::onServiceStateChanged(QLowEnergyService::ServiceState newState)
{
    Q_ASSERT(ancsService != nullptr);
    // @TODO: Deal with other states
    if (newState == QLowEnergyService::ServiceDiscovered)
    {
        QObject::connect(ancsService, &QLowEnergyService::characteristicChanged, this, &ANCS::onANCSCharacteristicChanged);

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

void ANCS::onDisconnected()
{
    stop();
    start();
}

void ANCS::onConnected()
{
    // Stop advertising
    leController->stopAdvertising();
    // @TODO: Fix this hack in QT Bluetooth lib
    leController->switchRole();

    leController->discoverServices();
}
