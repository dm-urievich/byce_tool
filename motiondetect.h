#ifndef MOTIONDETECT_H
#define MOTIONDETECT_H

#include "modulegui.h"

#include <QLabel>
#include <QPushButton>
#include <QRadioButton>
#include <QDomElement>
#include <QDebug>
#include <QString>
#include <QTextStream>
#include <QStringList>

class MotionDetect : public ModuleGui
{
    Q_OBJECT
public:
    explicit MotionDetect(QString nameModule, int IdModule, QWidget *parent = 0);

    void parseXml(QDomElement &domElement);
    void refresh(void);
    void generateXml(QTextStream& out);
    bool isEvent(void);
    void socket(QString socket, QString dataSocket);
    QStringList getListEvents();
    QStringList getListSockets();

signals:

public slots:

private:
    QLabel* nameDev;
    QPushButton* mainButton;

    bool dinState_;

    bool onSocket_;
    bool offSocket_;

    void changeButtonIcon();

private slots:
    //void mainButtonClick();
};

#endif // MOTIONDETECT_H
