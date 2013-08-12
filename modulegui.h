#ifndef MODULEGUI_H
#define MODULEGUI_H

#include <QWidget>
#include <QString>
#include <QDomElement>

class ModuleGui : public QWidget
{
    Q_OBJECT
public:
    explicit ModuleGui(QString nameModule, int IdModule, QWidget *parent = 0);
    QString name;
    int idModule;

    virtual void parseXml(QDomElement& domElement);
    virtual void refresh(void);

signals:
    
public slots:
    
};

#endif // MODULEGUI_H
