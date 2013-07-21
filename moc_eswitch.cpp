/****************************************************************************
** Meta object code from reading C++ file 'eswitch.h'
**
** Created: Thu Jul 18 22:05:16 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "eswitch.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eswitch.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_eSwitch[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
       9,    8,    8,    8, 0x05,
      20,    8,    8,    8, 0x05,

 // slots: signature, parameters, type, tag, flags
      30,    8,    8,    8, 0x0a,
      35,    8,    8,    8, 0x0a,
      41,    8,    8,    8, 0x08,
      59,    8,    8,    8, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_eSwitch[] = {
    "eSwitch\0\0dInRaise()\0dInFall()\0on()\0"
    "off()\0mainButtonClick()\0readTimerEvent()\0"
};

void eSwitch::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        eSwitch *_t = static_cast<eSwitch *>(_o);
        switch (_id) {
        case 0: _t->dInRaise(); break;
        case 1: _t->dInFall(); break;
        case 2: _t->on(); break;
        case 3: _t->off(); break;
        case 4: _t->mainButtonClick(); break;
        case 5: _t->readTimerEvent(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData eSwitch::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject eSwitch::staticMetaObject = {
    { &Hardware::staticMetaObject, qt_meta_stringdata_eSwitch,
      qt_meta_data_eSwitch, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &eSwitch::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *eSwitch::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *eSwitch::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_eSwitch))
        return static_cast<void*>(const_cast< eSwitch*>(this));
    return Hardware::qt_metacast(_clname);
}

int eSwitch::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Hardware::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void eSwitch::dInRaise()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void eSwitch::dInFall()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
