#include "hardware.h"
#include "hardwaresettingsdialog.h"

Hardware::Hardware(QWidget *parent, QString n) :
      Module(parent),
      name(n)
{
    enableReadCheck = new QCheckBox(parent);
    enableReadCheck->setChecked(true);

    //mbPort_ = 0;
}

modbus_t* Hardware::mbPort_ = 0;

void Hardware::setMbPort(modbus_t *port)
{
    mbPort_ = port;
}

void Hardware::setMbAddr(int addr)
{
    mbAddr_ = addr;
}

int Hardware::getMbAddr(void)
{
    return mbAddr_;
}

// чтение одного регистра
quint16 Hardware::readReg(int regAddr)
{
    quint16 data;

    readRegisters(regAddr, 1, &data);

    return data;
}

void Hardware::readReg(ModbusRegister &reg)
{
    readRegisters(reg.addr, 1, &reg.data_);
}

// чтение группы регистров
void Hardware::readRegisters(int regAddr, int cont, quint16 *data)
{
    if (mbPort_ != 0 && enableReadCheck->isChecked()) {
        modbus_set_slave(mbPort_, mbAddr_);
        modbus_read_registers(mbPort_, regAddr, cont, data);
    }
    else {
        for (int i = 0; i < cont; i++) {
            data[i] = 0;
        }
    }
}

// запись одного регистра
void Hardware::writeReg(int regAddr, quint16 data)
{
    if (mbPort_ != 0 && enableReadCheck->isChecked()) {
        modbus_set_slave(mbPort_, mbAddr_);
        modbus_write_register(mbPort_, regAddr, data);
    }
}

void Hardware::writeReg(ModbusRegister &reg)
{
    if (mbPort_ != 0 && enableReadCheck->isChecked()) {
        modbus_set_slave(mbPort_, mbAddr_);
        modbus_write_register(mbPort_, reg.addr, reg.data_);
    }
}

void Hardware::settingsButtonClick(void)
{
    HardwareSettingsDialog settingsWindow(0, "eSwitch.h", this);
}

void Hardware::generateXml(QFile* file)
{
    QTextStream out(file);

    QDomDocument hardware;
    QDomElement root = hardware.createElement("hardware");
    QDomElement addr = hardware.createElement("mbAddr");
    QDomElement nameDev = hardware.createElement("name");
    QDomText nameModule = hardware.createTextNode(name);
    QDomText addrModule = hardware.createTextNode(QString::number(mbAddr_));

    hardware.appendChild(root);
    root.appendChild(addr);
    root.appendChild(nameDev);
    addr.appendChild(addrModule);
    nameDev.appendChild(nameModule);

    hardware.save(out, 4);
}


