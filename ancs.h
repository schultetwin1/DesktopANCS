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

#include <vector>

#include "ancsnotification.h"
#include "le_controller.h"

const QBluetoothUuid ancsServiceUuid = QBluetoothUuid(QString("{7905F431-B5CE-4E99-A40F-4B1E122D00D0}"));
const QBluetoothUuid ancsNotificationSourceCharUUid = QBluetoothUuid(QString("9FBF120D-6301-42D9-8C58-25E699A21DBD"));
const QBluetoothUuid ancsDataSourceCharUUid = QBluetoothUuid(QString("22EAC6E9-24D6-4BB5-BE44-B36ACE7C7BFB"));
const QBluetoothUuid ancsControlPointCharUUid = QBluetoothUuid(QString("69D1D8F3-45E1-49A8-9821-9BBDFDAAD9D9 "));

class ANCS : public QObject
{
    Q_OBJECT

public:
    explicit ANCS(QObject *parent = 0);
    ~ANCS();

signals:
    void finished(int error);
    void newNotification(const ANCSNotification&);

public slots:
    void start();
    void stop();

private:
    QLowEnergyService* ancsService;
    LEController leController;
    std::vector<ANCSNotification> notifications;

    void startAdvertising();

private slots:
    void leError(QLowEnergyController::Error error);
    void onServiceDiscovered(const QBluetoothUuid &newService);
    void onServiceStateChanged(QLowEnergyService::ServiceState newState);
    void onDisconnected();
    void onConnected();
    void onANCSCharacteristicChanged(QLowEnergyCharacteristic, QByteArray);

};

#endif // ANCSSERVICE_H
