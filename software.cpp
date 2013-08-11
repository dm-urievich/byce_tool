#include "software.h"

Software::Software(QObject *parent, QString n) :
    Module(parent),
    name(n)
{

}


void Software::settings()
{
    qDebug() << "I am Software module";
}
