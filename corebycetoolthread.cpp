#include "corebycetoolthread.h"

CoreByceToolThread::CoreByceToolThread(QObject *parent) :
    QThread(parent)
{
    transferHardwareModules = new TransferThread(&hardwareVector, &lockHardwareVector);

    connect(transferHardwareModules, SIGNAL(eventInModule(bool)), this, SLOT(generateXmlHardware(bool)));
    connect(this, SIGNAL(setTransferPeriod(int)), transferHardwareModules, SLOT(setPeriod(int)));
}

void CoreByceToolThread::run()
{
    transferHardwareModules->start();

    this->exec();
}

void CoreByceToolThread::createNewHardwareModule(Hardware *device)
{
    QMutexLocker locker(&lockHardwareVector);

    device->moveToThread(transferHardwareModules);
    hardwareVector.push_back(device);
}

void CoreByceToolThread::generateXmlHardware(bool isEvent)
{
    QVector<Hardware*>::Iterator device;

    QFile outFile("moduleEvents.xml");
    if (outFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&outFile);
        out.setCodec("UTF-8");
        out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        out << "<module>\n";

        lockHardwareVector.lock();
        for (device = hardwareVector.begin(); device != hardwareVector.end(); ++device) {
            if (isEvent) {
                if ((*device)->isEvent()) {
                    (*device)->generateXml(out);
                }
            }
            else {
                (*device)->generateXml(out);        // для инициализации Gui, генерим состояние всех девайсов
            }
        }
        lockHardwareVector.unlock();

        out << "</module>\n";
        outFile.close();

        emit guiRefresh();
    }
}
