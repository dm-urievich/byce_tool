#ifndef WINDOWOPTIONS_H
#define WINDOWOPTIONS_H

#include <QDialog>
#include <QSettings>
#include <QtAddOnSerialPort/serialport-global.h>

namespace Ui {
class windowOptions;
}

QT_BEGIN_NAMESPACE_SERIALPORT
class SerialPort;
QT_END_NAMESPACE_SERIALPORT

QT_USE_NAMESPACE_SERIALPORT

class windowOptions : public QDialog
{
    Q_OBJECT
    
public:
    explicit windowOptions(QWidget *parent = 0, QSettings * settings = 0);
    ~windowOptions();
    
private:
    Ui::windowOptions *ui;
    QSettings *settings;

    void fillPortsInfo(void);

private slots:
    void buttonApplayOptionsClick(void);
    void buttonCancelClick(void);

protected:
    void showEvent(QShowEvent * event);

};

#endif // WINDOWOPTIONS_H
