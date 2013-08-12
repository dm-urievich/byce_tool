#include "module.h"

Module::Module(QObject *parent) : QObject(parent)
{
}

void Module::settings(void)
{

    qDebug() << "i'm virtual in base class";
}
