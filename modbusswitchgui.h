#ifndef MODBUSSWITCHGUI_H
#define MODBUSSWITCHGUI_H

#include "modulegui.h"
#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QDomElement>
#include <QDebug>
#include <QString>

class ModbusSwitchGui : public ModuleGui
{
    Q_OBJECT
public:
    explicit ModbusSwitchGui(QString nameModule, int IdModule, QWidget *parent = 0);
    
    void parseXml(QDomElement &domElement);
    void refresh(void);

signals:
    
public slots:
    
private:
    QLabel* nameDev;
    QPushButton* mainButton;
    QRadioButton* dInStateButton;
    QPushButton* settingsButton;
    QLabel* adcDataLable;

    bool modbusSwitchOutState;
    bool dinState_;
    int adcData_;

    void changeButtonIcon();

private slots:
   // void settingsButtonClick();
    void mainButtonClick();
};

#endif // MODBUSSWITCHGUI_H
