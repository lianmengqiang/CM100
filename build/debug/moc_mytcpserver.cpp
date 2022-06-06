/****************************************************************************
** Meta object code from reading C++ file 'mytcpserver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mytcpserver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mytcpserver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyTCPServer_t {
    QByteArrayData data[9];
    char stringdata[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyTCPServer_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyTCPServer_t qt_meta_stringdata_MyTCPServer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MyTCPServer"
QT_MOC_LITERAL(1, 12, 12), // "signRecvData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "ip"
QT_MOC_LITERAL(4, 29, 4), // "port"
QT_MOC_LITERAL(5, 34, 4), // "mesg"
QT_MOC_LITERAL(6, 39, 13), // "signTransData"
QT_MOC_LITERAL(7, 53, 19), // "signTransDataString"
QT_MOC_LITERAL(8, 73, 14) // "signDisconnect"

    },
    "MyTCPServer\0signRecvData\0\0ip\0port\0"
    "mesg\0signTransData\0signTransDataString\0"
    "signDisconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyTCPServer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   44,    2, 0x06 /* Public */,
       6,    1,   51,    2, 0x06 /* Public */,
       6,    3,   54,    2, 0x06 /* Public */,
       7,    1,   61,    2, 0x06 /* Public */,
       8,    0,   64,    2, 0x06 /* Public */,
       8,    2,   65,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QByteArray,    3,    4,    5,
    QMetaType::Void, QMetaType::QByteArray,    5,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QByteArray,    3,    4,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

       0        // eod
};

void MyTCPServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyTCPServer *_t = static_cast<MyTCPServer *>(_o);
        switch (_id) {
        case 0: _t->signRecvData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 1: _t->signTransData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 2: _t->signTransData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 3: _t->signTransDataString((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->signDisconnect(); break;
        case 5: _t->signDisconnect((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyTCPServer::*_t)(QString , int , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTCPServer::signRecvData)) {
                *result = 0;
            }
        }
        {
            typedef void (MyTCPServer::*_t)(QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTCPServer::signTransData)) {
                *result = 1;
            }
        }
        {
            typedef void (MyTCPServer::*_t)(QString , int , QByteArray );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTCPServer::signTransData)) {
                *result = 2;
            }
        }
        {
            typedef void (MyTCPServer::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTCPServer::signTransDataString)) {
                *result = 3;
            }
        }
        {
            typedef void (MyTCPServer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTCPServer::signDisconnect)) {
                *result = 4;
            }
        }
        {
            typedef void (MyTCPServer::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyTCPServer::signDisconnect)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject MyTCPServer::staticMetaObject = {
    { &QTcpServer::staticMetaObject, qt_meta_stringdata_MyTCPServer.data,
      qt_meta_data_MyTCPServer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyTCPServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyTCPServer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyTCPServer.stringdata))
        return static_cast<void*>(const_cast< MyTCPServer*>(this));
    return QTcpServer::qt_metacast(_clname);
}

int MyTCPServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTcpServer::qt_metacall(_c, _id, _a);
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
void MyTCPServer::signRecvData(QString _t1, int _t2, QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyTCPServer::signTransData(QByteArray _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyTCPServer::signTransData(QString _t1, int _t2, QByteArray _t3)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyTCPServer::signTransDataString(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyTCPServer::signDisconnect()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void MyTCPServer::signDisconnect(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
