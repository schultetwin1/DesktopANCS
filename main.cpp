#include "ancs.h"


int main(int argc, char *argv[])
{
    //QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    QCoreApplication a(argc, argv);

    QBluetoothLocalDevice localDevice;
    ANCS ancs;

    if (localDevice.hostMode() == QBluetoothLocalDevice::HostPoweredOff)
    {
        QTextStream(stdout) << "Bluetooth Device Powered Off" << endl;
        return -1;
    }

    QTextStream(stdout) << "Discoverable as " << localDevice.name() << endl;
    QTextStream(stdout) << "Note: If this has been changed, iOS may have cached the name as something else" << endl;

    QObject::connect(&localDevice, &QBluetoothLocalDevice::error, [&](QBluetoothLocalDevice::Error error){
        QTextStream(stdout) << "Local Device Error: " << error << endl;
        ancs.stop();
        a.exit(-1);
    });

    QObject::connect(&ancs, &ANCS::finished, &a, &QCoreApplication::exit);

    ancs.start();


    return a.exec();
}
