#ifndef ESWITCH_H
#define ESWITCH_H

#include "modbus.h"
#include <stddef.h>
#include <QString>
#include <QMessageBox>

// конкретный класс выключателя
// в дальнейшем придумать базовый класс и наследовать выключатель от него
// пока так, буду понимать что мне нужно и как должно работать

/*
 * как должне выглядеть базовый класс
 * реализованны функции чтетия/записи одного регистра и набора регистров
 * инициализация указателя на порт происходит единожды, указатель общий для всех потомков (статик)
 * имя и адрес девайса инициализируется в конструкторе
 * общие методы и свойства для всех классов (виртуальные в базовом:
 *  имя, адрес
 *  рефреш (там генерятся все сигналы)
 *  сеттингс (конструктор окна для настройки девайса)
 *  установка и считывание всех полей
 *
 * все проверки наличия открытого порта и т.д. в базовом классе
 *
 */
class eSwitch
{
public:
    eSwitch(const QString &name, int addr);
    QString name;

    static void setMbPort(modbus_t *mbPort);

    void settings(void);
    quint16 getState(void);
    void setState(int state);
    void refresh(void);

    void setMbAddr(int addr);
    int getMbAddr();
    void on(void);
    void off(void);

private:
    int mbAddr;
    modbus_t *mbPort;

};

#endif // ESWITCH_H
