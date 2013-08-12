#ifndef COREBYCETOOLTHREAD_H
#define COREBYCETOOLTHREAD_H

#include <QThread>
#include <QVector>
#include <QMutex>

#include "hardware.h"
#include "software.h"
#include "transferthread.h"


class CoreByceToolThread : public QThread
{
    Q_OBJECT
public:
    explicit CoreByceToolThread(QObject *parent = 0);
    
signals:
    void guiRefresh();
    void setTransferPeriod(int);

public slots:
    void createNewHardwareModule(Hardware *device);
    void generateXmlHardware(bool isEvent);

protected:
    void run();

private:
    TransferThread* transferHardwareModules;

    QVector<Hardware*> hardwareVector;
    QVector<Software*> softwareVector;

    QMutex lockHardwareVector;

};

#endif // COREBYCETOOLTHREAD_H
