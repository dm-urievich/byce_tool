/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Jun 28 21:15:19 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLCDNumber>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QSpinBox>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonSettings;
    QPushButton *buttonOpenClose;
    QPushButton *buttonMonitor;
    QPushButton *buttonReadRequest;
    QCheckBox *checkBoxPeriodicaly;
    QSpinBox *spinBoxPeriod;
    QLabel *label_8;
    QTabWidget *tabWidgetMain;
    QWidget *tabRegisters;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEditDeviceAddrRegs;
    QRadioButton *radioButtonHex;
    QRadioButton *radioButtonInt;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditDataRegToWrite;
    QLineEdit *lineEditAddrRegToWrite;
    QLabel *label_4;
    QPushButton *pushButtonWriteReg;
    QSpacerItem *verticalSpacer_2;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QLabel *label_15;
    QLineEdit *lineEditDeviceId;
    QLabel *label_7;
    QLineEdit *lineEditDeviceName;
    QLabel *label_6;
    QPushButton *pushButtonReadId;
    QLineEdit *lineEditRunStatus;
    QSpacerItem *horizontalSpacer_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLabel *label_3;
    QLineEdit *lineEditRegAddr1;
    QLineEdit *lineEditRegData1;
    QLineEdit *lineEditRegAddr2;
    QLineEdit *lineEditRegData2;
    QLineEdit *lineEditRegAddr3;
    QLineEdit *lineEditRegData3;
    QLineEdit *lineEditRegAddr4;
    QLineEdit *lineEditRegData4;
    QLineEdit *lineEditRegAddr5;
    QLineEdit *lineEditRegData5;
    QPushButton *pushButtonClearRegs;
    QPushButton *pushButtonReadRegs;
    QWidget *tabWattMeter;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_9;
    QLineEdit *lineEditWattmeterAddr;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *layoutWidget2;
    QFormLayout *formLayout;
    QLabel *label_10;
    QLCDNumber *lcdNumberMeasU;
    QLabel *label_11;
    QLCDNumber *lcdNumberMeasI;
    QLabel *label_12;
    QLCDNumber *lcdNumberMeasS;
    QLabel *label_13;
    QLCDNumber *lcdNumberMeasP;
    QLabel *label_14;
    QLCDNumber *lcdNumberMeasWatts;
    QWidget *tabeSwitch;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_16;
    QLineEdit *lineEditeSwitchAddr;
    QPushButton *pushButtonSwitchOn;
    QPushButton *pushButtonSwitchOff;
    QPushButton *pushButtonSwitcherWindow;
    QLineEdit *lineEditTimeOn;
    QPushButton *pushButtonStopOn;
    QPushButton *pushButtonStartOn;
    QWidget *tab;
    QPushButton *pushButtonIniteSwitchClass;
    QLineEdit *lineEditAddreSwitchClass;
    QPushButton *pushButtoneSwitchClassOn;
    QPushButton *pushButtoneSwitchClassOff;
    QCheckBox *checkBoxeSwitchClassLamp;
    QMenuBar *menuBar;
    QStatusBar *statusBar;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(656, 440);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonSettings = new QPushButton(widget);
        buttonSettings->setObjectName(QString::fromUtf8("buttonSettings"));

        horizontalLayout->addWidget(buttonSettings);

        buttonOpenClose = new QPushButton(widget);
        buttonOpenClose->setObjectName(QString::fromUtf8("buttonOpenClose"));

        horizontalLayout->addWidget(buttonOpenClose);

        buttonMonitor = new QPushButton(widget);
        buttonMonitor->setObjectName(QString::fromUtf8("buttonMonitor"));

        horizontalLayout->addWidget(buttonMonitor);

        buttonReadRequest = new QPushButton(widget);
        buttonReadRequest->setObjectName(QString::fromUtf8("buttonReadRequest"));
        buttonReadRequest->setCheckable(true);
        buttonReadRequest->setChecked(false);

        horizontalLayout->addWidget(buttonReadRequest);

        checkBoxPeriodicaly = new QCheckBox(widget);
        checkBoxPeriodicaly->setObjectName(QString::fromUtf8("checkBoxPeriodicaly"));

        horizontalLayout->addWidget(checkBoxPeriodicaly);

        spinBoxPeriod = new QSpinBox(widget);
        spinBoxPeriod->setObjectName(QString::fromUtf8("spinBoxPeriod"));
        spinBoxPeriod->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        spinBoxPeriod->setButtonSymbols(QAbstractSpinBox::PlusMinus);
        spinBoxPeriod->setMinimum(100);
        spinBoxPeriod->setMaximum(10000);
        spinBoxPeriod->setSingleStep(100);
        spinBoxPeriod->setValue(1000);

        horizontalLayout->addWidget(spinBoxPeriod);

        label_8 = new QLabel(widget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout->addWidget(label_8);

        label_8->raise();
        checkBoxPeriodicaly->raise();
        buttonReadRequest->raise();
        spinBoxPeriod->raise();
        buttonOpenClose->raise();
        buttonSettings->raise();
        buttonMonitor->raise();

        verticalLayout->addWidget(widget);

        tabWidgetMain = new QTabWidget(centralWidget);
        tabWidgetMain->setObjectName(QString::fromUtf8("tabWidgetMain"));
        tabWidgetMain->setMinimumSize(QSize(638, 311));
        tabWidgetMain->setTabPosition(QTabWidget::North);
        tabWidgetMain->setTabShape(QTabWidget::Rounded);
        tabRegisters = new QWidget();
        tabRegisters->setObjectName(QString::fromUtf8("tabRegisters"));
        horizontalLayout_3 = new QHBoxLayout(tabRegisters);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(tabRegisters);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(140, 27));
        label->setMaximumSize(QSize(140, 27));

        horizontalLayout_2->addWidget(label);

        lineEditDeviceAddrRegs = new QLineEdit(tabRegisters);
        lineEditDeviceAddrRegs->setObjectName(QString::fromUtf8("lineEditDeviceAddrRegs"));
        lineEditDeviceAddrRegs->setMaximumSize(QSize(90, 16777215));
        lineEditDeviceAddrRegs->setMaxLength(6);
        lineEditDeviceAddrRegs->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(lineEditDeviceAddrRegs);

        radioButtonHex = new QRadioButton(tabRegisters);
        radioButtonHex->setObjectName(QString::fromUtf8("radioButtonHex"));
        radioButtonHex->setChecked(true);

        horizontalLayout_2->addWidget(radioButtonHex);

        radioButtonInt = new QRadioButton(tabRegisters);
        radioButtonInt->setObjectName(QString::fromUtf8("radioButtonInt"));

        horizontalLayout_2->addWidget(radioButtonInt);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        groupBox_2 = new QGroupBox(tabRegisters);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(391, 92));
        gridLayout_2 = new QGridLayout(groupBox_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 0, 1, 1, 1);

        lineEditDataRegToWrite = new QLineEdit(groupBox_2);
        lineEditDataRegToWrite->setObjectName(QString::fromUtf8("lineEditDataRegToWrite"));
        lineEditDataRegToWrite->setMaxLength(6);
        lineEditDataRegToWrite->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditDataRegToWrite, 1, 1, 1, 1);

        lineEditAddrRegToWrite = new QLineEdit(groupBox_2);
        lineEditAddrRegToWrite->setObjectName(QString::fromUtf8("lineEditAddrRegToWrite"));
        lineEditAddrRegToWrite->setMaxLength(6);
        lineEditAddrRegToWrite->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(lineEditAddrRegToWrite, 1, 0, 1, 1);

        label_4 = new QLabel(groupBox_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        pushButtonWriteReg = new QPushButton(groupBox_2);
        pushButtonWriteReg->setObjectName(QString::fromUtf8("pushButtonWriteReg"));

        gridLayout_2->addWidget(pushButtonWriteReg, 1, 2, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        groupBox_3 = new QGroupBox(tabRegisters);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setMinimumSize(QSize(391, 112));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_15 = new QLabel(groupBox_3);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_3->addWidget(label_15, 0, 1, 1, 1);

        lineEditDeviceId = new QLineEdit(groupBox_3);
        lineEditDeviceId->setObjectName(QString::fromUtf8("lineEditDeviceId"));
        lineEditDeviceId->setMinimumSize(QSize(51, 27));
        lineEditDeviceId->setMaximumSize(QSize(51, 27));
        lineEditDeviceId->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDeviceId->setReadOnly(true);

        gridLayout_3->addWidget(lineEditDeviceId, 1, 0, 1, 1);

        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setMinimumSize(QSize(66, 17));
        label_7->setMaximumSize(QSize(66, 17));

        gridLayout_3->addWidget(label_7, 0, 2, 1, 1);

        lineEditDeviceName = new QLineEdit(groupBox_3);
        lineEditDeviceName->setObjectName(QString::fromUtf8("lineEditDeviceName"));
        lineEditDeviceName->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditDeviceName->setReadOnly(true);

        gridLayout_3->addWidget(lineEditDeviceName, 1, 2, 1, 1);

        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_3->addWidget(label_6, 0, 0, 1, 1);

        pushButtonReadId = new QPushButton(groupBox_3);
        pushButtonReadId->setObjectName(QString::fromUtf8("pushButtonReadId"));

        gridLayout_3->addWidget(pushButtonReadId, 1, 4, 1, 1);

        lineEditRunStatus = new QLineEdit(groupBox_3);
        lineEditRunStatus->setObjectName(QString::fromUtf8("lineEditRunStatus"));
        lineEditRunStatus->setMaximumSize(QSize(50, 16777215));
        lineEditRunStatus->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRunStatus->setReadOnly(true);

        gridLayout_3->addWidget(lineEditRunStatus, 1, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox_3);


        horizontalLayout_3->addLayout(verticalLayout_3);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        groupBox = new QGroupBox(tabRegisters);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 1, 1, 1);

        lineEditRegAddr1 = new QLineEdit(groupBox);
        lineEditRegAddr1->setObjectName(QString::fromUtf8("lineEditRegAddr1"));
        lineEditRegAddr1->setMaxLength(6);
        lineEditRegAddr1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditRegAddr1, 1, 0, 1, 1);

        lineEditRegData1 = new QLineEdit(groupBox);
        lineEditRegData1->setObjectName(QString::fromUtf8("lineEditRegData1"));
        lineEditRegData1->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRegData1->setReadOnly(true);

        gridLayout->addWidget(lineEditRegData1, 1, 1, 1, 1);

        lineEditRegAddr2 = new QLineEdit(groupBox);
        lineEditRegAddr2->setObjectName(QString::fromUtf8("lineEditRegAddr2"));
        lineEditRegAddr2->setMaxLength(6);
        lineEditRegAddr2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditRegAddr2, 2, 0, 1, 1);

        lineEditRegData2 = new QLineEdit(groupBox);
        lineEditRegData2->setObjectName(QString::fromUtf8("lineEditRegData2"));
        lineEditRegData2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRegData2->setReadOnly(true);

        gridLayout->addWidget(lineEditRegData2, 2, 1, 1, 1);

        lineEditRegAddr3 = new QLineEdit(groupBox);
        lineEditRegAddr3->setObjectName(QString::fromUtf8("lineEditRegAddr3"));
        lineEditRegAddr3->setMaxLength(6);
        lineEditRegAddr3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditRegAddr3, 3, 0, 1, 1);

        lineEditRegData3 = new QLineEdit(groupBox);
        lineEditRegData3->setObjectName(QString::fromUtf8("lineEditRegData3"));
        lineEditRegData3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRegData3->setReadOnly(true);

        gridLayout->addWidget(lineEditRegData3, 3, 1, 1, 1);

        lineEditRegAddr4 = new QLineEdit(groupBox);
        lineEditRegAddr4->setObjectName(QString::fromUtf8("lineEditRegAddr4"));
        lineEditRegAddr4->setMaxLength(6);
        lineEditRegAddr4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditRegAddr4, 4, 0, 1, 1);

        lineEditRegData4 = new QLineEdit(groupBox);
        lineEditRegData4->setObjectName(QString::fromUtf8("lineEditRegData4"));
        lineEditRegData4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRegData4->setReadOnly(true);

        gridLayout->addWidget(lineEditRegData4, 4, 1, 1, 1);

        lineEditRegAddr5 = new QLineEdit(groupBox);
        lineEditRegAddr5->setObjectName(QString::fromUtf8("lineEditRegAddr5"));
        lineEditRegAddr5->setMaxLength(6);
        lineEditRegAddr5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(lineEditRegAddr5, 5, 0, 1, 1);

        lineEditRegData5 = new QLineEdit(groupBox);
        lineEditRegData5->setObjectName(QString::fromUtf8("lineEditRegData5"));
        lineEditRegData5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        lineEditRegData5->setReadOnly(true);

        gridLayout->addWidget(lineEditRegData5, 5, 1, 1, 1);

        pushButtonClearRegs = new QPushButton(groupBox);
        pushButtonClearRegs->setObjectName(QString::fromUtf8("pushButtonClearRegs"));

        gridLayout->addWidget(pushButtonClearRegs, 6, 0, 1, 1);

        pushButtonReadRegs = new QPushButton(groupBox);
        pushButtonReadRegs->setObjectName(QString::fromUtf8("pushButtonReadRegs"));

        gridLayout->addWidget(pushButtonReadRegs, 6, 1, 1, 1);


        horizontalLayout_3->addWidget(groupBox);

        tabWidgetMain->addTab(tabRegisters, QString());
        tabWattMeter = new QWidget();
        tabWattMeter->setObjectName(QString::fromUtf8("tabWattMeter"));
        layoutWidget = new QWidget(tabWattMeter);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(400, 20, 152, 29));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget);
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_9 = new QLabel(layoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_4->addWidget(label_9);

        lineEditWattmeterAddr = new QLineEdit(layoutWidget);
        lineEditWattmeterAddr->setObjectName(QString::fromUtf8("lineEditWattmeterAddr"));
        lineEditWattmeterAddr->setMaximumSize(QSize(41, 27));
        QFont font;
        font.setPointSize(11);
        lineEditWattmeterAddr->setFont(font);

        horizontalLayout_4->addWidget(lineEditWattmeterAddr);

        layoutWidget1 = new QWidget(tabWattMeter);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(400, 70, 104, 62));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(layoutWidget1);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout_4->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(layoutWidget1);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout_4->addWidget(pushButton_6);

        layoutWidget2 = new QWidget(tabWattMeter);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(20, 21, 333, 231));
        formLayout = new QFormLayout(layoutWidget2);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(layoutWidget2);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        QFont font1;
        font1.setPointSize(16);
        label_10->setFont(font1);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_10);

        lcdNumberMeasU = new QLCDNumber(layoutWidget2);
        lcdNumberMeasU->setObjectName(QString::fromUtf8("lcdNumberMeasU"));
        lcdNumberMeasU->setMinimumSize(QSize(121, 41));
        lcdNumberMeasU->setFrameShape(QFrame::Box);
        lcdNumberMeasU->setFrameShadow(QFrame::Plain);
        lcdNumberMeasU->setLineWidth(1);
        lcdNumberMeasU->setMidLineWidth(0);
        lcdNumberMeasU->setSmallDecimalPoint(true);
        lcdNumberMeasU->setNumDigits(6);
        lcdNumberMeasU->setDigitCount(6);
        lcdNumberMeasU->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberMeasU->setProperty("value", QVariant(0));
        lcdNumberMeasU->setProperty("intValue", QVariant(0));

        formLayout->setWidget(0, QFormLayout::FieldRole, lcdNumberMeasU);

        label_11 = new QLabel(layoutWidget2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font1);

        formLayout->setWidget(1, QFormLayout::LabelRole, label_11);

        lcdNumberMeasI = new QLCDNumber(layoutWidget2);
        lcdNumberMeasI->setObjectName(QString::fromUtf8("lcdNumberMeasI"));
        lcdNumberMeasI->setMinimumSize(QSize(121, 41));
        lcdNumberMeasI->setFrameShape(QFrame::Box);
        lcdNumberMeasI->setFrameShadow(QFrame::Plain);
        lcdNumberMeasI->setLineWidth(1);
        lcdNumberMeasI->setMidLineWidth(0);
        lcdNumberMeasI->setSmallDecimalPoint(true);
        lcdNumberMeasI->setNumDigits(6);
        lcdNumberMeasI->setDigitCount(6);
        lcdNumberMeasI->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberMeasI->setProperty("value", QVariant(0));
        lcdNumberMeasI->setProperty("intValue", QVariant(0));

        formLayout->setWidget(1, QFormLayout::FieldRole, lcdNumberMeasI);

        label_12 = new QLabel(layoutWidget2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setFont(font1);

        formLayout->setWidget(2, QFormLayout::LabelRole, label_12);

        lcdNumberMeasS = new QLCDNumber(layoutWidget2);
        lcdNumberMeasS->setObjectName(QString::fromUtf8("lcdNumberMeasS"));
        lcdNumberMeasS->setMinimumSize(QSize(121, 41));
        lcdNumberMeasS->setFrameShape(QFrame::Box);
        lcdNumberMeasS->setFrameShadow(QFrame::Plain);
        lcdNumberMeasS->setLineWidth(1);
        lcdNumberMeasS->setMidLineWidth(0);
        lcdNumberMeasS->setSmallDecimalPoint(true);
        lcdNumberMeasS->setNumDigits(6);
        lcdNumberMeasS->setDigitCount(6);
        lcdNumberMeasS->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberMeasS->setProperty("value", QVariant(0));
        lcdNumberMeasS->setProperty("intValue", QVariant(0));

        formLayout->setWidget(2, QFormLayout::FieldRole, lcdNumberMeasS);

        label_13 = new QLabel(layoutWidget2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setFont(font1);

        formLayout->setWidget(3, QFormLayout::LabelRole, label_13);

        lcdNumberMeasP = new QLCDNumber(layoutWidget2);
        lcdNumberMeasP->setObjectName(QString::fromUtf8("lcdNumberMeasP"));
        lcdNumberMeasP->setMinimumSize(QSize(121, 41));
        lcdNumberMeasP->setFrameShape(QFrame::Box);
        lcdNumberMeasP->setFrameShadow(QFrame::Plain);
        lcdNumberMeasP->setLineWidth(1);
        lcdNumberMeasP->setMidLineWidth(0);
        lcdNumberMeasP->setSmallDecimalPoint(true);
        lcdNumberMeasP->setNumDigits(6);
        lcdNumberMeasP->setDigitCount(6);
        lcdNumberMeasP->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberMeasP->setProperty("value", QVariant(0));
        lcdNumberMeasP->setProperty("intValue", QVariant(0));

        formLayout->setWidget(3, QFormLayout::FieldRole, lcdNumberMeasP);

        label_14 = new QLabel(layoutWidget2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setFont(font1);

        formLayout->setWidget(4, QFormLayout::LabelRole, label_14);

        lcdNumberMeasWatts = new QLCDNumber(layoutWidget2);
        lcdNumberMeasWatts->setObjectName(QString::fromUtf8("lcdNumberMeasWatts"));
        lcdNumberMeasWatts->setMinimumSize(QSize(121, 41));
        lcdNumberMeasWatts->setFrameShape(QFrame::Box);
        lcdNumberMeasWatts->setFrameShadow(QFrame::Plain);
        lcdNumberMeasWatts->setLineWidth(1);
        lcdNumberMeasWatts->setMidLineWidth(0);
        lcdNumberMeasWatts->setSmallDecimalPoint(true);
        lcdNumberMeasWatts->setNumDigits(6);
        lcdNumberMeasWatts->setDigitCount(6);
        lcdNumberMeasWatts->setSegmentStyle(QLCDNumber::Flat);
        lcdNumberMeasWatts->setProperty("value", QVariant(0));
        lcdNumberMeasWatts->setProperty("intValue", QVariant(0));

        formLayout->setWidget(4, QFormLayout::FieldRole, lcdNumberMeasWatts);

        tabWidgetMain->addTab(tabWattMeter, QString());
        tabeSwitch = new QWidget();
        tabeSwitch->setObjectName(QString::fromUtf8("tabeSwitch"));
        layoutWidget_2 = new QWidget(tabeSwitch);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(220, 20, 152, 29));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label_16 = new QLabel(layoutWidget_2);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_5->addWidget(label_16);

        lineEditeSwitchAddr = new QLineEdit(layoutWidget_2);
        lineEditeSwitchAddr->setObjectName(QString::fromUtf8("lineEditeSwitchAddr"));
        lineEditeSwitchAddr->setMaximumSize(QSize(41, 27));
        lineEditeSwitchAddr->setFont(font);

        horizontalLayout_5->addWidget(lineEditeSwitchAddr);

        pushButtonSwitchOn = new QPushButton(tabeSwitch);
        pushButtonSwitchOn->setObjectName(QString::fromUtf8("pushButtonSwitchOn"));
        pushButtonSwitchOn->setGeometry(QRect(30, 20, 98, 27));
        pushButtonSwitchOff = new QPushButton(tabeSwitch);
        pushButtonSwitchOff->setObjectName(QString::fromUtf8("pushButtonSwitchOff"));
        pushButtonSwitchOff->setGeometry(QRect(30, 60, 98, 27));
        pushButtonSwitcherWindow = new QPushButton(tabeSwitch);
        pushButtonSwitcherWindow->setObjectName(QString::fromUtf8("pushButtonSwitcherWindow"));
        pushButtonSwitcherWindow->setGeometry(QRect(220, 60, 151, 27));
        lineEditTimeOn = new QLineEdit(tabeSwitch);
        lineEditTimeOn->setObjectName(QString::fromUtf8("lineEditTimeOn"));
        lineEditTimeOn->setGeometry(QRect(30, 230, 113, 27));
        pushButtonStopOn = new QPushButton(tabeSwitch);
        pushButtonStopOn->setObjectName(QString::fromUtf8("pushButtonStopOn"));
        pushButtonStopOn->setGeometry(QRect(260, 230, 98, 27));
        pushButtonStartOn = new QPushButton(tabeSwitch);
        pushButtonStartOn->setObjectName(QString::fromUtf8("pushButtonStartOn"));
        pushButtonStartOn->setGeometry(QRect(150, 230, 98, 27));
        tabWidgetMain->addTab(tabeSwitch, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        pushButtonIniteSwitchClass = new QPushButton(tab);
        pushButtonIniteSwitchClass->setObjectName(QString::fromUtf8("pushButtonIniteSwitchClass"));
        pushButtonIniteSwitchClass->setGeometry(QRect(140, 20, 98, 27));
        lineEditAddreSwitchClass = new QLineEdit(tab);
        lineEditAddreSwitchClass->setObjectName(QString::fromUtf8("lineEditAddreSwitchClass"));
        lineEditAddreSwitchClass->setGeometry(QRect(20, 20, 101, 27));
        pushButtoneSwitchClassOn = new QPushButton(tab);
        pushButtoneSwitchClassOn->setObjectName(QString::fromUtf8("pushButtoneSwitchClassOn"));
        pushButtoneSwitchClassOn->setGeometry(QRect(20, 70, 101, 27));
        pushButtoneSwitchClassOff = new QPushButton(tab);
        pushButtoneSwitchClassOff->setObjectName(QString::fromUtf8("pushButtoneSwitchClassOff"));
        pushButtoneSwitchClassOff->setGeometry(QRect(20, 110, 101, 27));
        checkBoxeSwitchClassLamp = new QCheckBox(tab);
        checkBoxeSwitchClassLamp->setObjectName(QString::fromUtf8("checkBoxeSwitchClassLamp"));
        checkBoxeSwitchClassLamp->setGeometry(QRect(20, 170, 97, 22));
        tabWidgetMain->addTab(tab, QString());

        verticalLayout->addWidget(tabWidgetMain);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 656, 25));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        mainToolBar->setMovable(false);
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);

        retranslateUi(MainWindow);

        tabWidgetMain->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "BYCE tool", 0, QApplication::UnicodeUTF8));
        buttonSettings->setText(QApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\260", 0, QApplication::UnicodeUTF8));
        buttonOpenClose->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", 0, QApplication::UnicodeUTF8));
        buttonMonitor->setText(QApplication::translate("MainWindow", "\320\234\320\276\320\275\320\270\321\202\320\276\321\200", 0, QApplication::UnicodeUTF8));
        buttonReadRequest->setText(QApplication::translate("MainWindow", "\320\236\320\277\321\200\320\276\321\201", 0, QApplication::UnicodeUTF8));
        checkBoxPeriodicaly->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\265\321\201\320\272\320\270", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("MainWindow", "\320\274\321\201", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201 \321\203\321\201\321\202\321\200\320\276\320\271\321\201\321\202\320\262\320\260", 0, QApplication::UnicodeUTF8));
        radioButtonHex->setText(QApplication::translate("MainWindow", "hex", 0, QApplication::UnicodeUTF8));
        radioButtonInt->setText(QApplication::translate("MainWindow", "int", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\321\214 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\260", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pushButtonWriteReg->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "\320\230\320\264\320\265\320\275\321\202\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "Status", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("MainWindow", "Name", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Id", 0, QApplication::UnicodeUTF8));
        pushButtonReadId->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\247\321\202\320\265\320\275\320\270\320\265 \321\200\320\265\320\263\320\270\321\201\321\202\321\200\320\276\320\262", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "\320\220\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "\320\224\320\260\320\275\320\275\321\213\320\265", 0, QApplication::UnicodeUTF8));
        pushButtonClearRegs->setText(QApplication::translate("MainWindow", "\320\236\321\207\320\270\321\201\321\202\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonReadRegs->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\276\321\207\320\270\321\202\320\260\321\202\321\214", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabRegisters), QApplication::translate("MainWindow", "\320\240\320\265\320\263\320\270\321\201\321\202\321\200\321\213", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\223\321\200\320\260\321\204\320\270\320\272\320\270", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\232\320\260\320\273\320\270\320\261\321\200\320\276\320\262\320\272\320\260", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\277\321\200\321\217\320\266\320\265\320\275\320\270\320\265", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "\320\242\320\276\320\272", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\273\320\275\320\260\321\217 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "\320\220\320\272\321\202\320\270\320\262\320\275\320\260\321\217 \320\274\320\276\321\211\320\275\320\276\321\201\321\202\321\214", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "\320\232\320\270\320\273\320\276\320\262\320\260\321\202\321\202*\321\207\320\260\321\201", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabWattMeter), QApplication::translate("MainWindow", "WattMeter", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "\320\241\320\265\321\202\320\265\320\262\320\276\320\271 \320\260\320\264\321\200\320\265\321\201", 0, QApplication::UnicodeUTF8));
        pushButtonSwitchOn->setText(QApplication::translate("MainWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonSwitchOff->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonSwitcherWindow->setText(QApplication::translate("MainWindow", "\320\236\320\272\320\275\320\276 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", 0, QApplication::UnicodeUTF8));
        pushButtonStopOn->setText(QApplication::translate("MainWindow", "Stop", 0, QApplication::UnicodeUTF8));
        pushButtonStartOn->setText(QApplication::translate("MainWindow", "Start", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tabeSwitch), QApplication::translate("MainWindow", "eSwitch", 0, QApplication::UnicodeUTF8));
        pushButtonIniteSwitchClass->setText(QApplication::translate("MainWindow", "initialize", 0, QApplication::UnicodeUTF8));
        pushButtoneSwitchClassOn->setText(QApplication::translate("MainWindow", "on", 0, QApplication::UnicodeUTF8));
        pushButtoneSwitchClassOff->setText(QApplication::translate("MainWindow", "off", 0, QApplication::UnicodeUTF8));
        checkBoxeSwitchClassLamp->setText(QApplication::translate("MainWindow", "lamp", 0, QApplication::UnicodeUTF8));
        tabWidgetMain->setTabText(tabWidgetMain->indexOf(tab), QApplication::translate("MainWindow", "eSwitch class", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
