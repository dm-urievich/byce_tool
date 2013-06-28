#ifndef ESWITCH_H
#define ESWITCH_H

#include "modbus.h"
#include <stddef.h>
#include <QString>
#include <QMessageBox>

// конкретный класс выключателя
// в дальнейшем придумать базовый класс и наследовать выключатель от него
// пока так, буду понимать что мне нужно и как должно работать

class eSwitch
{
public:
    eSwitch();

    void settings(void);
    quint16 getState(void);
    void setState(int state);
    void refresh(void);

    void setMbAddr(int addr);
    int getMbAddr();
    void on(void);
    void off(void);

    void setMbPort(modbus_t *mbPort);

private:
    int mbAddr;
    modbus_t *mbPort;

};

#endif // ESWITCH_H
