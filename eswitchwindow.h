#ifndef ESWITCHWINDOW_H
#define ESWITCHWINDOW_H

#include <QDialog>

namespace Ui {
class eSwitchWindow;
}

class eSwitchWindow : public QDialog
{
    Q_OBJECT
    
public:
    explicit eSwitchWindow(QWidget *parent = 0);
    ~eSwitchWindow();
    
private:
    Ui::eSwitchWindow *ui;

signals:
    void switchOn(void);
    void switchOff(void);
};

#endif // ESWITCHWINDOW_H
