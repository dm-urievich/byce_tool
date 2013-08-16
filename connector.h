#ifndef CONNECTOR_H
#define CONNECTOR_H


#include <QDomElement>
#include <QTextStream>

/*
 * Специальный класс для соединения
 * событий и сокетов модулей
 * все генериться через XML
 */

class Connector
{
public:
    Connector();

    bool isEvent(void);

    void parseXml(QDomElement& domElement);
    void generateXml(QTextStream& out);
};

#endif // CONNECTOR_H
