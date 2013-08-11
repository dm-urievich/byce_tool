#include "corebycetoolthread.h"

CoreByceToolThread::CoreByceToolThread(QObject *parent) :
    QThread(parent)
{
    transferHardwareModules = new TransferThread(&hardwareVector);
    transferHardwareModules->start();
}

void CoreByceToolThread::createNewHardwareModule(Hardware *device)
{
    // лок мютекс
    device->moveToThread(transferHardwareModules);
    hardwareVector.push_back(device);

}
