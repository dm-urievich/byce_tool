/********************************************************************************
** Form generated from reading UI file 'eswitchwindow.ui'
**
** Created: Wed Jun 5 20:48:33 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ESWITCHWINDOW_H
#define UI_ESWITCHWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_eSwitchWindow
{
public:
    QPushButton *pushButtonEswitchWindowOff;
    QPushButton *pushButtonEswitchWindowOn;

    void setupUi(QDialog *eSwitchWindow)
    {
        if (eSwitchWindow->objectName().isEmpty())
            eSwitchWindow->setObjectName(QString::fromUtf8("eSwitchWindow"));
        eSwitchWindow->resize(156, 131);
        eSwitchWindow->setSizeGripEnabled(false);
        pushButtonEswitchWindowOff = new QPushButton(eSwitchWindow);
        pushButtonEswitchWindowOff->setObjectName(QString::fromUtf8("pushButtonEswitchWindowOff"));
        pushButtonEswitchWindowOff->setGeometry(QRect(30, 80, 98, 27));
        pushButtonEswitchWindowOn = new QPushButton(eSwitchWindow);
        pushButtonEswitchWindowOn->setObjectName(QString::fromUtf8("pushButtonEswitchWindowOn"));
        pushButtonEswitchWindowOn->setGeometry(QRect(30, 20, 98, 27));

        retranslateUi(eSwitchWindow);

        QMetaObject::connectSlotsByName(eSwitchWindow);
    } // setupUi

    void retranslateUi(QDialog *eSwitchWindow)
    {
        eSwitchWindow->setWindowTitle(QApplication::translate("eSwitchWindow", "eSwitch", 0, QApplication::UnicodeUTF8));
        pushButtonEswitchWindowOff->setText(QApplication::translate("eSwitchWindow", "\320\222\321\213\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        pushButtonEswitchWindowOn->setText(QApplication::translate("eSwitchWindow", "\320\222\320\272\320\273\321\216\321\207\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class eSwitchWindow: public Ui_eSwitchWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ESWITCHWINDOW_H
