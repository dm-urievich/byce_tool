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
    adcData = 0;
    raiseEvent_ = false;
    fallEvent_ = false;

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
    quint16 data[6];

    raiseEvent_ = false;
    fallEvent_ = false;

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

    if (!dInState && prevState) {     // задний фронт
        emit dInFall();
        fallEvent_ = true;
    }
    else
        if (dInState && !prevState) { // передний фронт
            emit dInRaise();
            raiseEvent_ = true;
        }

    changeButtonIcon();

    // заполняем данные с АЦП
    adcData = data[5];
    adcDataLable->setText(QString::number(adcData));

    if (raiseEvent_ || fallEvent_) {
        QFile file("hardware.xml");
        if (file.open(QIODevice::WriteOnly)) {
            generateXml(&file);
            file.close();
        }
    }
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

void eSwitch::generateXml(QFile *file)
{
    QTextStream out(file);

    QDomDocument hardware;
    QDomNode xmlNode = hardware.createProcessingInstruction("xml", "version=\"1.0\" encoding=\"UTF-8\"");
    hardware.insertBefore(xmlNode, hardware.firstChild());

    QDomElement root = hardware.createElement("hardware");
    QDomElement addrElement = hardware.createElement("mbAddr");
    QDomElement nameElement = hardware.createElement("name");
    QDomElement mbSwitch = hardware.createElement("ModbusSwitch");
    QDomElement stateElement = hardware.createElement("outState");
    QDomElement dinElement = hardware.createElement("dinState");
    QDomElement adcElement = hardware.createElement("adcData");
    QDomElement eventElement = hardware.createElement("event");

    QDomText nameDomText = hardware.createTextNode(name);
    QDomText addrDomText = hardware.createTextNode(QString::number(mbAddr_));
    QDomText outDomText = hardware.createTextNode(QString::number(eSwitchOutState));
    QDomText dinDomText = hardware.createTextNode(QString::number(dInState));
    QDomText adcDomText = hardware.createTextNode(QString::number(adcData));

    QDomText eventDomText = hardware.createTextNode("none");
    if (raiseEvent_) {
         eventDomText = hardware.createTextNode("raiseEvent");
    }
    else
        if (fallEvent_) {
            eventDomText = hardware.createTextNode("fallEvent");
        }

    hardware.appendChild(root);
    root.appendChild(addrElement);
    root.appendChild(nameElement);
    addrElement.appendChild(addrDomText);
    nameElement.appendChild(nameDomText);

    root.appendChild(mbSwitch);
    mbSwitch.appendChild(stateElement);
    stateElement.appendChild(outDomText);
    mbSwitch.appendChild(dinElement);
    dinElement.appendChild(dinDomText);
    mbSwitch.appendChild(adcElement);
    adcElement.appendChild(adcDomText);
    mbSwitch.appendChild(eventElement);
    eventElement.appendChild(eventDomText);

    hardware.save(out, 4);
}
