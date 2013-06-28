#include "eswitchwindow.h"
#include "ui_eswitchwindow.h"

eSwitchWindow::eSwitchWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::eSwitchWindow)
{
    ui->setupUi(this);

    connect(ui->pushButtonEswitchWindowOn, SIGNAL(clicked()), this, SIGNAL(switchOn()));
    connect(ui->pushButtonEswitchWindowOff, SIGNAL(clicked()), this, SIGNAL(switchOff()));
}

eSwitchWindow::~eSwitchWindow()
{
    delete ui;
}
