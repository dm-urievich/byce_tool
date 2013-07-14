#ifndef HARDWARESETTINGSDIALOG_H
#define HARDWARESETTINGSDIALOG_H

#include <QDialog>
#include <QVector>
#include <QComboBox>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "modbusregister.h"
#include "hardware.h"

class HardwareSettingsDialog : public QDialog
{
    Q_OBJECT
public:
    explicit HardwareSettingsDialog(QWidget *parent = 0, QString file = "HardwareModule", Hardware* module = 0);

    QString descriptorFile;
    Hardware* hardwareModule;
    
signals:
    
public slots:

private:
    void refreshRegisters(void);
    void readDescriptorFromFile(QString fileName);
    bool isRegDeclarationString(QString &str);
    int getRegisterType(QString& str);

    QVector<QLabel*> labelVector;
    QVector<QComboBox*> boxVector;
    QVector<ModbusRegister*> registerVector;
    QVector<QLineEdit*> lineeditVector;

    QPushButton* buttonOk;
    QPushButton* buttonCancel;

private slots:
    void applySettings();
    void cancelSettings();
    
};

#endif // HARDWARESETTINGSDIALOG_H
