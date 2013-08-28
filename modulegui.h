#ifndef MODULEGUI_H
#define MODULEGUI_H

#include <QWidget>
#include <QString>
#include <QDomElement>
#include <QTextStream>

#include <module.h>

class ModuleGui : public QWidget, public Module
{
    Q_OBJECT
public:
    explicit ModuleGui(QString nameModule, int IdModule, QWidget *parent = 0);
    QString name;
    int idModule;

    virtual void parseXml(QDomElement& domElement);
    virtual void generateXml(QTextStream& out);
    virtual void refresh(void);
    virtual bool isEvent(void);
    virtual void socket(QString socket, QString dataSocket) = 0;
    virtual QStringList getListEvents();
    virtual QStringList getListSockets();


signals:
    void event(void);   // событие для генерации XML для аппаратного модуля
    void eventForGui(int idModule, QString eventName, QString eventData);
    
public slots:
    
};

#endif // MODULEGUI_H
