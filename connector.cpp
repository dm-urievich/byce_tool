#include "connector.h"

Connector::Connector(QString nameModule, int IdModule, QWidget *parent) :
    ModuleGui(nameModule, IdModule, parent)
{
}

bool Connector::isEvent()
{
    return false;
}

void Connector::addConnection(int idSender, QString event, int idReceiver, QString socket)
{
    idModule = idSender;
    idReceiver_ = idReceiver;
    event_ = event;
    socket_ = socket;
}

void Connector::generateXml(QTextStream &out)
{
    out << "<connector id=\""   << idReceiver_    <<"\">\n";
    out << "<idModule>"         << idModule       << "</idModule>\n";
    out << "<" << socket_ << ">" << dataEvent_    << "</" << socket_ << ">\n";
    out << "</connector>\n";

    eventModule_ = false;
}

void Connector::parseXml(QDomElement &domElement)
{
    return;
    /*
    QString tagName;

    QDomNode n = domElement.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // пробуем преобразовать узел в элемент.
        if(!e.isNull()) {
            tagName = e.tagName(); // узел действительно является элементом.
            if (tagName == event_) {
                dataEvent_ = e.text();
                eventModule_ = true;
            }
        }
        n = n.nextSibling();
    }
    */
}

void Connector::socket(QString socket, QString dataSocket)
{
    if (event_ == socket) {
        emit eventForGui(idReceiver_, socket_, dataSocket);
    }
}
