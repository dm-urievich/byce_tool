/****************************************************************************
** Meta object code from reading C++ file 'eswitchwindow.h'
**
** Created: Tue Jul 2 00:13:19 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eswitchwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eswitchwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_eSwitchWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x05,
      26,   14,   14,   14, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_eSwitchWindow[] = {
    "eSwitchWindow\0\0switchOn()\0switchOff()\0"
};

void eSwitchWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        eSwitchWindow *_t = static_cast<eSwitchWindow *>(_o);
        switch (_id) {
        case 0: _t->switchOn(); break;
        case 1: _t->switchOff(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData eSwitchWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject eSwitchWindow::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_eSwitchWindow,
      qt_meta_data_eSwitchWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &eSwitchWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *eSwitchWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *eSwitchWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_eSwitchWindow))
        return static_cast<void*>(const_cast< eSwitchWindow*>(this));
    return QDialog::qt_metacast(_clname);
}

int eSwitchWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void eSwitchWindow::switchOn()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void eSwitchWindow::switchOff()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
