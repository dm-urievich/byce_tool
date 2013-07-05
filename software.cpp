#include "software.h"

Software::Software(QWidget *parent) : Module(parent)
{

}


void Software::settings()
{
    qDebug() << "i'm virtual in next class";
}
