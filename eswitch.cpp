#include "eswitch.h"

eSwitch::eSwitch()
{

    mbAddr = 0;
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
    this->mbPort = mbPort;
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

    if (this->mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = this->mbAddr;
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(this->mbPort, addr);
    modbus_write_register(this->mbPort, regAddr, data);
}

void eSwitch::off()
{
    int addr;
    int regAddr = 0;
    int data = 0;

    if (this->mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = this->mbAddr;
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(this->mbPort, addr);
    modbus_write_register(this->mbPort, regAddr, data);
}
