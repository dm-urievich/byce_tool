#ifndef MODBUSREGISTER_H
#define MODBUSREGISTER_H

#include <QString>
#include <QStringList>
#include <QVector>

class ModbusRegister
{
public:
    ModbusRegister();

    enum {intType, hexType, textType, reservType};

    QString name;
    int getType(void);
    void setType(int type);
    bool isTextType(void);
    void setTextType(void);
    void addTextVal(int val, QString text);
    //quint16 data;
    quint16 getData();
    quint16 getData(int);
    void setData(int);
    quint16 maxLim; // верхний предел
    quint16 minLim; // нижний предел
    int addr;

    QStringList stringText_;
    quint16 data_;
private:
    int type_;
    bool textType_;
    //QStringList stringText_;
    QVector<int> stringVal_;

};

#endif // MODBUSREGISTER_H
