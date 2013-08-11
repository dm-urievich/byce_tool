#ifndef MODULEGUI_H
#define MODULEGUI_H

#include <QWidget>
#include <QString>

class ModuleGui : public QWidget
{
    Q_OBJECT
public:
    explicit ModuleGui(QString nameModule, int IdModule, QWidget *parent = 0);
    QString name;
    int idModule;

signals:
    
public slots:
    
};

#endif // MODULEGUI_H
