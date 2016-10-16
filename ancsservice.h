#ifndef ANCSSERVICE_H
#define ANCSSERVICE_H

#include <QObject>
#include <QString>
#include <QCoreApplication>
#include <QLowEnergyAdvertisingData>
#include <QLowEnergyAdvertisingParameters>
#include <QTextStream>
#include <QScopedPointer>
#include <QLowEnergyController>
#include <QBluetoothLocalDevice>
#include <QLowEnergyServiceData>
#include <QLoggingCategory>

const QBluetoothUuid ancsServiceUuid = QBluetoothUuid(QString("{7905F431-B5CE-4E99-A40F-4B1E122D00D0}"));
const QBluetoothUuid ancsNotificationSourceCharUUid = QBluetoothUuid(QString("9FBF120D-6301-42D9-8C58-25E699A21DBD"));
const QBluetoothUuid ancsDataSourceCharUUid = QBluetoothUuid(QString("22EAC6E9-24D6-4BB5-BE44-B36ACE7C7BFB"));
const QBluetoothUuid ancsControlPointCharUUid = QBluetoothUuid(QString("69D1D8F3-45E1-49A8-9821-9BBDFDAAD9D9 "));

class ANCSService : public QObject
{
    Q_OBJECT
public:
    struct CategoryID {
        const static uint8_t Other              = 0;
        const static uint8_t IncomingCall       = 1;
        const static uint8_t MissedCall         = 2;
        const static uint8_t Voicemail          = 3;
        const static uint8_t Social             = 4;
        const static uint8_t Schedule           = 5;
        const static uint8_t Email              = 6;
        const static uint8_t News               = 7;
        const static uint8_t HealthAndFitness   = 8;
        const static uint8_t BusinessAndFinance = 9;
        const static uint8_t Location           = 10;
        const static uint8_t Entertainment      = 11;
    };

    struct EventID {
        const static uint8_t NotificationAdded    = 0;
        const static uint8_t NotificationModified = 1;
        const static uint8_t NotificationRemoved  = 2;
    };

    struct EventFlags {
        const static uint8_t Silent         = ( 1 << 0 );
        const static uint8_t Important      = ( 1 << 1 );
        const static uint8_t PreExisting    = ( 1 << 2 );
        const static uint8_t PositiveAction = ( 1 << 3 );
        const static uint8_t NegativeAction = ( 1 << 4 );
    };

    struct CommandID {
        const static uint8_t GetNotificationAttributes = 0;
        const static uint8_t GetAppAttributes          = 1;
        const static uint8_t PerformNotificationAction = 2;
    };

    struct NotificationAttributeID {
        const static uint8_t AppIdentifier       = 0;
        const static uint8_t Title               = 1;
        const static uint8_t Subtitle            = 2;
        const static uint8_t Message             = 3;
        const static uint8_t MessageSize         = 4;
        const static uint8_t Date                = 5;
        const static uint8_t PositiveActionLabel = 6;
        const static uint8_t NegativeActionLabel = 7;
    };

    struct ActionID {
        const static uint8_t Positive = 0;
        const static uint8_t Negative = 1;
    };

    struct AppAttributeID {
        const static uint8_t DisplayName = 0;
    };

    explicit ANCSService(QObject *parent = 0);

signals:
    void finished(int error);

public slots:
    void start();
    void stop();

private:
    QLowEnergyService* ancsService;
    QLowEnergyController* leController = QLowEnergyController::createPeripheral();

    void startAdvertising();

private slots:
    void leError(QLowEnergyController::Error error);
    void onServiceDiscovered(const QBluetoothUuid &newService);
    void onServiceStateChanged(QLowEnergyService::ServiceState newState);
    void onDisconnected();
    void onConnected();

};

#endif // ANCSSERVICE_H
