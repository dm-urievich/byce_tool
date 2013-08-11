#ifndef COREBYCETOOLTHREAD_H
#define COREBYCETOOLTHREAD_H

#include <QThread>
#include <QVector>

#include "hardware.h"
#include "software.h"
#include "transferthread.h"


class CoreByceToolThread : public QThread
{
    Q_OBJECT
public:
    explicit CoreByceToolThread(QObject *parent = 0);
    
signals:
    
public slots:
    void createNewHardwareModule(Hardware *device);

private:
    TransferThread* transferHardwareModules;

    QVector<Hardware*> hardwareVector;
    QVector<Software*> softwareVector;


};

#endif // COREBYCETOOLTHREAD_H
