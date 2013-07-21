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

    eSwitchOutState = false;
    dInState = false;

    mainButton = new QPushButton(this);
    mainButton->move(0, 25);
    mainButton->resize(100, 100);
    changeButtonIcon();
    mainButton->setIconSize(QSize(100, 100));
    mainButton->show();
    connect(mainButton, SIGNAL(clicked()), this, SLOT(mainButtonClick()));

    dInStateButton = new QRadioButton(this);
    dInStateButton->move(25, 125);
    dInStateButton->resize(25, 25);
    //dInStateButton->setDisabled(true);
    dInStateButton->show();

    settingsButton = new QPushButton(this);
    settingsButton->move(0, 125);
    settingsButton->resize(25, 25);
    settingsButton->setText(QString::fromLocal8Bit("..."));
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
    bool prevState = dInState;
    int regAddr = 0;
    quint16 data[3];

    //data = readReg(regAddr);
    readRegisters(regAddr, 3, data);

    if (data[0] == 1) {
        eSwitchOutState = true;
    }
    else {
        eSwitchOutState = false;
    }

    if (data[2] == 1)
        dInState = true;
    else
        dInState = false;

    dInStateButton->setChecked(dInState);

    if (!dInState && prevState)     // задний фронт
        emit dInFall();
    else
        if (dInState && !prevState) // передний фронт
            emit dInRaise();

    changeButtonIcon();
}

bool eSwitch::getState()
{
    return eSwitchOutState;
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
  /*  if (eSwitchOutState) {
        eSwitchOutState = false;
    }
    else {
        eSwitchOutState = true;
    }
    */
    eSwitchOutState != eSwitchOutState;

    changeButtonIcon();

    if (eSwitchOutState) {
        on();
    }
    else {
        off();
    }
}

void eSwitch::changeButtonIcon(void)
{
    if (eSwitchOutState) {
        mainButton->setIcon(QIcon(":/img/lampOn.png"));
    }
    else {
        mainButton->setIcon(QIcon(":/img/lampOff.png"));
    }
}
