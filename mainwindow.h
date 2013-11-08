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
#include <QDomDocument>
#include <QDomElement>
#include <QDomText>

#include "modbus.h"
#include "busmonitor.h"
#include "modbusadapter.h"

#include "eswitch.h"
#include "bycetimer.h"

#include "modulegui.h"
#include "modbusswitchgui.h"
#include "connector.h"

#include "module.h"
#include "corebycetoolthread.h"
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

    QTimer *eSwitchOnTimer;

    TransferThread* transferHardwareModules;
    CoreByceToolThread* coreThread;

    QVector<ModuleGui*> moduleVector;

    Module *testModule;

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

signals:
    void moduleSocketRead(void);

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
    void eswitchOn(void);
    void eswitchOff(void);

    void eSwitchClassInit(void);
    void addTimerButtonClick(void);

    void refreshModulesGui(void);
    void generateXmlModuleGui(void);
    void eventGuiMachine(int idModule, QString eventName, QString eventData);

    void addModulesGui(void);               // добавление модулей
    void refreshModuleConnection(int);     // обновить данные на вкладке настройки соединений
    void listModuleEvents(int);            // выводит список событий в комбобокс
    void listModuleSockets(int);            // список сокетов
    void connectModules(void);              // соединение модулей

public slots:

};

#endif // MAINWINDOW_H
