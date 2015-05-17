#include "motiondetect.h"


MotionDetect::MotionDetect(QString nameModule, int IdModule, QWidget *parent) :
    ModuleGui(nameModule, IdModule, parent)
{
    onSocket_ = false;
    offSocket_ = false;

    nameDev = new QLabel(this);
    nameDev->setText(name);
    nameDev->show();

    mainButton = new QPushButton(this);
    mainButton->move(0, 25);
    mainButton->resize(100, 100);
    changeButtonIcon();
    mainButton->setIconSize(QSize(100, 100));
    mainButton->show();

    this->resize(100, 150);
}


void MotionDetect::changeButtonIcon(void)
{
    if (dinState_) {
        mainButton->setIcon(QIcon(":/img/motionOn.png"));
    }
    else {
        mainButton->setIcon(QIcon(":/img/motionOff.png"));
    }
}

void MotionDetect::parseXml(QDomElement &domElement)
{
    QString tagName;

    QDomNode n = domElement.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // пробуем преобразовать узел в элемент.
        if(!e.isNull()) {
            tagName = e.tagName(); // узел действительно является элементом.
            if (tagName == "dinState") {
                dinState_ = (e.text().toInt()) ? true : false;
            }
            if (tagName == "raiseEvent") {
                if (e.text().toInt())
                    emit eventForGui(idModule, tagName, e.text());
            }
            if (tagName == "fallEvent") {
                if (e.text().toInt())
                    emit eventForGui(idModule, tagName, e.text());
            }

        }
        n = n.nextSibling();
    }
    refresh();
}

void MotionDetect::refresh()
{
    changeButtonIcon();
}

void MotionDetect::generateXml(QTextStream &out)
{
    out << "<modbusSwitchGui id=\"" << idModule <<"\">\n";
    out << "<idModule>"     << idModule         << "</idModule>\n";
    out << "<name>"         << name             << "</name>\n";
    out << "<onSocket>"     << onSocket_        << "</onSocket>\n";
    out << "<offSocket>"    << offSocket_       << "</offSocket>\n";
    out << "</modbusSwitchGui>\n";

    onSocket_ = false;
    offSocket_ = false;
}

bool MotionDetect::isEvent()
{
    return (onSocket_ || offSocket_);
}

void MotionDetect::socket(QString socket, QString dataSocket)
{
    if (socket == "onSocket") {
        if (dataSocket.toInt()) {
            onSocket_ = true;
        }
    }
    if (socket == "offSocket") {
        if (dataSocket.toInt()) {
            offSocket_ = true;
        }
    }

    refresh();
}

QStringList MotionDetect::getListEvents()
{
    QStringList list;
    list.append("raiseEvent");
    list.append("fallEvent");

    return list;
}

QStringList MotionDetect::getListSockets()
{
    QStringList list;
    //list.append("onSocket");
    //list.append("offSocket");

    return list;
}
