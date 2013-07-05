#ifndef HARDWARE_H
#define HARDWARE_H

#include "module.h"

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
    Hardware(QWidget *parent = 0);
};

#endif // HARDWARE_H
