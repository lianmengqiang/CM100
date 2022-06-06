/****************************************************************************
** Meta object code from reading C++ file 'widSetting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widSetting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widSetting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_widSetting_t {
    QByteArrayData data[11];
    char stringdata[121];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_widSetting_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_widSetting_t qt_meta_stringdata_widSetting = {
    {
QT_MOC_LITERAL(0, 0, 10), // "widSetting"
QT_MOC_LITERAL(1, 11, 17), // "signReLoginCamera"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 9), // "ipAddress"
QT_MOC_LITERAL(4, 40, 4), // "port"
QT_MOC_LITERAL(5, 45, 8), // "userName"
QT_MOC_LITERAL(6, 54, 7), // "userPwd"
QT_MOC_LITERAL(7, 62, 12), // "signReListen"
QT_MOC_LITERAL(8, 75, 20), // "signReConnectBattery"
QT_MOC_LITERAL(9, 96, 13), // "slotSaveParam"
QT_MOC_LITERAL(10, 110, 10) // "slotCancel"

    },
    "widSetting\0signReLoginCamera\0\0ipAddress\0"
    "port\0userName\0userPwd\0signReListen\0"
    "signReConnectBattery\0slotSaveParam\0"
    "slotCancel"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_widSetting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   39,    2, 0x06 /* Public */,
       7,    1,   48,    2, 0x06 /* Public */,
       8,    0,   51,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   52,    2, 0x08 /* Private */,
      10,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void widSetting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        widSetting *_t = static_cast<widSetting *>(_o);
        switch (_id) {
        case 0: _t->signReLoginCamera((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->signReListen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->signReConnectBattery(); break;
        case 3: _t->slotSaveParam(); break;
        case 4: _t->slotCancel(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (widSetting::*_t)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&widSetting::signReLoginCamera)) {
                *result = 0;
            }
        }
        {
            typedef void (widSetting::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&widSetting::signReListen)) {
                *result = 1;
            }
        }
        {
            typedef void (widSetting::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&widSetting::signReConnectBattery)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject widSetting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_widSetting.data,
      qt_meta_data_widSetting,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *widSetting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *widSetting::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_widSetting.stringdata))
        return static_cast<void*>(const_cast< widSetting*>(this));
    return QDialog::qt_metacast(_clname);
}

int widSetting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void widSetting::signReLoginCamera(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void widSetting::signReListen(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void widSetting::signReConnectBattery()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
