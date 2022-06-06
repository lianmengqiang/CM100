/****************************************************************************
** Meta object code from reading C++ file 'cameraconnectthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../cameraconnectthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'cameraconnectthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraConnectThread_t {
    QByteArrayData data[12];
    char stringdata[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraConnectThread_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraConnectThread_t qt_meta_stringdata_CameraConnectThread = {
    {
QT_MOC_LITERAL(0, 0, 19), // "CameraConnectThread"
QT_MOC_LITERAL(1, 20, 11), // "signalLogin"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 12), // "signalLogout"
QT_MOC_LITERAL(4, 46, 9), // "slotStart"
QT_MOC_LITERAL(5, 56, 11), // "slotReStart"
QT_MOC_LITERAL(6, 68, 9), // "ipAddress"
QT_MOC_LITERAL(7, 78, 4), // "port"
QT_MOC_LITERAL(8, 83, 8), // "userName"
QT_MOC_LITERAL(9, 92, 7), // "userPwd"
QT_MOC_LITERAL(10, 100, 16), // "onConnectTimeout"
QT_MOC_LITERAL(11, 117, 12) // "onTcpTimeout"

    },
    "CameraConnectThread\0signalLogin\0\0"
    "signalLogout\0slotStart\0slotReStart\0"
    "ipAddress\0port\0userName\0userPwd\0"
    "onConnectTimeout\0onTcpTimeout"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraConnectThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   46,    2, 0x0a /* Public */,
       5,    4,   47,    2, 0x0a /* Public */,
      10,    0,   56,    2, 0x0a /* Public */,
      11,    0,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    6,    7,    8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CameraConnectThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraConnectThread *_t = static_cast<CameraConnectThread *>(_o);
        switch (_id) {
        case 0: _t->signalLogin(); break;
        case 1: _t->signalLogout(); break;
        case 2: _t->slotStart(); break;
        case 3: _t->slotReStart((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 4: _t->onConnectTimeout(); break;
        case 5: _t->onTcpTimeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraConnectThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraConnectThread::signalLogin)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraConnectThread::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraConnectThread::signalLogout)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CameraConnectThread::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraConnectThread.data,
      qt_meta_data_CameraConnectThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraConnectThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraConnectThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraConnectThread.stringdata))
        return static_cast<void*>(const_cast< CameraConnectThread*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraConnectThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void CameraConnectThread::signalLogin()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CameraConnectThread::signalLogout()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
