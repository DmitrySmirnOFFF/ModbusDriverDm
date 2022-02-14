/****************************************************************************
** Meta object code from reading C++ file 'ModbusRequest.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ModbusRequest.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModbusRequest.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusRequest_t {
    QByteArrayData data[17];
    char stringdata0[209];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusRequest_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusRequest_t qt_meta_stringdata_ModbusRequest = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ModbusRequest"
QT_MOC_LITERAL(1, 14, 12), // "requestReady"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 10), // "regChanged"
QT_MOC_LITERAL(4, 39, 15), // "quantityChanged"
QT_MOC_LITERAL(5, 55, 12), // "slaveChanged"
QT_MOC_LITERAL(6, 68, 15), // "periodRxChanged"
QT_MOC_LITERAL(7, 84, 15), // "periodTxChanged"
QT_MOC_LITERAL(8, 100, 16), // "slotRequestRxTim"
QT_MOC_LITERAL(9, 117, 16), // "slotRequestTxTim"
QT_MOC_LITERAL(10, 134, 18), // "slotRequestRxReady"
QT_MOC_LITERAL(11, 153, 18), // "slotRequestTxReady"
QT_MOC_LITERAL(12, 172, 3), // "reg"
QT_MOC_LITERAL(13, 176, 8), // "quantity"
QT_MOC_LITERAL(14, 185, 5), // "slave"
QT_MOC_LITERAL(15, 191, 8), // "periodRx"
QT_MOC_LITERAL(16, 200, 8) // "periodTx"

    },
    "ModbusRequest\0requestReady\0\0regChanged\0"
    "quantityChanged\0slaveChanged\0"
    "periodRxChanged\0periodTxChanged\0"
    "slotRequestRxTim\0slotRequestTxTim\0"
    "slotRequestRxReady\0slotRequestTxReady\0"
    "reg\0quantity\0slave\0periodRx\0periodTx"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusRequest[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       5,   74, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x06 /* Public */,
       3,    0,   65,    2, 0x06 /* Public */,
       4,    0,   66,    2, 0x06 /* Public */,
       5,    0,   67,    2, 0x06 /* Public */,
       6,    0,   68,    2, 0x06 /* Public */,
       7,    0,   69,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
      12, QMetaType::Int, 0x00495103,
      13, QMetaType::Int, 0x00495103,
      14, QMetaType::Int, 0x00495103,
      15, QMetaType::Int, 0x00495103,
      16, QMetaType::Int, 0x00495103,

 // properties: notify_signal_id
       1,
       2,
       3,
       4,
       5,

       0        // eod
};

void ModbusRequest::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusRequest *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestReady(); break;
        case 1: _t->regChanged(); break;
        case 2: _t->quantityChanged(); break;
        case 3: _t->slaveChanged(); break;
        case 4: _t->periodRxChanged(); break;
        case 5: _t->periodTxChanged(); break;
        case 6: _t->slotRequestRxTim(); break;
        case 7: _t->slotRequestTxTim(); break;
        case 8: _t->slotRequestRxReady(); break;
        case 9: _t->slotRequestTxReady(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModbusRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRequest::requestReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModbusRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRequest::regChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ModbusRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRequest::quantityChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ModbusRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRequest::slaveChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ModbusRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRequest::periodRxChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (ModbusRequest::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusRequest::periodTxChanged)) {
                *result = 5;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ModbusRequest *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = _t->reg(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->quantity(); break;
        case 2: *reinterpret_cast< int*>(_v) = _t->slave(); break;
        case 3: *reinterpret_cast< int*>(_v) = _t->periodRx(); break;
        case 4: *reinterpret_cast< int*>(_v) = _t->periodTx(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ModbusRequest *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setReg(*reinterpret_cast< int*>(_v)); break;
        case 1: _t->setQuantity(*reinterpret_cast< int*>(_v)); break;
        case 2: _t->setSlave(*reinterpret_cast< int*>(_v)); break;
        case 3: _t->setPeriodRx(*reinterpret_cast< int*>(_v)); break;
        case 4: _t->setPeriodTx(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ModbusRequest::staticMetaObject = { {
    &BaseObject::staticMetaObject,
    qt_meta_stringdata_ModbusRequest.data,
    qt_meta_data_ModbusRequest,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModbusRequest::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusRequest::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusRequest.stringdata0))
        return static_cast<void*>(this);
    return BaseObject::qt_metacast(_clname);
}

int ModbusRequest::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ModbusRequest::requestReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ModbusRequest::regChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ModbusRequest::quantityChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ModbusRequest::slaveChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ModbusRequest::periodRxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void ModbusRequest::periodTxChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
