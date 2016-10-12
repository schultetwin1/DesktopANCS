#include <QCoreApplication>
#include <QLowEnergyAdvertisingData>
#include <QLowEnergyAdvertisingParameters>
#include <QTextStream>
#include <QScopedPointer>
#include <QLowEnergyController>
#include <QBluetoothLocalDevice>
#include <QLowEnergyServiceData>
#include <QLoggingCategory>

#include "ancsservice.h"

const QBluetoothUuid ancsServiceUuid = QBluetoothUuid(QString("{7905F431-B5CE-4E99-A40F-4B1E122D00D0}"));
const QBluetoothUuid ancsNotificationSourceCharUUid = QBluetoothUuid(QString("9FBF120D-6301-42D9-8C58-25E699A21DBD"));
const QBluetoothUuid ancsDataSourceCharUUid = QBluetoothUuid(QString("22EAC6E9-24D6-4BB5-BE44-B36ACE7C7BFB"));
const QBluetoothUuid ancsControlPointCharUUid = QBluetoothUuid(QString("69D1D8F3-45E1-49A8-9821-9BBDFDAAD9D9 "));

void processNotifiation(QLowEnergyCharacteristic characteristic, QByteArray data, QLowEnergyService* service) {
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

int main(int argc, char *argv[])
{
    //QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    QCoreApplication a(argc, argv);

    QBluetoothLocalDevice localDevice;
    QLowEnergyService* ancsService;
    QLowEnergyController* leController = QLowEnergyController::createPeripheral();

    ANCSService ancs;

    if (!leController)
    {
        QTextStream(stdout) << "Unable to create peripheral le device" << endl;
        return -1;
    }

    if (localDevice.hostMode() == QBluetoothLocalDevice::HostPoweredOff)
    {
        QTextStream(stdout) << "Bluetooth Device Powered Off" << endl;
        return -1;
    }

    QTextStream(stdout) << "Discoverable as " << localDevice.name() << endl;
    QTextStream(stdout) << "Note: If this has been changed iOS may have cached the name as something else" << endl;

    QObject::connect(&localDevice, &QBluetoothLocalDevice::error, [&](QBluetoothLocalDevice::Error error){
        QTextStream(stdout) << "Local Device Error: " << error << endl;
        a.exit(-1);
    });

    QLowEnergyAdvertisingData advertisingData;
    // @TODO: Add solicited UUIDs in Qt Bluetooth library
    // advertisingData.setDiscoverability(QLowEnergyAdvertisingData::DiscoverabilityGeneral);
    // advertisingData.setIncludePowerLevel(true);
    // advertisingData.setLocalName("ANCS");

    // advertisingData.setServices(QList<QBluetoothUuid>() << ancsServiceUuid);

    // Needed to do this manually to get service solication (0x15)
    advertisingData.setRawData(QByteArray::fromHex("020a070201060509414e43531115d0002d121e4b0fa4994eceb531f40579"));

    // Hook up error
    QObject::connect(
        leController,
        static_cast<void(QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
        [&](QLowEnergyController::Error error) {
            QTextStream(stdout) << "QLowEnergyControllerError: " << error << endl;
            QTextStream(stdout) << leController->errorString() << endl;
            a.exit(-1);
        }
    );

    QObject::connect(leController, &QLowEnergyController::serviceDiscovered, [&](const QBluetoothUuid &newService){
        if (newService == ancsServiceUuid)
        {
            QTextStream(stdout) << "Found ANCS" << endl;
            ancsService = leController->createServiceObject(newService);
            QObject::connect(ancsService, &QLowEnergyService::stateChanged, [&](QLowEnergyService::ServiceState newState){
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
            });
            ancsService->discoverDetails();
        }
    });

    QObject::connect(leController, &QLowEnergyController::disconnected, [&](){
        QTextStream(stdout) << "Remote disconnected!" << endl;
        a.exit(-1);
    });

    QObject::connect(&localDevice, &QBluetoothLocalDevice::deviceConnected, [&](){
        leController->stopAdvertising();
        // @TODO: Fix this hack in QT Bluetooth lib
        leController->switchRole();
        leController->discoverServices();
    });

    QLowEnergyAdvertisingParameters params;
    // Set very small advertising interval to be discovered
    params.setInterval(20,20);
    leController->startAdvertising(params, advertisingData, advertisingData);
    return a.exec();
}
