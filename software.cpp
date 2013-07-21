#include "software.h"

Software::Software(QWidget *parent, QString n) :
    Module(parent),
    name(n)
{

}


void Software::settings()
{
    qDebug() << "i'm virtual in next class";
}
