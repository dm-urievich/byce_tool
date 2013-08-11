#ifndef TRANSFERTHREAD_H
#define TRANSFERTHREAD_H

#include <QThread>
#include <QDebug>
#include <QVector>
#include <QTime>

#include "hardware.h"

class TransferThread : public QThread
{
    Q_OBJECT
public:
    explicit TransferThread(QVector<Hardware*> *hardwareVector, QObject *parent = 0);


protected:
    void run();

private:
    volatile unsigned int period_;
    QVector<Hardware*> *hardwareVector_;
    
signals:
    void transferTime(int time);

public slots:
    void setPeriod(int data);
    
};

#endif // TRANSFERTHREAD_H
