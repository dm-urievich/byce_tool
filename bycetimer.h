#ifndef BYCETIMER_H
#define BYCETIMER_H

#include "software.h"

#include <QTimer>
#include <QSpinBox>
#include <QPushButton>
#include <QString>
#include <QLabel>
#include <QTextStream>

class ByceTimer : public Software
{
    Q_OBJECT

public:
    ByceTimer(QObject *parent = 0, QString name = "ByceTimer");

    QTimer* mainTimer;
    void parseXml(QDomElement &domElement);
    void generateXml(QTextStream &out);

public slots:
    void startTimerButton(void);
    void stopTimerButton(void);

signals:
    void byceTimeOut(void);

private:
    int time_;
    int timeVal_;

private slots:
    void mainTimerEvent(void);

};

#endif // BYCETIMER_H
