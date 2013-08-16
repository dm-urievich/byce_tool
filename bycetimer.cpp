#include "bycetimer.h"

ByceTimer::ByceTimer(QObject *parent, QString name) : Software(parent, name)
{
}

void ByceTimer::startTimerButton(void)
{
  //  time_ = timeBox->value();
    timeVal_ = time_;
    mainTimer->start();
}

void ByceTimer::stopTimerButton(void)
{
    mainTimer->stop();
}

void ByceTimer::mainTimerEvent(void)
{
    if (time_ == 0) {
        stopTimerButton();
        emit byceTimeOut();
       // timeBox->setValue(timeVal_);
    }
    else {
        time_--;
        //timeBox->setValue(time_);
    }
}

void ByceTimer::parseXml(QDomElement &domElement)
{

}

void ByceTimer::generateXml(QTextStream &out)
{

}
