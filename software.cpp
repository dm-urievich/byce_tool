#include "software.h"

Software::Software(QObject *parent, QString n) :
    QObject(parent),
    Module(),
    name(n)
{

}


void Software::settings()
{
    qDebug() << "I am Software module";
}
