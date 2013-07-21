/****************************************************************************
** Meta object code from reading C++ file 'windowoptions.h'
**
** Created: Thu Jul 18 22:05:10 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "windowoptions.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'windowoptions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_windowOptions[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      15,   14,   14,   14, 0x08,
      42,   14,   14,   14, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_windowOptions[] = {
    "windowOptions\0\0buttonApplayOptionsClick()\0"
    "buttonCancelClick()\0"
};

void windowOptions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        windowOptions *_t = static_cast<windowOptions *>(_o);
        switch (_id) {
        case 0: _t->buttonApplayOptionsClick(); break;
        case 1: _t->buttonCancelClick(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData windowOptions::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject windowOptions::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_windowOptions,
      qt_meta_data_windowOptions, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &windowOptions::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *windowOptions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *windowOptions::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_windowOptions))
        return static_cast<void*>(const_cast< windowOptions*>(this));
    return QDialog::qt_metacast(_clname);
}

int windowOptions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
