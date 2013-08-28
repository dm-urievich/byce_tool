#ifndef SOFTWARE_H
#define SOFTWARE_H

#include <QObject>
#include "module.h"

#include <QString>

class Software : public QObject, public Module
{
    Q_OBJECT

public:
    Software(QObject *parent = 0, QString n = "SoftwareModule");

    QString name;

    void settings(void);
    virtual void generateXml(QTextStream &out) = 0;
    virtual void parseXml(QDomElement &domElement) = 0;
};

#endif // SOFTWARE_H
