#include "modbusregister.h"

ModbusRegister::ModbusRegister()
{
    textType_ = false;
    type_ = reservType;
}

void ModbusRegister::setTextType()
{
    textType_ = true;
}

bool ModbusRegister::isTextType()
{
    return textType_;
}

int ModbusRegister::getType(void)
{
    return type_;
}

void ModbusRegister::setType(int type)
{
    type_ = type;
    if (type_ == textType) {
        setTextType();
    }
}

void ModbusRegister::addTextVal(int val, QString text)
{
    stringText_.append(text);
    stringVal_.append(val);
}

quint16 ModbusRegister::getData()
{
    if (isTextType()) {
        return stringVal_.indexOf(data_);
    }
    else {
        return data_;
    }
}

quint16 ModbusRegister::getData(int index)
{
    return quint16(stringVal_[index]);
}

void ModbusRegister::setData(int data)
{
    if (isTextType()) {
        data_ = stringVal_[data];
    }
    else {
        data_ = quint16(data);
    }
}
