#ifndef MODULEGUI_H
#define MODULEGUI_H

#include <QWidget>
#include <QString>
#include <QDomElement>
#include <QTextStream>

class ModuleGui : public QWidget
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

signals:
    void event(void);
    
public slots:
    
};

#endif // MODULEGUI_H
