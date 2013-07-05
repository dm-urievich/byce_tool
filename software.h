#ifndef SOFTWARE_H
#define SOFTWARE_H

#include "module.h"

class Software : public Module
{
    Q_OBJECT

public:
    Software(QWidget *parent = 0);

    void settings(void);
};

#endif // SOFTWARE_H
