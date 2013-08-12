#include "eswitch.h"

eSwitch::eSwitch(QObject *parent, QString name, int addr) : Hardware(parent, name)
{

    mbAddr_ = addr;

    eSwitchOutState = false;
    dInState = false;
    adcData = 0;
    raiseEvent_ = false;
    fallEvent_ = false;
    adcEvent_ = false;
    adcHysteresis = 5;
}

bool eSwitch::refresh(void)
{
    bool prevState = dInState;
    int regAddr = 0;
    quint16 data[6];

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

    if (dInState && !prevState) { // передний фронт
        emit dInRaise();
        raiseEvent_ = true;
    }

    // заполняем данные с АЦП
    //if ((data[5] + adcHysteresis >= adcData) || (data[5] - adcHysteresis <= adcData)) {
    if (data[5] >= adcData + adcHysteresis) {
        adcEvent_ = true;
        adcData = data[5] - (data[5] % adcHysteresis);
    }
    else
        if (data[5] <= adcData - adcHysteresis) {
            adcEvent_ = true;
            adcData = data[5] - (data[5] % adcHysteresis);
        }
    //adcData = data[5];

    return true;
}

bool eSwitch::isEvent()
{
    if (raiseEvent_ || fallEvent_ || adcEvent_) {
        return true;
    }
    else
        return false;
}

void eSwitch::generateXml(QTextStream& out)
{
    out << "<modbusSwitch id=\"" << idModule <<"\">\n";
    out << "<idModule>"     << idModule         << "</idModule>\n";
    out << "<name>"         << name             << "</name>\n";
    out << "<mbAddr>"       << mbAddr_          << "</mbAddr>\n";
    out << "<outState>"     << eSwitchOutState  << "</outState>\n";
    out << "<dinState>"     << dInState         << "</dinState>\n";
    out << "<adcData>"      << adcData          << "</adcData>\n";
    out << "<raiseEvent>"   << raiseEvent_      << "</raiseEvent>\n";
    out << "<fallEvent>"    << fallEvent_       << "</fallEvent>\n";
    out << "</modbusSwitch>\n";

    raiseEvent_ = false;
    fallEvent_ = false;
    adcEvent_ = false;
}
