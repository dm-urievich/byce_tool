#ifndef BYCETIMER_H
#define BYCETIMER_H

#include "software.h"

#include <QTimer>
#include <QSpinBox>
#include <QPushButton>
#include <QString>
#include <QLabel>

class ByceTimer : public Software
{
    Q_OBJECT

public:
    ByceTimer(QWidget *parent = 0, QString name = "ByceTimer");

    QLabel *nameModule;
    QTimer* mainTimer;
    QPushButton* buttonStart;
    QPushButton* buttonStop;
    QSpinBox* timeBox;

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
