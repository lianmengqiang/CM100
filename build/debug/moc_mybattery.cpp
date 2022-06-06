/****************************************************************************
** Meta object code from reading C++ file 'mybattery.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mybattery.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mybattery.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyBattery_t {
    QByteArrayData data[5];
    char stringdata[67];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyBattery_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyBattery_t qt_meta_stringdata_MyBattery = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MyBattery"
QT_MOC_LITERAL(1, 10, 9), // "slotStart"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 24), // "slot_startConnectBattery"
QT_MOC_LITERAL(4, 46, 20) // "slotReConnectBattery"

    },
    "MyBattery\0slotStart\0\0slot_startConnectBattery\0"
    "slotReConnectBattery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyBattery[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x0a /* Public */,
       3,    0,   30,    2, 0x08 /* Private */,
       4,    0,   31,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MyBattery::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyBattery *_t = static_cast<MyBattery *>(_o);
        switch (_id) {
        case 0: _t->slotStart(); break;
        case 1: _t->slot_startConnectBattery(); break;
        case 2: _t->slotReConnectBattery(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject MyBattery::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyBattery.data,
      qt_meta_data_MyBattery,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyBattery::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyBattery::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyBattery.stringdata))
        return static_cast<void*>(const_cast< MyBattery*>(this));
    return QObject::qt_metacast(_clname);
}

int MyBattery::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
