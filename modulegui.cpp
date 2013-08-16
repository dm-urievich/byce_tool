#include "modulegui.h"

ModuleGui::ModuleGui(QString nameModule, int IdModule, QWidget *parent) :
    QWidget(parent),
    name(nameModule)
{
    idModule = IdModule;
    this->show();
}

void ModuleGui::parseXml(QDomElement &domElement)
{

}

void ModuleGui::refresh()
{

}

void ModuleGui::generateXml(QTextStream &out)
{

}

bool ModuleGui::isEvent()
{
    return false;
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
