#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore/QSettings>
#include "windowoptions.h"
#include <QSettings>
#include <QVector>
#include <QString>
#include <QTimer>
#include <QMessageBox>
#include <QInputDialog>
#include <QVector>
#include <QtScript>

#include "modbus.h"
#include "busmonitor.h"
#include "modbusadapter.h"
#include "eswitchwindow.h"

#include "eswitch.h"
#include "bycetimer.h"

#include "module.h"
#include "transferthread.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    windowOptions *windowoption;

    modbus_t *mbPort;
    QSettings *portSettings;

    BusMonitor *m_busMonitor;
    ModbusAdapter *m_modbus;

    QTimer *mbReadRequestTimer;

    eSwitchWindow* eSwitchWindowControl;
    QTimer *eSwitchOnTimer;

    Module *testModule;

    TransferThread* transferHardwareModules;

    QVector<Hardware*> hardwareVector;
    QVector<Software*> softwareVector;
    int numModuls_;

    void initbuttons();
    void readRegistersRequest(void);
    void readWattMeterRequest(void);
    void readeSwitchRequest(void);

    int registersGetSlaveAddr(void);
    int wattmeterGetSlaveAddr(void);
    int eswitchGetSlaveAddr(void);

    QString checkDataString(QString, int);
    int getIntFromTexEditText(QString);

private slots:
    void showWindowOption(void);
    void buttonOpenCloseClick(void);
    void showBusMonitor(void);
    void readRequest(void);
    void readRequestButtonClick(void);
    void mbTimerSetTimeInterval(int);

    void lineEditChenged(void);

    // обработчики кнопок на закладке чтения регистров
    void registersReadRegisters(void);
    void registersReadDeviceId(void);
    void registersWriteRegister(void);
    void registersClearRegisters(void);

    // обработчики кнопок на закладке выключателя
    void eswitchStartOn(void);
    //void eswitchStopOn(void);
    void eSwitchClassInit(void);
    void addTimerButtonClick(void);
    void confirureSignalsModules(void);
    void tryScriptEngine(void);

public slots:
    // обработчики кнопок на закладке выключателя
    void eswitchOn(void);
    void eswitchOff(void);

};

#endif // MAINWINDOW_H
