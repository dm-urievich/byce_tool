#ifndef BYCETIMER_H
#define BYCETIMER_H

#include "modulegui.h"

#include <QTimer>
#include <QSpinBox>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QTextStream>

class ByceTimer : public ModuleGui
{
    Q_OBJECT

public:
    ByceTimer(QString nameModule = "ByceTimer", int IdModule = 1, QWidget *parent = 0);

    QTimer* mainTimer;
    void parseXml(QDomElement &domElement);
    void generateXml(QTextStream &out);
    bool isEvent();
    void socket(QString socket, QString dataSocket);
    QStringList getListEvents();
    QStringList getListSockets();

public slots:
    void startTimerButton(void);
    void stopTimerButton(void);

signals:
    void byceTimeOut(void);

private:
    int time_;
    int timeVal_;
    bool timeOutEvetn_;

    QLabel* nameModuleLabel;
    QPushButton* buttonStart;
    QPushButton* buttonStop;
    QSpinBox* timeBox;


private slots:
    void mainTimerEvent(void);

};

#endif // BYCETIMER_H
