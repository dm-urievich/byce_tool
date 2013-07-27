#ifndef WINDOWOPTIONS_H
#define WINDOWOPTIONS_H

#include <QDialog>
#include <QSettings>
#include <QtSerialPort/qserialportglobal.h>

namespace Ui {
class windowOptions;
}

QT_BEGIN_NAMESPACE
class SerialPort;
QT_END_NAMESPACE

QT_USE_NAMESPACE

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
