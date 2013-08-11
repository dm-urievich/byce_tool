#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "module.h"

#include <QString>

class Software : public Module
{
    Q_OBJECT

public:
    Software(QObject *parent = 0, QString n = "SoftwareModule");

    QString name;

    void settings(void);
};

#endif // SOFTWARE_H
