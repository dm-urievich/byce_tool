#include "bycetimer.h"

ByceTimer::ByceTimer(QString nameModule, int IdModule, QWidget *parent) :
    ModuleGui(nameModule, IdModule, parent)
{
    mainTimer = new QTimer;
    mainTimer->setInterval(1000);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(mainTimerEvent()));

    nameModuleLabel = new QLabel(this);
    nameModuleLabel->setText(nameModule);
    nameModuleLabel->show();

    buttonStart = new QPushButton(this);
    buttonStart->setText("Start");
    buttonStart->resize(50, 25);
    buttonStart->move(0, 125);
    buttonStart->show();
    connect(buttonStart, SIGNAL(clicked()), this, SLOT(startTimerButton()));

    buttonStop = new QPushButton(this);
    buttonStop->setText("Stop");
    buttonStop->resize(50, 25);
    buttonStop->move(50, 125);
    buttonStop->show();
    connect(buttonStop, SIGNAL(clicked()), this, SLOT(stopTimerButton()));

    timeBox = new QSpinBox(this);
    timeBox->setValue(10);
    timeBox->resize(80, 25);
    timeBox->move(10, 50);
    timeBox->show();

    this->resize(100, 150);

    timeOutEvetn_ = false;
}

void ByceTimer::startTimerButton(void)
{
    time_ = timeBox->value();
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
        emit eventForGui(idModule, "timeOutEvent", "1");
        timeOutEvetn_ = true;
        timeBox->setValue(timeVal_);
    }
    else {
        time_--;
        timeBox->setValue(time_);
    }
}

void ByceTimer::parseXml(QDomElement &domElement)
{

}

void ByceTimer::generateXml(QTextStream &out)
{

}

bool ByceTimer::isEvent()
{
    return timeOutEvetn_;
}

void ByceTimer::socket(QString socket, QString dataSocket)
{
    if (socket == "startSocket") {
        if (dataSocket.toInt()) {
            startTimerButton();
        }
    }

    if (socket == "stopSocket") {
        if (dataSocket.toInt()) {
            stopTimerButton();
        }
    }
}

QStringList ByceTimer::getListEvents()
{
    QStringList list;
    list.append("timeOutEvent");

    return list;
}

QStringList ByceTimer::getListSockets()
{
    QStringList list;
    list.append("startSocket");
    list.append("stopSocket");

    return list;
}
