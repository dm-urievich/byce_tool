#ifndef MODBUSSWITCHGUI_H
#define MODBUSSWITCHGUI_H

#include "modulegui.h"
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>

class ModbusSwitchGui : public ModuleGui
{
    Q_OBJECT
public:
    explicit ModbusSwitchGui(QString nameModule, int IdModule, QWidget *parent = 0);
    
signals:
    
public slots:
    
private:
    QLabel* nameDev;
    QPushButton* mainButton;
    QRadioButton* dInStateButton;
    QPushButton* settingsButton;
    QLabel* adcDataLable;

    bool modbusSwitchOutState;

    void changeButtonIcon();

private slots:
   // void settingsButtonClick();
    void mainButtonClick();
};

#endif // MODBUSSWITCHGUI_H
