#ifndef HARDWARE_H
#define HARDWARE_H

#include <QPushButton>
#include <QCheckBox>

#include "module.h"
#include "modbus.h"
#include "modbusregister.h"
//#include "hardwaresettingsdialog.h"

/*
 * базовый класс аппаратного девайса
 * уже добавлено понятие модбаса, адреса устройства
 * методы для работы с устройством
 * все аппаратные штуки должны наследоваться от него
 */

class Hardware : public Module
{
    Q_OBJECT

public:
    Hardware(QWidget *parent = 0, QString n = "HardwareModule");

    QString name;
    QCheckBox* enableReadCheck;
    static void setMbPort(modbus_t *port);

    void setMbAddr(int addr);
    int getMbAddr();
    quint16 readReg(int regAddr);
    void readReg(ModbusRegister& reg);
    void writeReg(int regAddr, quint16 data);
    void writeReg(ModbusRegister& reg);

protected:
    static modbus_t *mbPort_;
    void readRegisters(int regAddr, int cont, quint16* data);

    int mbAddr_;
    QPushButton *settingsButton;

protected slots:
    void settingsButtonClick(void);
private:




};

#endif // HARDWARE_H
