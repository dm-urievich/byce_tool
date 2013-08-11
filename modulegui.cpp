#include "modulegui.h"

ModuleGui::ModuleGui(QWidget *parent) :
    QWidget(parent)
{
}

/*

hardware!

    enableReadCheck = new QCheckBox(parent);
    enableReadCheck->setChecked(true);

void Hardware::settingsButtonClick(void)
{
    HardwareSettingsDialog settingsWindow(0, "eSwitch.h", this);
}

end hardware!

  eswitch!

  constructor

    readTimer = new QTimer;
    readTimer->start(500);
    connect(readTimer, SIGNAL(timeout()), this, SLOT(readTimerEvent()));

    nameDev = new QLabel(this);
    nameDev->setText(name);
    nameDev->show();


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

end of eswitch!

software!


end software!

bycetimer!

constructor

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






















  */
