#ifndef MODULE_H
#define MODULE_H

#include <QDebug>
#include <QPainter>
#include <QString>
#include <QDomElement>

/*
 * базовый клас для всех элементов системы
 * реализует некоторое графическое представление модуля
 * содержит простые методы для настройки, но больше относиться к ПО для ПК
 */

class Module : public QObject
{
    Q_OBJECT

public:
    Module(QObject *parent = 0);

    QString name;
    int idModule;   // уникальный идентификатор, модули различаются по нему

    virtual void settings(void);
    virtual void generateXml(QTextStream &out) = 0;
    virtual void parseXml(QDomElement &domElement) = 0;

};

#endif // MODULE_H
