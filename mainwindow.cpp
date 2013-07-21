#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtDebug>

#include "modbus.h"

#include <QtAddOnSerialPort/serialport.h>
#include <QtAddOnSerialPort/serialportinfo.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    eSwitchWindowControl = new eSwitchWindow;

    portSettings = new QSettings("BYCE_tool.ini", QSettings::IniFormat);
    windowoption = new windowOptions(this, portSettings);

    mbReadRequestTimer = new QTimer;
    eSwitchOnTimer = new QTimer;

  //  hardwareVector = new QVector<eSwitch*>;
   // softwareVector = new QVector<Software*>;
    numModuls_ = 0;

    qDebug() << "Hello debug";

    this->mbPort = NULL;

    this->initbuttons();

    m_modbus=new ModbusAdapter(this);
    m_modbus->regModel->setBase(EUtils::Bin);

    m_busMonitor = new BusMonitor(this, m_modbus->rawModel);
    connect(ui->buttonMonitor,SIGNAL(clicked()),this,SLOT(showBusMonitor()));

    connect(ui->spinBoxPeriod, SIGNAL(valueChanged(int)), this, SLOT(mbTimerSetTimeInterval(int)));

    // добавляем кнопочки в панель инструментов
    ui->mainToolBar->addWidget(ui->widget);

    // сигналы lineEdit на проверку валидности
    connect(ui->lineEditRegAddr1, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditRegAddr2, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditRegAddr3, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditRegAddr4, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditRegAddr5, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditAddrRegToWrite, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditDataRegToWrite, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->lineEditDeviceAddrRegs, SIGNAL(editingFinished()), this, SLOT(lineEditChenged()));
    connect(ui->radioButtonHex, SIGNAL(clicked()), this, SLOT(lineEditChenged()));
    connect(ui->radioButtonInt, SIGNAL(clicked()), this, SLOT(lineEditChenged()));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::initbuttons()
{
    connect(ui->buttonSettings, SIGNAL(clicked()), this, SLOT(showWindowOption()));
    connect(ui->buttonOpenClose, SIGNAL(clicked()), this, SLOT(buttonOpenCloseClick()));
    connect(ui->buttonReadRequest, SIGNAL(clicked()), this, SLOT(readRequestButtonClick()));
    connect(mbReadRequestTimer, SIGNAL(timeout()), this, SLOT(readRequest()));

    // закладка чтения регистров
    connect(ui->pushButtonClearRegs, SIGNAL(clicked()), this, SLOT(registersClearRegisters()));
    connect(ui->pushButtonReadId, SIGNAL(clicked()), this, SLOT(registersReadDeviceId()));
    connect(ui->pushButtonReadRegs, SIGNAL(clicked()), this, SLOT(registersReadRegisters()));
    connect(ui->pushButtonWriteReg, SIGNAL(clicked()), this, SLOT(registersWriteRegister()));

    // закладка работы с переключателем
    connect(ui->pushButtonSwitchOn, SIGNAL(clicked()), this, SLOT(eswitchOn()));
    connect(ui->pushButtonSwitchOff, SIGNAL(clicked()), this, SLOT(eswitchOff()));
    connect(ui->pushButtonSwitcherWindow, SIGNAL(clicked()), eSwitchWindowControl, SLOT(show()));
    connect(eSwitchWindowControl, SIGNAL(switchOn()), this, SLOT(eswitchOn()));
    connect(eSwitchWindowControl, SIGNAL(switchOff()), this, SLOT(eswitchOff()));
    connect(ui->pushButtonStartOn, SIGNAL(clicked()), this, SLOT(eswitchStartOn()));
    connect(ui->pushButtonStopOn, SIGNAL(clicked()), this, SLOT(eswitchOff()));
    connect(ui->pushButtonIniteSwitchClass, SIGNAL(clicked()), this, SLOT(eSwitchClassInit()));
 //   connect(this->eSwitchOnTimer, SIGNAL(timeout()), this, SLOT(eswitchOff()));

    connect(ui->pushButtonAddTimer, SIGNAL(clicked()), this, SLOT(addTimerButtonClick()));
    connect(ui->pushButtonConfigureSignals, SIGNAL(clicked()), this, SLOT(confirureSignalsModules()));
    connect(ui->pushButtonStartScript, SIGNAL(clicked()), this, SLOT(tryScriptEngine()));
}

void MainWindow::showWindowOption()
{
    this->windowoption->open();
    qDebug() << "show Window Option";
}

void MainWindow::showBusMonitor()
{
    qDebug() << "show BusMonitor";
    this->m_busMonitor->show();
}

void MainWindow::buttonOpenCloseClick()
{
    QString portName;
    char parity = 'N';
    int baud = 115200;
    int dataBit = 8;
    int stopBit = 1;

    switch(this->portSettings->value("parity").toInt()) {
    case 0: parity = 'N';
        break;
    case 1: parity = 'O';
        break;
    case 2: parity = 'E';
    }

    portName = "/dev/" + this->portSettings->value("portName").toString();
    baud = this->portSettings->value("baud").toInt();
    stopBit = this->portSettings->value("stopBits").toInt();

    if (this->mbPort == NULL) {         // порт закрыт
        this->mbPort = modbus_new_rtu(portName.toAscii().constData(), baud, parity, dataBit, stopBit, 0);
        if ( modbus_connect(this->mbPort) == -1) {
        //if (this->mbPort == NULL) {
            this->mbPort = NULL;
            ui->statusBar->showMessage("mbPort not initialized");
        }
        else {
            ui->statusBar->showMessage("mbPort Open " + portName);
            ui->buttonOpenClose->setText(QString::fromLocal8Bit("Закрыть"));

            Hardware::setMbPort(this->mbPort);
        }
    }
    else {
        modbus_close(this->mbPort);
        modbus_free(this->mbPort);
        this->mbPort = NULL;
        ui->buttonOpenClose->setText(QString::fromLocal8Bit("Открыть"));
        ui->statusBar->showMessage("mbPort Close");

        Hardware::setMbPort(0);
    }
}

void MainWindow::readRequestButtonClick()
{
    if (mbPort == NULL) {
        ui->buttonReadRequest->setChecked(false);
        mbReadRequestTimer->stop();
        QMessageBox::information(NULL, "Connection failed", "Could not connect to serial port!");
        return;
    }

    if (mbReadRequestTimer->isActive()) {
        // выключаем таймер
        mbReadRequestTimer->stop();
        qDebug() << "stop timer";
        ui->buttonReadRequest->setChecked(false);
    }
    else {
        if (ui->checkBoxPeriodicaly->isChecked()) {
            // запускаем таймер, кнопку "зажимаем"
            mbReadRequestTimer->start(ui->spinBoxPeriod->value());
            //mbTimerSetTimeInterval(ui->spinBoxPeriod->value());

            qDebug() << "start timer";
            ui->buttonReadRequest->setChecked(true);
        }
        else {
            ui->buttonReadRequest->setChecked(false);
        }

        this->readRequest();
    }
}

void MainWindow::mbTimerSetTimeInterval(int time)
{
    mbReadRequestTimer->setInterval(time);
}

void MainWindow::readRequest()
{
    qDebug() << "read request";

    switch(ui->tabWidgetMain->currentIndex()) {
    case 0 : qDebug() << "read registers";
        readRegistersRequest();
        break;
    case 1 : qDebug() << "read WattMeter";
        readWattMeterRequest();
        break;
    case 2 : qDebug() << "read eSwitch";
        readeSwitchRequest();
        break;
    case 3 : qDebug() << "read eSwitch Class";

        break;
    default : qDebug() << "nothing to read";
        break;
    }
}

void MainWindow::readRegistersRequest()
{
//    registersReadDeviceId();
    registersReadRegisters();
}

void MainWindow::registersClearRegisters()
{
    ui->lineEditRegAddr1->clear();
    ui->lineEditRegAddr2->clear();
    ui->lineEditRegAddr3->clear();
    ui->lineEditRegAddr4->clear();
    ui->lineEditRegAddr5->clear();

    ui->lineEditRegData1->clear();
    ui->lineEditRegData2->clear();
    ui->lineEditRegData3->clear();
    ui->lineEditRegData4->clear();
    ui->lineEditRegData5->clear();
}

void MainWindow::registersReadDeviceId()
{
    QString name;
    quint8 rxBuf[256] = {0};
    int length = -1;
    int Id = 0;
    int status = 0;
    int addr;

    if (mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = registersGetSlaveAddr();
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(mbPort, addr);
    length = modbus_report_slave_id(mbPort, rxBuf);
    if (length != -1) {
        ui->lineEditDeviceId->clear();
        ui->lineEditDeviceName->clear();
        return;
    }

    Id = rxBuf[1];
    status = rxBuf[2];

    ui->lineEditDeviceId->setText(QString("%1").arg(Id));

    if (status == 0x00) {
        ui->lineEditRunStatus->setText("OFF");
    }
    else {
        ui->lineEditRunStatus->setText("ON");
    }

    name.append(rxBuf[3]);

    ui->lineEditDeviceName->setText(name);
}

void MainWindow::registersReadRegisters()
{
    int addr;
    int regAddr;
    quint16 data;
    QString tmpstr;

    if (mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = registersGetSlaveAddr();
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(mbPort, addr);

    if (!ui->lineEditRegAddr1->text().isEmpty()) {
        regAddr = getIntFromTexEditText(ui->lineEditRegAddr1->text());
        modbus_read_registers(mbPort, regAddr, 1, &data);
        tmpstr.setNum(data);
        ui->lineEditRegData1->setText(checkDataString(tmpstr, 4));
    }

    if (!ui->lineEditRegAddr2->text().isEmpty()) {
        regAddr = getIntFromTexEditText(ui->lineEditRegAddr2->text());
        modbus_read_registers(mbPort, regAddr, 1, &data);
        tmpstr.setNum(data);
        ui->lineEditRegData2->setText(checkDataString(tmpstr, 4));
    }

    if (!ui->lineEditRegAddr3->text().isEmpty()) {
        regAddr = getIntFromTexEditText(ui->lineEditRegAddr3->text());
        modbus_read_registers(mbPort, regAddr, 1, &data);
        tmpstr.setNum(data);
        ui->lineEditRegData3->setText(checkDataString(tmpstr, 4));
    }

    if (!ui->lineEditRegAddr4->text().isEmpty()) {
        regAddr = getIntFromTexEditText(ui->lineEditRegAddr4->text());
        modbus_read_registers(mbPort, regAddr, 1, &data);
        tmpstr.setNum(data);
        ui->lineEditRegData4->setText(checkDataString(tmpstr, 4));
    }

    if (!ui->lineEditRegAddr5->text().isEmpty()) {
        regAddr = getIntFromTexEditText(ui->lineEditRegAddr5->text());
        modbus_read_registers(mbPort, regAddr, 1, &data);
        tmpstr.setNum(data);
        ui->lineEditRegData5->setText(checkDataString(tmpstr, 4));
    }

}

void MainWindow::registersWriteRegister()
{
    int addr;
    int regAddr;
    int data;

    if (mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = registersGetSlaveAddr();
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(mbPort, addr);

    if (!ui->lineEditAddrRegToWrite->text().isEmpty()) {
        regAddr = getIntFromTexEditText(ui->lineEditAddrRegToWrite->text());
        if (!ui->lineEditDataRegToWrite->text().isEmpty()) {
            data = getIntFromTexEditText(ui->lineEditDataRegToWrite->text());

            modbus_write_register(mbPort, regAddr, data);
        }
    }
}

void MainWindow::readWattMeterRequest()
{
    // вычитваем 8 регистров с 0x0002 по 0x0009 включительно
    quint16 data[8];
    int addr;
    int regAddr = 0x0002;
    QString LCDstr;

    if (mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = wattmeterGetSlaveAddr();
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(mbPort, addr);
    modbus_read_registers(mbPort, regAddr, 8, data);

    LCDstr.setNum(data[0]);
    LCDstr.insert(LCDstr.length()-1,'.');
    ui->lcdNumberMeasU->display(LCDstr);

    LCDstr.setNum(data[1]);
    if (LCDstr.length() < 2) {
        LCDstr.insert(0, "0.0");
    } else {
        if (LCDstr.length() < 3) {
            LCDstr.insert(0, "0.");
        } else {
            LCDstr.insert(LCDstr.length()-2, '.');
        }
    }
    ui->lcdNumberMeasI->display(LCDstr);

    LCDstr.setNum(data[2]);
    if (LCDstr.length() < 2) {
        LCDstr.insert(0, "0.");
    } else {
        LCDstr.insert(LCDstr.length()-1, '.');
    }
    ui->lcdNumberMeasS->display(LCDstr);

    LCDstr.setNum((qint16)data[3]);
    if (LCDstr.length() < 2) {
        LCDstr.insert(0, "0.");
    } else {
        if ((qint16)data[3] < 0 && LCDstr.length() == 2) {
            LCDstr.insert(1, "0.");
        }
        else {
            LCDstr.insert(LCDstr.length()-1, '.');
        }
    }
    ui->lcdNumberMeasP->display(LCDstr);

}

// получить адрес слейв устройства в окне чтения данных с ваттметра
int MainWindow::wattmeterGetSlaveAddr(void)
{
    int addr;
    bool ok;
    QString str;

    while (ui->lineEditWattmeterAddr->text().isEmpty()) {
        str = QInputDialog::getText(this, QString::fromLocal8Bit("Не задан адрес устройства"),
                                     QString::fromLocal8Bit("Адрес устройства: "), QLineEdit::Normal, "", &ok);
        if (ok) {
            ui->lineEditWattmeterAddr->setText(checkDataString(str, 2));
        }
        else {
           return -1;
        }
    }

    addr = getIntFromTexEditText(ui->lineEditWattmeterAddr->text());

    return addr;
}

void MainWindow::readeSwitchRequest()
{

}

/*
 *  Все что относиться к окну управления eSwitch
 */

// получить адрес слейв устройства в окне управления переключателем
int MainWindow::eswitchGetSlaveAddr(void)
{
    int addr;
    bool ok;
    QString str;

    while (ui->lineEditeSwitchAddr->text().isEmpty()) {
        str = QInputDialog::getText(this, QString::fromLocal8Bit("Не задан адрес устройства"),
                                     QString::fromLocal8Bit("Адрес устройства: "), QLineEdit::Normal, "", &ok);
        if (ok) {
            ui->lineEditeSwitchAddr->setText(checkDataString(str, 2));
        }
        else {
           return -1;
        }
    }

    addr = getIntFromTexEditText(ui->lineEditeSwitchAddr->text());

    return addr;
}

void MainWindow::eswitchOn()
{
    int addr;
    int regAddr = 0;
    int data = 1;

    if (mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = eswitchGetSlaveAddr();
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(mbPort, addr);
    modbus_write_register(mbPort, regAddr, data);
}

void MainWindow::eswitchOff()
{
    int addr;
    int regAddr = 0;
    int data = 0;

    if (mbPort == NULL) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Последовательный порт не отрыт!"));
        return;
    }

    addr = eswitchGetSlaveAddr();
    if (addr == -1) {
        QMessageBox::information(NULL, QString::fromLocal8Bit("Ошибка подключения"),
                                QString::fromLocal8Bit("Не задан сетевой адрес устройства!"));
        return;
    }

    modbus_set_slave(mbPort, addr);
    modbus_write_register(mbPort, regAddr, data);
}

void MainWindow::eswitchStartOn()
{
    int time;
    time = ui->lineEditTimeOn->text().toInt();
    this->eSwitchOnTimer->setSingleShot(true);
    this->eSwitchOnTimer->singleShot(time*1000, this, SLOT(eswitchOff()));

    this->eswitchOn();
}

void MainWindow::eSwitchClassInit()
{
    int addr;
    int xPos = 0;
    bool ok;
    QString str, name;
    eSwitch *eswitchDev;

    if (ui->lineEditAddreSwitchClass->text().isEmpty()) {
        str = QInputDialog::getText(this, QString::fromLocal8Bit("Не задан адрес устройства"),
                                     QString::fromLocal8Bit("Адрес устройства: "), QLineEdit::Normal, "", &ok);
        if (ok) {
            ui->lineEditAddreSwitchClass->setText(checkDataString(str, 2));
        }
        else {
           return;
        }
    }

    addr = getIntFromTexEditText(ui->lineEditAddreSwitchClass->text());

    name = ui->lineEditNameeSwitchClass->text();
    addr = ui->lineEditAddreSwitchClass->text().toInt();
    eswitchDev = new eSwitch(ui->tab, name, addr);
    // помещаем девайс на форму
    xPos = numModuls_ * 125 + 10;
    eswitchDev->move(xPos, 100);
    numModuls_++;

    //eswitchDev->setMbPort(this->mbPort);
    eswitchDev->setMbAddr(addr);

    hardwareVector.push_back(eswitchDev);
}

void MainWindow::addTimerButtonClick()
{
    int xPos = 0;
    QString name;
    ByceTimer *byceTimer;

    name = ui->lineEditNameeSwitchClass->text();
    byceTimer = new ByceTimer(ui->tab, name);
    // помещаем девайс на форму
    xPos = numModuls_ * 125 + 10;
    byceTimer->move(xPos, 100);
    numModuls_++;

    softwareVector.push_back(byceTimer);
}

void MainWindow::confirureSignalsModules()
{
    ByceTimer *byceTimer = (ByceTimer*) softwareVector[0];
    eSwitch *eswitchDev = (eSwitch*) hardwareVector[0];

    connect(eswitchDev, SIGNAL(dInRaise()), byceTimer, SLOT(startTimerButton()));
    connect(byceTimer, SIGNAL(byceTimeOut()), eswitchDev, SLOT(off()));
}

void MainWindow::tryScriptEngine()
{
    QScriptEngine engine;
    qDebug() << "the magic number is:" << engine.evaluate("1 + 2").toNumber();
    engine.evaluate("ui->pushButtonStartScript->resize(10, 10)");
}

// проверка адреса и данных на правельность ввода
// перекодировка строки из dec в hex и обратно в зависимости от радиобатон
QString MainWindow::checkDataString(QString str, int fmt = 4)
{
    // раздупляем что ввел пользователь
    // приводим к единному виду
    int data;
    QString tmp;

    if (str.isEmpty())
        return "";

    if (str.startsWith("0x") || str.startsWith("0X")) {
        // должно быть в hex формате

        tmp = str;
        tmp.remove(0, 2);

        if (tmp.contains(QRegExp("[^0-9A-Fa-f]")))
                return "";

        tmp = tmp.toUpper();
        str.clear();
        str = "0x" + tmp.rightJustified(fmt, '0', true);
    }
    else {
        if (str.contains(QRegExp("\\D")))
                return "";

        switch (fmt) {
        case 4 : if (str.toInt() > 65535) {
                str.clear();
                str = QString("%1").arg(65535);
            }
            break;
        case 2 : if (str.toInt() > 255) {
                str.clear();
                str = QString("%1").arg(255);
            }
            break;
        default: str.clear();
            break;
        }

        // удаляем начальные нули
        while (str.startsWith('0'))
            str.remove(0, 1);
    }

    // проверяем какой формат должен быть
    if (ui->radioButtonHex->isChecked()) {
        // hex
        if (!str.startsWith("0x")) {
            data = str.toInt();
            str.clear();
            tmp.clear();
            tmp = QString("%1").arg(data, 0, 16);
            tmp = tmp.toUpper();
            str = "0x" + tmp.rightJustified(fmt, '0', true);
        }

    }
    else {
        // int
        if (str.startsWith("0x")) {
            str.remove(0, 2);
            data = str.toInt(0, 16);
            str.clear();
            str = QString("%1").arg(data);  // есть метод setNum вместо этого изврата
        }
    }

    return str;
}

// проверка валидности введенных данных
void MainWindow::lineEditChenged(void)
{
    ui->lineEditRegAddr1->setText(checkDataString(ui->lineEditRegAddr1->text()));
    ui->lineEditRegAddr2->setText(checkDataString(ui->lineEditRegAddr2->text()));
    ui->lineEditRegAddr3->setText(checkDataString(ui->lineEditRegAddr3->text()));
    ui->lineEditRegAddr4->setText(checkDataString(ui->lineEditRegAddr4->text()));
    ui->lineEditRegAddr5->setText(checkDataString(ui->lineEditRegAddr5->text()));

    ui->lineEditAddrRegToWrite->setText(checkDataString(ui->lineEditAddrRegToWrite->text()));
    ui->lineEditDataRegToWrite->setText(checkDataString(ui->lineEditDataRegToWrite->text()));

    ui->lineEditDeviceAddrRegs->setText(checkDataString(ui->lineEditDeviceAddrRegs->text(), 2));
}

// получить адрес слейв устройства в окне чтения регистров
int MainWindow::registersGetSlaveAddr(void)
{
    int addr;
    bool ok;
    QString str;

    while (ui->lineEditDeviceAddrRegs->text().isEmpty()) {
        str = QInputDialog::getText(this, QString::fromLocal8Bit("Не задан адрес устройства"),
                                     QString::fromLocal8Bit("Адрес устройства: "), QLineEdit::Normal, "", &ok);
        if (ok) {
            ui->lineEditDeviceAddrRegs->setText(checkDataString(str, 2));
        }
        else {
           return -1;
        }
    }

    addr = getIntFromTexEditText(ui->lineEditDeviceAddrRegs->text());

    return addr;
}

int MainWindow::getIntFromTexEditText(QString str)
{
    int data;
    bool ok;

    if (str.startsWith("0x")) {
        str.remove(0, 2);
        data = str.toInt(&ok, 16);
    }
    else {
        data = str.toInt();
    }

    return data;
}
