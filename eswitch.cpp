#include "eswitch.h"

eSwitch::eSwitch(const QString &name, int addr) : name(name)
{

    this->mbAddr = addr;
}

quint16 eSwitch::getState()
{
    int regAddr = 0;
    quint16 data;

    modbus_set_slave(this->mbPort, this->mbAddr);
    modbus_read_registers(this->mbPort, regAddr, 1, &data);

    return data;
}

void eSwitch::setMbPort(modbus_t *mbPort)
{
    mbPort = mbPort;
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
