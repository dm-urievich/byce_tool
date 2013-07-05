/********************************************************************************
** Form generated from reading UI file 'windowoptions.ui'
**
** Created: Tue Jul 2 00:13:00 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWOPTIONS_H
#define UI_WINDOWOPTIONS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QComboBox>
#include <QtGui/QDialog>
#include <QtGui/QGridLayout>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_windowOptions
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboBoxPortName;
    QComboBox *comboBoxBaud;
    QLabel *label_3;
    QComboBox *comboBoxStopBits;
    QLabel *label_4;
    QComboBox *comboBoxParity;
    QLabel *label_2;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QPushButton *buttonCancel;
    QSpacerItem *horizontalSpacer;
    QPushButton *buttonApply;

    void setupUi(QDialog *windowOptions)
    {
        if (windowOptions->objectName().isEmpty())
            windowOptions->setObjectName(QString::fromUtf8("windowOptions"));
        windowOptions->resize(254, 258);
        verticalLayout = new QVBoxLayout(windowOptions);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(windowOptions);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        comboBoxPortName = new QComboBox(windowOptions);
        comboBoxPortName->setObjectName(QString::fromUtf8("comboBoxPortName"));

        gridLayout->addWidget(comboBoxPortName, 0, 1, 1, 1);

        comboBoxBaud = new QComboBox(windowOptions);
        comboBoxBaud->setObjectName(QString::fromUtf8("comboBoxBaud"));

        gridLayout->addWidget(comboBoxBaud, 1, 1, 1, 1);

        label_3 = new QLabel(windowOptions);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        comboBoxStopBits = new QComboBox(windowOptions);
        comboBoxStopBits->setObjectName(QString::fromUtf8("comboBoxStopBits"));

        gridLayout->addWidget(comboBoxStopBits, 2, 1, 1, 1);

        label_4 = new QLabel(windowOptions);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        comboBoxParity = new QComboBox(windowOptions);
        comboBoxParity->setObjectName(QString::fromUtf8("comboBoxParity"));

        gridLayout->addWidget(comboBoxParity, 3, 1, 1, 1);

        label_2 = new QLabel(windowOptions);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        buttonCancel = new QPushButton(windowOptions);
        buttonCancel->setObjectName(QString::fromUtf8("buttonCancel"));

        horizontalLayout->addWidget(buttonCancel);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        buttonApply = new QPushButton(windowOptions);
        buttonApply->setObjectName(QString::fromUtf8("buttonApply"));

        horizontalLayout->addWidget(buttonApply);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(buttonApply, buttonCancel);

        retranslateUi(windowOptions);

        comboBoxBaud->setCurrentIndex(5);
        comboBoxStopBits->setCurrentIndex(0);
        comboBoxParity->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(windowOptions);
    } // setupUi

    void retranslateUi(QDialog *windowOptions)
    {
        windowOptions->setWindowTitle(QApplication::translate("windowOptions", "Port Settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("windowOptions", "Port Name", 0, QApplication::UnicodeUTF8));
        comboBoxBaud->clear();
        comboBoxBaud->insertItems(0, QStringList()
         << QApplication::translate("windowOptions", "1200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "2400", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "4800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "9600", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "34800", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "115200", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "230400", 0, QApplication::UnicodeUTF8)
        );
        label_3->setText(QApplication::translate("windowOptions", "Stop bits", 0, QApplication::UnicodeUTF8));
        comboBoxStopBits->clear();
        comboBoxStopBits->insertItems(0, QStringList()
         << QApplication::translate("windowOptions", "1", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "2", 0, QApplication::UnicodeUTF8)
        );
        label_4->setText(QApplication::translate("windowOptions", "Parity", 0, QApplication::UnicodeUTF8));
        comboBoxParity->clear();
        comboBoxParity->insertItems(0, QStringList()
         << QApplication::translate("windowOptions", "none", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "odd", 0, QApplication::UnicodeUTF8)
         << QApplication::translate("windowOptions", "even", 0, QApplication::UnicodeUTF8)
        );
        label_2->setText(QApplication::translate("windowOptions", "Baud", 0, QApplication::UnicodeUTF8));
        buttonCancel->setText(QApplication::translate("windowOptions", "\320\236\321\202\320\274\320\265\320\275\320\260", 0, QApplication::UnicodeUTF8));
        buttonApply->setText(QApplication::translate("windowOptions", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class windowOptions: public Ui_windowOptions {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWOPTIONS_H
