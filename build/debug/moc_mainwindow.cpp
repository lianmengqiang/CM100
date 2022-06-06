/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[27];
    char stringdata[380];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 13), // "signalReStart"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "ipAddress"
QT_MOC_LITERAL(4, 36, 4), // "port"
QT_MOC_LITERAL(5, 41, 8), // "userName"
QT_MOC_LITERAL(6, 50, 7), // "userPwd"
QT_MOC_LITERAL(7, 58, 15), // "signalStartBase"
QT_MOC_LITERAL(8, 74, 2), // "va"
QT_MOC_LITERAL(9, 77, 8), // "slotExit"
QT_MOC_LITERAL(10, 86, 11), // "slotSetting"
QT_MOC_LITERAL(11, 98, 18), // "slotHikvisionLogin"
QT_MOC_LITERAL(12, 117, 19), // "slotHikvisionLogout"
QT_MOC_LITERAL(13, 137, 12), // "slotRecvData"
QT_MOC_LITERAL(14, 150, 2), // "ip"
QT_MOC_LITERAL(15, 153, 4), // "data"
QT_MOC_LITERAL(16, 158, 12), // "slotReListen"
QT_MOC_LITERAL(17, 171, 20), // "slotReConnectBattery"
QT_MOC_LITERAL(18, 192, 18), // "on_ptb_std_clicked"
QT_MOC_LITERAL(19, 211, 20), // "on_actFile_triggered"
QT_MOC_LITERAL(20, 232, 20), // "on_ptb_lower_clicked"
QT_MOC_LITERAL(21, 253, 18), // "on_ptb_led_clicked"
QT_MOC_LITERAL(22, 272, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(23, 294, 22), // "on_act_lower_triggered"
QT_MOC_LITERAL(24, 317, 23), // "on_act_camera_triggered"
QT_MOC_LITERAL(25, 341, 21), // "on_ptb_camStu_clicked"
QT_MOC_LITERAL(26, 363, 16) // "slot_TimeBattery"

    },
    "MainWindow\0signalReStart\0\0ipAddress\0"
    "port\0userName\0userPwd\0signalStartBase\0"
    "va\0slotExit\0slotSetting\0slotHikvisionLogin\0"
    "slotHikvisionLogout\0slotRecvData\0ip\0"
    "data\0slotReListen\0slotReConnectBattery\0"
    "on_ptb_std_clicked\0on_actFile_triggered\0"
    "on_ptb_lower_clicked\0on_ptb_led_clicked\0"
    "on_pushButton_clicked\0on_act_lower_triggered\0"
    "on_act_camera_triggered\0on_ptb_camStu_clicked\0"
    "slot_TimeBattery"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,  104,    2, 0x06 /* Public */,
       7,    1,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,  116,    2, 0x08 /* Private */,
      10,    0,  117,    2, 0x08 /* Private */,
      11,    0,  118,    2, 0x08 /* Private */,
      12,    0,  119,    2, 0x08 /* Private */,
      13,    3,  120,    2, 0x08 /* Private */,
      16,    1,  127,    2, 0x08 /* Private */,
      17,    0,  130,    2, 0x08 /* Private */,
      18,    0,  131,    2, 0x08 /* Private */,
      19,    0,  132,    2, 0x08 /* Private */,
      20,    0,  133,    2, 0x08 /* Private */,
      21,    0,  134,    2, 0x08 /* Private */,
      22,    0,  135,    2, 0x08 /* Private */,
      23,    0,  136,    2, 0x08 /* Private */,
      24,    0,  137,    2, 0x08 /* Private */,
      25,    0,  138,    2, 0x08 /* Private */,
      26,    0,  139,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::Double,    8,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString, QMetaType::Int, QMetaType::QByteArray,   14,    4,   15,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->signalReStart((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->signalStartBase((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->slotExit(); break;
        case 3: _t->slotSetting(); break;
        case 4: _t->slotHikvisionLogin(); break;
        case 5: _t->slotHikvisionLogout(); break;
        case 6: _t->slotRecvData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QByteArray(*)>(_a[3]))); break;
        case 7: _t->slotReListen((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->slotReConnectBattery(); break;
        case 9: _t->on_ptb_std_clicked(); break;
        case 10: _t->on_actFile_triggered(); break;
        case 11: _t->on_ptb_lower_clicked(); break;
        case 12: _t->on_ptb_led_clicked(); break;
        case 13: _t->on_pushButton_clicked(); break;
        case 14: _t->on_act_lower_triggered(); break;
        case 15: _t->on_act_camera_triggered(); break;
        case 16: _t->on_ptb_camStu_clicked(); break;
        case 17: _t->slot_TimeBattery(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MainWindow::*_t)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalReStart)) {
                *result = 0;
            }
        }
        {
            typedef void (MainWindow::*_t)(double );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::signalStartBase)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}

// SIGNAL 0
void MainWindow::signalReStart(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow::signalStartBase(double _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
