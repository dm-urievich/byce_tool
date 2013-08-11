#include "modbusswitchgui.h"

ModbusSwitchGui::ModbusSwitchGui(QString nameModule, int IdModule, QWidget *parent) :
    ModuleGui(nameModule, IdModule, parent)
{
    modbusSwitchOutState = false;

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
   // connect(settingsButton, SIGNAL(clicked()), this, SLOT(settingsButtonClick()));

    adcDataLable = new QLabel(this);
    adcDataLable->move(50, 125);
    adcDataLable->resize(30, 25);
    adcDataLable->setAlignment(Qt::AlignRight);
    adcDataLable->setText("0");
    adcDataLable->show();

    this->resize(100, 150);
}

/*
bool ModbusSwitchGui::getState()
{
    return eSwitchOutState;
}

void ModbusSwitchGui::on()
{
    int regAddr = 0;
    int data = 1;

    writeReg(regAddr, data);
}

void ModbusSwitchGui::off()
{
    int regAddr = 0;
    int data = 0;

    writeReg(regAddr, data);
}
*/
void ModbusSwitchGui::mainButtonClick(void)
{
    if (modbusSwitchOutState) {
        modbusSwitchOutState = false;
    }
    else {
        modbusSwitchOutState = true;
    }

    changeButtonIcon();
/*
    if (eSwitchOutState) {
        on();
    }
    else {
        off();
    }
    */
}

void ModbusSwitchGui::changeButtonIcon(void)
{
    if (modbusSwitchOutState) {
        mainButton->setIcon(QIcon(":/img/lampOn.png"));
    }
    else {
        mainButton->setIcon(QIcon(":/img/lampOff.png"));
    }
}
