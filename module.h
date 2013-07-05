#ifndef MODULE_H
#define MODULE_H

#include <QWidget>
#include <QDebug>
#include <QPainter>

/*
 * базовый клас для всех элементов системы
 * реализует некоторое графическое представление модуля
 * содержит простые методы для настройки, но больше относиться к ПО для ПК
 */

class Module : public QWidget
{
    Q_OBJECT

public:
    Module(QWidget *parent = 0);

    void paintEvent(QPaintEvent *);
    void settings();
};

#endif // MODULE_H
