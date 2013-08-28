#include "modulegui.h"

ModuleGui::ModuleGui(QString nameModule, int IdModule, QWidget *parent) :
    QWidget(parent),
    name(nameModule)
{
    idModule = IdModule;
    this->show();
}

void ModuleGui::parseXml(QDomElement &domElement)
{

}

void ModuleGui::refresh()
{

}

void ModuleGui::generateXml(QTextStream &out)
{

}

bool ModuleGui::isEvent()
{
    return false;
}

QStringList ModuleGui::getListEvents()
{
    return QStringList();
}

QStringList ModuleGui::getListSockets()
{
    return QStringList();
}

