#include "transferthread.h"

TransferThread::TransferThread(QVector<Hardware *> *hardwareVector, QObject *parent) :
    QThread(parent)
{
    hardwareVector_ = hardwareVector;
    period_ = 1000;     // по умолчанию будет 1 с
}

void TransferThread::run()
{
    QVector<Hardware*>::Iterator device;// = hardwareVector_->begin();
    QTime timer;
    timer.start();

    for (;;) {
        timer.restart();
        for (device = hardwareVector_->begin(); device != hardwareVector_->end(); ++device) {
            if ((*device)->refresh()) {
                if ((*device)->isEvent()) {
                    qDebug() << "Event in " << (*device)->name;
                    QFile file((*device)->name + ".xml");
                    if (file.open(QIODevice::WriteOnly)) {
                        (*device)->generateXml(&file);
                        file.close();
                    }
                }
            }
            else {
                qDebug() << "No response " << (*device)->name;
            }
            msleep(2);  // время на раздупление (скорее аппаратной части)
        }
        emit transferTime(timer.elapsed());

        //qDebug() << "I am in thread :)";
        // для честного опроса нужно от периода вычитать время потраченное на выполнение
        msleep(period_);
    }
}

void TransferThread::setPeriod(int data)
{
    period_ = data;
}
