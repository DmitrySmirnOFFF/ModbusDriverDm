/****************************************************************************
** Meta object code from reading C++ file 'ModbusClient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ModbusClient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModbusClient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusClient_t {
    QByteArrayData data[13];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusClient_t qt_meta_stringdata_ModbusClient = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ModbusClient"
QT_MOC_LITERAL(1, 13, 13), // "slotClientErr"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 20), // "QModbusDevice::Error"
QT_MOC_LITERAL(4, 49, 5), // "error"
QT_MOC_LITERAL(5, 55, 16), // "slotStateChanged"
QT_MOC_LITERAL(6, 72, 20), // "QModbusDevice::State"
QT_MOC_LITERAL(7, 93, 5), // "state"
QT_MOC_LITERAL(8, 99, 21), // "slotConnectMonitorTim"
QT_MOC_LITERAL(9, 121, 5), // "start"
QT_MOC_LITERAL(10, 127, 4), // "stop"
QT_MOC_LITERAL(11, 132, 6), // "socket"
QT_MOC_LITERAL(12, 139, 12) // "responseTime"

    },
    "ModbusClient\0slotClientErr\0\0"
    "QModbusDevice::Error\0error\0slotStateChanged\0"
    "QModbusDevice::State\0state\0"
    "slotConnectMonitorTim\0start\0stop\0"
    "socket\0responseTime"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       2,   48, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x08 /* Private */,
       5,    1,   42,    2, 0x08 /* Private */,
       8,    0,   45,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   46,    2, 0x02 /* Public */,
      10,    0,   47,    2, 0x02 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00095103,
      12, QMetaType::Int, 0x00095103,

       0        // eod
};

void ModbusClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusClient *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->slotClientErr((*reinterpret_cast< QModbusDevice::Error(*)>(_a[1]))); break;
        case 1: _t->slotStateChanged((*reinterpret_cast< QModbusDevice::State(*)>(_a[1]))); break;
        case 2: _t->slotConnectMonitorTim(); break;
        case 3: _t->start(); break;
        case 4: _t->stop(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ModbusClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->socket(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->responseTime(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ModbusClient *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setSocket(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setResponseTime(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ModbusClient::staticMetaObject = { {
    &BaseObject::staticMetaObject,
    qt_meta_stringdata_ModbusClient.data,
    qt_meta_data_ModbusClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModbusClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusClient.stringdata0))
        return static_cast<void*>(this);
    return BaseObject::qt_metacast(_clname);
}

int ModbusClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
