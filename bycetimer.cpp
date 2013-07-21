#include "bycetimer.h"

ByceTimer::ByceTimer(QWidget *parent, QString name) : Software(parent, name)
{
    mainTimer = new QTimer;
    mainTimer->setInterval(1000);
    connect(mainTimer, SIGNAL(timeout()), this, SLOT(mainTimerEvent()));

    nameModule = new QLabel(this);
    nameModule->setText(name);
    nameModule->show();

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
        emit byceTimeOut();
        timeBox->setValue(timeVal_);
    }
    else {
        time_--;
        timeBox->setValue(time_);
    }

}
