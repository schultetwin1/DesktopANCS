#include <QDataStream>

#include "ancs.h"

void ANCS::onANCSCharacteristicChanged(QLowEnergyCharacteristic characteristic, QByteArray data) {
    Q_ASSERT(leController);

    if (characteristic.uuid() == ancsNotificationSourceCharUUid)
    {
        QDataStream dataStream(&data, QIODevice::ReadOnly);
        dataStream.setByteOrder(QDataStream::LittleEndian);
        uint8_t eventId, flags, categoryId, categoryCount;
        uint32_t uid;
        dataStream >> eventId;
        dataStream >> flags;
        dataStream >> categoryId;
        dataStream >> categoryCount;
        dataStream >> uid;

        if (eventId == ANCSNotification::EventID::NotificationAdded ||
            eventId == ANCSNotification::EventID::NotificationModified)
        {
            const uint16_t MAX_SIZE = 0xFFFF;
            QByteArray buffer;
            QDataStream request(&buffer, QIODevice::WriteOnly);
            request.setByteOrder(QDataStream::LittleEndian);

            request << ANCSNotification::CommandID::GetNotificationAttributes;
            request << uid;
            request << ANCSNotification::NotificationAttributeID::AppIdentifier;
            request << ANCSNotification::NotificationAttributeID::Title;
            request << MAX_SIZE;
            request << ANCSNotification::NotificationAttributeID::Subtitle;
            request << MAX_SIZE;
            request << ANCSNotification::NotificationAttributeID::Message;
            request << MAX_SIZE;
            request << ANCSNotification::NotificationAttributeID::Date;
            request << ANCSNotification::NotificationAttributeID::PositiveActionLabel;
            request << ANCSNotification::NotificationAttributeID::NegativeActionLabel;

            ancsService->writeCharacteristic(ancsService->characteristic(ancsControlPointCharUUid), buffer);
        }
        else
        {
            std::remove_if(notifications.begin(), notifications.end(), [&uid](ANCSNotification& n) {
                return n.getUid() == uid;
            });
        }
    }
    else if (characteristic.uuid() == ancsDataSourceCharUUid)
    {
        ANCSNotification notification;
        notification.UpdateData(data);
        notifications.push_back(notification);
        emit newNotification(notifications[notifications.size() - 1]);
    }
}

ANCS::ANCS(QObject *parent) : QObject(parent), ancsService(nullptr)
{
    leController = QLowEnergyController::createPeripheral(this);

    QObject::connect(
        leController,
        static_cast<void(QLowEnergyController::*)(QLowEnergyController::Error)>(&QLowEnergyController::error),
        this,
        &ANCS::leError
    );

    QObject::connect(leController, &QLowEnergyController::disconnected, this, &ANCS::onDisconnected);
    QObject::connect(leController, &QLowEnergyController::connected, this, &ANCS::onConnected);

    QObject::connect(leController, &QLowEnergyController::serviceDiscovered, this, &ANCS::onServiceDiscovered);
}

ANCS::~ANCS()
{
    stop();
}

void ANCS::start()
{
    startAdvertising();
}

void ANCS::stop()
{
    leController->stopAdvertising();
    leController->disconnectFromDevice();

    if (ancsService)
    {
        delete ancsService;
        ancsService = nullptr;
    }
    Q_ASSERT(!ancsService);
}

void ANCS::startAdvertising()
{
    Q_ASSERT(leController);
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
    Q_ASSERT(leController);
    QTextStream(stderr) << "LEControllerError: " << leController->errorString() << endl;
    stop();
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
    if (newState == QLowEnergyService::InvalidService)
    {
        Q_ASSERT(ancsService);
        delete ancsService;
        ancsService = nullptr;
        return;
    }

    Q_ASSERT(leController);

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
    Q_ASSERT(leController);
    // If disconnect happened due to error, stop will have already occured
    if (leController->error() != QLowEnergyController::NoError) return;

    stop();
    leController->switchRole();
    start();
}

void ANCS::onConnected()
{
    Q_ASSERT(leController);

    leController->stopAdvertising();
    // @TODO: Fix this hack in QT Bluetooth lib
    leController->switchRole();
    leController->discoverServices();
}
