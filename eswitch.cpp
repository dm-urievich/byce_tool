#include "eswitch.h"

eSwitch::eSwitch(QWidget *parent, QString name, int addr) : Hardware(parent), name(name)
{

    this->mbAddr = addr;

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

    this->resize(100, 125);
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

    modbus_set_slave(this->mbPort, this->mbAddr);
    modbus_read_registers(this->mbPort, regAddr, 1, &data);

    return data;
}

void eSwitch::setMbPort(modbus_t *port)
{
    mbPort = port;
}

void eSwitch::setMbAddr(int addr)
{
    this->mbAddr = addr;
}

void eSwitch::on()
{
    int addr;
    int regAddr = 0;
    int data = 1;

    addr = this->mbAddr;

    modbus_set_slave(this->mbPort, addr);
    modbus_write_register(this->mbPort, regAddr, data);
}

void eSwitch::off()
{
    int addr;
    int regAddr = 0;
    int data = 0;

    addr = this->mbAddr;

    modbus_set_slave(this->mbPort, addr);
    modbus_write_register(this->mbPort, regAddr, data);
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
