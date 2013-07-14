#include "hardwaresettingsdialog.h"

HardwareSettingsDialog::HardwareSettingsDialog(QWidget *parent, QString file, Hardware *module) :
    QDialog(parent),
    descriptorFile(file)
{
    hardwareModule = module;

    readDescriptorFromFile(descriptorFile);
    refreshRegisters();

    buttonOk = new QPushButton(this);
    buttonCancel = new QPushButton(this);

    buttonOk->resize(100, 25);
    buttonOk->setText(QString::fromLocal8Bit("Применить"));

    buttonCancel->resize(100, 25);
    buttonCancel->setText(QString::fromLocal8Bit("Отмена"));
    connect(buttonOk, SIGNAL(clicked()), this, SLOT(applySettings()));
    connect(buttonCancel, SIGNAL(clicked()), this, SLOT(cancelSettings()));

    // отрисовка найденых регистров на форме
    QVector<ModbusRegister*>::Iterator reg = registerVector.begin();
    int yPos = 10;
    int yStep = 30;
    int labelXsize = 200;
    int labelYsize = 25;
    int lineEditXsize = 150;
    int xDistance = 20;
    for (reg = registerVector.begin(); reg != registerVector.end(); ++reg) {
        if ((*reg)->getType() == ModbusRegister::reservType)
            continue;

        QLabel* text = new QLabel(this);

        text->show();
        text->move(5, yPos);
        text->resize(labelXsize, labelYsize);
        text->setText((*reg)->name);

        labelVector.push_back(text);

        switch ((*reg)->getType()) {
        case ModbusRegister::intType : {
                QLineEdit* edit = new QLineEdit(this);

                edit->move(labelXsize + xDistance, yPos);
                edit->resize(lineEditXsize, labelYsize);
                edit->setText(QString::number((*reg)->getData()));
                edit->show();
                lineeditVector.push_back(edit);
            }
            break;
        case ModbusRegister::textType : {
                QComboBox *box = new QComboBox(this);

                // заполняем список фозможными значениями
                int nText = (*reg)->stringText_.size();
                for (int j = 0; j < nText; j++) {
                    box->addItem((*reg)->stringText_[j]);
                }
                box->setCurrentIndex((*reg)->getData());
                // пихаем на форму
                box->move(labelXsize + xDistance, yPos);
                box->resize(lineEditXsize, labelYsize);
                box->show();
                boxVector.push_back(box);
            }
            break;
        default : break;
        }

        yPos += yStep;
    }

    yPos += yStep;
    buttonOk->move(400 - 100 - (400 - xDistance - labelXsize - lineEditXsize), yPos); // это придумал мой пьяный мозг, на самом деле нужно просто добавить компоновщик
    buttonCancel->move(400 - 100 - xDistance - 100 - (400 - xDistance - labelXsize - lineEditXsize), yPos);
    buttonCancel->show();
    buttonOk->show();
    yPos += yStep;

    this->resize(400, yPos + 25);
    this->exec();
}

void HardwareSettingsDialog::applySettings()
{
    QVector<ModbusRegister*>::Iterator reg = registerVector.begin();
    QVector<QComboBox*>::Iterator box = boxVector.begin();
    QVector<QLineEdit*>::Iterator lineedit = lineeditVector.begin();

    for (reg = registerVector.begin(); reg != registerVector.end(); ++reg) {
        if ((*reg)->getType() == ModbusRegister::reservType)
            continue;

        switch ((*reg)->getType()) {
        case ModbusRegister::intType : {
                (*reg)->setData((*lineedit)->text().toInt());
                hardwareModule->writeReg(*(*reg));
                ++lineedit;
            }
            break;
        case ModbusRegister::textType : {
                (*reg)->setData((*box)->currentIndex());
                hardwareModule->writeReg(*(*reg));
                ++box;
            }
            break;
        default : break;
        }
    }
}


void HardwareSettingsDialog::cancelSettings()
{

}

void HardwareSettingsDialog::refreshRegisters()
{
    QVector<ModbusRegister*>::Iterator reg = registerVector.begin();
    // Вычитака данных (обновление инфы)
    for (; reg != registerVector.end(); ++reg) {
        if ((*reg)->getType() != ModbusRegister::reservType) {
            hardwareModule->readReg(*(*reg));
        }
    }
}

void HardwareSettingsDialog::readDescriptorFromFile(QString fileName)
{
    QString fileString;
    QFile dataFile(fileName);
    dataFile.open(QIODevice::ReadOnly);
    QTextStream file(&dataFile);
    int addrReg = 0;
    int regType;

    while (!file.atEnd()) {
        fileString = file.readLine();
        // ищем начало таблицы регистров
        if (fileString.contains("modbusReg_type"))
            break;
    }

    // дальше пошла таблица с регистрами
    while (!file.atEnd()) {
        int index;
        fileString = file.readLine();

        // конец таблицы
        if (fileString.contains("};")) {
            break;
        }

        // проверям это строка с регистром или так просто
        // в соответсвии с сруктурой регистров в девайсе мы ищем такую строку
        // {бла,бла,бла,бла,бла,бла}, - это условия для элемента масива
        if (isRegDeclarationString(fileString))
            addrReg++;

        // есть ли комментарии
        if (fileString.contains("//")) {
            // мочим все что до комменнта
            index = fileString.indexOf("//");
            fileString.remove(0, index + 2);

            regType = getRegisterType(fileString);

            // строка объявление регистра
            if (regType != -1) {
                ModbusRegister* reg = new ModbusRegister;
                reg->name = fileString;
                reg->addr = addrReg - 1;
                reg->setType(regType);

                registerVector.push_back(reg);
            }
            else { // вероятно значение текстового поля
                if (registerVector.back()->isTextType()) {
                    QString number;
                    int val;

                    index = fileString.indexOf('-');
                    number = fileString;
                    number.remove(index, number.length() - index);

                    fileString.remove(0, index + 2);
                    val = number.toInt();

                    registerVector.back()->addTextVal(val, fileString);
                }
            }
        }
    }
}

// проверка я вляется ли строка элементом массива регистров
bool HardwareSettingsDialog::isRegDeclarationString(QString& str)
{
    int p = 0;

    p = str.indexOf('{');
    if (p == -1) {
        return false;
    }

    // указатель на переменную
    p = str.indexOf(',', p + 1);
    if (p == -1)
        return false;

    // нижний предел
    p = str.indexOf(',', p + 1);
    if (p == -1)
        return false;

    // верхний предел
    p = str.indexOf(',', p + 1);
    if (p == -1)
        return false;

    // режим доступа
    p = str.indexOf(',', p + 1);
    if (p == -1)
        return false;

    // энергонезависимость
    p = str.indexOf(',', p + 1);
    if (p == -1)
        return false;

    // значение по умолчанию
    p = str.indexOf('}', p + 1);
    if (p == -1)
        return false;

    // конец объявления
    p = str.indexOf(',', p + 1);
    if (p == -1)
        return false;

    return true;
}

// узнать какого типа строка
int HardwareSettingsDialog::getRegisterType(QString &str)
{
    int p;

    p = str.indexOf("Text", Qt::CaseInsensitive);
    if (p != -1) {
        str.remove(p, 4);
        return ModbusRegister::textType;
    }

    p = str.indexOf("Int", Qt::CaseInsensitive);
    if (p != -1) {
        str.remove(p, 3);
        return ModbusRegister::intType;
    }

    p = str.indexOf("Hex", Qt::CaseInsensitive);
    if (p != -1) {
        str.remove(p, 3);
        return ModbusRegister::hexType;
    }

    p = str.indexOf("Reserv", Qt::CaseInsensitive);
    if (p != -1) {
        str.remove(p, 6);
        return ModbusRegister::reservType;
    }

    return -1;
}
