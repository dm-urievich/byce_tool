#include "corebycetoolthread.h"

CoreByceToolThread::CoreByceToolThread(QObject *parent) :
    QThread(parent)
{
    transferHardwareModules = new TransferThread(&hardwareVector, &lockHardwareVector);

    connect(transferHardwareModules, SIGNAL(eventInModule(bool)), this, SLOT(generateXmlHardware(bool)));
    connect(this, SIGNAL(setTransferPeriod(int)), transferHardwareModules, SLOT(setPeriod(int)));
}

void CoreByceToolThread::run()
{
    transferHardwareModules->start();

    this->exec();
}

void CoreByceToolThread::createNewHardwareModule(Hardware *device)
{
    QMutexLocker locker(&lockHardwareVector);

    device->moveToThread(transferHardwareModules);
    hardwareVector.push_back(device);
}

void CoreByceToolThread::generateXmlHardware(bool isEvent)
{
    QVector<Hardware*>::Iterator device;

    QFile outFile("moduleEvents.xml");
    if (outFile.open(QIODevice::WriteOnly)) {
        QTextStream out(&outFile);
        out.setCodec("UTF-8");
        out << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>\n";
        out << "<module>\n";

        lockHardwareVector.lock();
        for (device = hardwareVector.begin(); device != hardwareVector.end(); ++device) {
            if (isEvent) {
                if ((*device)->isEvent()) {
                    (*device)->generateXml(out);
                }
            }
            else {
                (*device)->generateXml(out);        // для инициализации Gui, генерим состояние всех девайсов
            }
        }
        lockHardwareVector.unlock();

        out << "</module>\n";
        outFile.close();

        emit guiRefresh();
    }
}

void CoreByceToolThread::parseSockets()
{
    QDomDocument doc("module");
    QFile inFile("moduleSockets.xml");
    QString errorParse;
    QVector<Hardware*>::iterator module; //= hardwareVector.begin();
    int errorLine;
    int idModule = 0;

    if (!inFile.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&inFile, &errorParse, &errorLine)) {
        qDebug() << "Error: " << errorParse;
        qDebug() << "in line: " << errorLine << endl;
        inFile.close();
        return;
    }
    inFile.close();

    // печатает имена всех непосредственных потомков
    // внешнего элемента.
    QDomElement docElem = doc.documentElement();

    lockHardwareVector.lock();
    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // пробуем преобразовать узел в элемент.
        if(!e.isNull()) {
            //qDebug() << e.tagName() << '\n'; // узел действительно является элементом.
            //qDebug() << "attr: " << e.attribute("id") << '\n';
            idModule = e.attribute("id").toInt();
            if (idModule) {
                 // удобнее это вынести в функцию
                for (module = hardwareVector.begin(); module != hardwareVector.end(); ++module) {
                    if ((*module)->idModule == idModule) {
                        (*module)->parseXml(e);
                    }
                }
            }
        }
        n = n.nextSibling();
    }
    lockHardwareVector.unlock();
}
