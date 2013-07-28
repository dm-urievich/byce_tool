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

    // кнопка с настройками
    settingsButton = new QPushButton(this);
    settingsButton->move(0, 125);
    settingsButton->resize(25, 25);
    settingsButton->setText(QString::fromLocal8Bit("..."));
    settingsButton->show();
    connect(settingsButton, SIGNAL(clicked()), this, SLOT(settingsButtonClick()));

    // кнопа включения/выключения обмена
    enableReadCheck->setParent(this);
    enableReadCheck->resize(20,25);
    enableReadCheck->move(80, 125);
    enableReadCheck->show();

    adcDataLable = new QLabel(this);
    adcDataLable->move(50, 125);
    adcDataLable->resize(30, 25);
    adcDataLable->setAlignment(Qt::AlignRight);
    adcDataLable->setText("0");
    adcDataLable->show();

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
    int adcData = 0;
    quint16 data[6];

    //data = readReg(regAddr);
    readRegisters(regAddr, 6, data);

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

    // заполняем данные с АЦП
    adcData = data[5];
    adcDataLable->setText(QString::number(adcData));
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
    if (eSwitchOutState) {
        eSwitchOutState = false;
    }
    else {
        eSwitchOutState = true;
    }

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
