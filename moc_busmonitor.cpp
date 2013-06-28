/****************************************************************************
** Meta object code from reading C++ file 'busmonitor.h'
**
** Created: Wed Jun 5 20:48:47 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "3rdparty/qModMaster/busmonitor.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'busmonitor.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_BusMonitor[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      20,   11,   11,   11, 0x08,
      27,   11,   11,   11, 0x08,
      37,   34,   11,   11, 0x08,
      62,   53,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_BusMonitor[] = {
    "BusMonitor\0\0clear()\0exit()\0save()\0en\0"
    "startStop(bool)\0selected\0"
    "selectedRow(QModelIndex)\0"
};

void BusMonitor::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        BusMonitor *_t = static_cast<BusMonitor *>(_o);
        switch (_id) {
        case 0: _t->clear(); break;
        case 1: _t->exit(); break;
        case 2: _t->save(); break;
        case 3: _t->startStop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->selectedRow((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData BusMonitor::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject BusMonitor::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_BusMonitor,
      qt_meta_data_BusMonitor, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &BusMonitor::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *BusMonitor::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *BusMonitor::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_BusMonitor))
        return static_cast<void*>(const_cast< BusMonitor*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int BusMonitor::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
