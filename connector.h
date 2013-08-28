#ifndef CONNECTOR_H
#define CONNECTOR_H


#include <QDomElement>
#include <QTextStream>
#include <QString>

#include <modulegui.h>

/*
 * Специальный класс для соединения
 * событий и сокетов модулей
 * все генериться через XML
 */

class Connector : public ModuleGui
{
public:
    Connector(QString nameModule, int IdModule, QWidget *parent);


    bool isEvent(void);
    void addConnection(int idSender, QString event, int idReceiver, QString socket);
    void parseXml(QDomElement& domElement);
    void generateXml(QTextStream& out);
    void socket(QString socket, QString dataSocket);

private:
    int idReceiver_;
    QString event_;
    QString socket_;
    QString dataEvent_;
    bool eventModule_;
};

#endif // CONNECTOR_H
