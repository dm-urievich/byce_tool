#include "module.h"

Module::Module(QWidget *parent) : QWidget(parent)
{

    this->show();
}

void Module::settings()
{

    qDebug() << "i'm virtual in base class";
}

void Module::paintEvent(QPaintEvent *event)
{
//    QPainter paint(this);

    //paint.setPen(palette().foreground().color());
//    paint.drawLine(0, 0, 10, 10);

}
