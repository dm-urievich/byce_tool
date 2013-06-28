#include "windowoptions.h"
#include "ui_windowoptions.h"

#include <QtDebug>
#include <QSettings>
#include <QtAddOnSerialPort/serialport.h>
#include <QtAddOnSerialPort/serialportinfo.h>

windowOptions::windowOptions(QWidget *parent, QSettings *settings) :
    QDialog(parent),
    ui(new Ui::windowOptions),
    settings(settings)
{
    ui->setupUi(this);

    connect(ui->buttonCancel, SIGNAL(clicked()), this, SLOT(buttonCancelClick()));
    connect(ui->buttonApply, SIGNAL(clicked()), this, SLOT(buttonApplayOptionsClick()));
}

windowOptions::~windowOptions()
{
    delete ui;
}

void windowOptions::buttonCancelClick()
{

    qDebug() << "quit Option Window";
    this->close();
}

void windowOptions::buttonApplayOptionsClick()
{
    settings->setValue("portName", ui->comboBoxPortName->currentText());
    settings->setValue("baud", ui->comboBoxBaud->currentText().toInt());
    settings->setValue("parity", ui->comboBoxParity->currentIndex());
    settings->setValue("stopBits", ui->comboBoxStopBits->currentText().toInt());

    qDebug() << "apply Option";
    this->close();
}

void windowOptions::fillPortsInfo()
{
    ui->comboBoxPortName->clear();
    foreach (const SerialPortInfo &info, SerialPortInfo::availablePorts()) {
        QStringList list;
        list << info.portName() << info.description()
             << info.manufacturer() << info.systemLocation()
             << info.vendorIdentifier() << info.productIdentifier();

        ui->comboBoxPortName->addItem(list.first(), list);
    }
}

void windowOptions::showEvent(QShowEvent * event)
{
    // поиск портов
    this->fillPortsInfo();

    ui->comboBoxPortName->setCurrentIndex( ui->comboBoxPortName->findText( settings->value( "portName" ).toString() ) );
    ui->comboBoxBaud->setCurrentIndex( ui->comboBoxBaud->findText( settings->value( "baud" ).toString() ) );
    ui->comboBoxParity->setCurrentIndex( settings->value( "parity" ).toInt());
    ui->comboBoxStopBits->setCurrentIndex( ui->comboBoxStopBits->findText( settings->value( "stopBits" ).toString() ) );

}
