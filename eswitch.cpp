#include "eswitch.h"

eSwitch::eSwitch(QWidget *parent, QString name, int addr) : Hardware(parent, name)
{

    mbAddr_ = addr;

    readTimer = new QTimer;
    readTimer->start(500);
    connect(readTimer, SIGNAL(timeout()), this, SLOT(readTimerEvent()));

    nameDev = new QLabel(this);
    nameDev->setText(name);
    nameDev->show();

    eSwitchOutState = e_off;

    mainButton = new QPushButton(this);
    mainButton->move(0, 25);
    mainButton->resize(100, 100);
    changeButtonIcon();
    mainButton->setIconSize(QSize(100, 100));
    mainButton->show();
    connect(mainButton, SIGNAL(clicked()), this, SLOT(mainButtonClick()));

    settingsButton = new QPushButton(this);
    settingsButton->move(0, 125);
    settingsButton->resize(100, 25);
    settingsButton->setText(QString::fromLocal8Bit("Настройки"));
    settingsButton->show();
    connect(settingsButton, SIGNAL(clicked()), this, SLOT(settingsButtonClick()));

    this->resize(100, 150);
}

void eSwitch::paintEvent(QPaintEvent *event)
{
//    QPainter paint(this);

    //paint.setPen(palette().foreground().color());
  //  paint.drawLine(0, 0, 10, 10);

}

void eSwitch::readTimerEvent(void)
{
    if (getState() == 1) {
        eSwitchOutState = e_on;
    }
    else {
        eSwitchOutState = e_off;
    }
    changeButtonIcon();
}

quint16 eSwitch::getState()
{
    int regAddr = 0;
    quint16 data;

    data = readReg(regAddr);

    return data;
}

void eSwitch::on()
{
    int regAddr = 0;
    int data = 1;

    writeReg(regAddr, data);
}

void eSwitch::off()
{
    int regAddr = 0;
    int data = 0;

    writeReg(regAddr, data);
}

void eSwitch::mainButtonClick(void)
{
    if (eSwitchOutState == e_off) {
        eSwitchOutState = e_on;
    }
    else {
        eSwitchOutState = e_off;
    }

    changeButtonIcon();

    if (eSwitchOutState == e_off) {
        off();
    }
    else {
        on();
    }
}

void eSwitch::changeButtonIcon(void)
{
    if (eSwitchOutState == e_off) {
         mainButton->setIcon(QIcon(":/img/lampOff.png"));
    }
    else {
         mainButton->setIcon(QIcon(":/img/lampOn.png"));
    }
}
