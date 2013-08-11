#include "eswitch.h"

eSwitch::eSwitch(QObject *parent, QString name, int addr) : Hardware(parent, name)
{

    mbAddr_ = addr;

    eSwitchOutState = false;
    dInState = false;
    adcData = 0;
    raiseEvent_ = false;
    fallEvent_ = false;
}

bool eSwitch::refresh(void)
{
    bool prevState = dInState;
    int regAddr = 0;
    quint16 data[6];

    raiseEvent_ = false;
    fallEvent_ = false;

    //data = readReg(regAddr);
    if (readRegisters(regAddr, 6, data) == -1) {
        return false;
    }

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

    if (!dInState && prevState) {     // задний фронт
        emit dInFall();
        fallEvent_ = true;
    }
    else
        if (dInState && !prevState) { // передний фронт
            emit dInRaise();
            raiseEvent_ = true;
        }

    // заполняем данные с АЦП
    adcData = data[5];

    return true;
}

bool eSwitch::isEvent()
{
    if (raiseEvent_ || fallEvent_) {
        return true;
    }
    else
        return false;
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
