/****************************************************************************
** Meta object code from reading C++ file 'ModbusTag.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ModbusTag.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ModbusTag.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ModbusTag_t {
    QByteArrayData data[12];
    char stringdata0[128];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ModbusTag_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ModbusTag_t qt_meta_stringdata_ModbusTag = {
    {
QT_MOC_LITERAL(0, 0, 9), // "ModbusTag"
QT_MOC_LITERAL(1, 10, 12), // "valueChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 15), // "signalEventList"
QT_MOC_LITERAL(4, 40, 19), // "slotRequestComplete"
QT_MOC_LITERAL(5, 60, 7), // "request"
QT_MOC_LITERAL(6, 68, 14), // "ModbusRequest*"
QT_MOC_LITERAL(7, 83, 5), // "value"
QT_MOC_LITERAL(8, 89, 6), // "adress"
QT_MOC_LITERAL(9, 96, 8), // "adressHi"
QT_MOC_LITERAL(10, 105, 9), // "eventList"
QT_MOC_LITERAL(11, 115, 12) // "historyCount"

    },
    "ModbusTag\0valueChanged\0\0signalEventList\0"
    "slotRequestComplete\0request\0ModbusRequest*\0"
    "value\0adress\0adressHi\0eventList\0"
    "historyCount"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ModbusTag[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       6,   32, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x06 /* Public */,
       3,    0,   30,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   31,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,

 // properties: name, type, flags
       5, 0x80000000 | 6, 0x0009510b,
       7, QMetaType::UInt, 0x00495103,
       8, QMetaType::QString, 0x00095103,
       9, QMetaType::QString, 0x00095103,
      10, QMetaType::Bool, 0x00095103,
      11, QMetaType::Int, 0x00095103,

 // properties: notify_signal_id
       0,
       0,
       0,
       0,
       0,
       0,

       0        // eod
};

void ModbusTag::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ModbusTag *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged(); break;
        case 1: _t->signalEventList(); break;
        case 2: _t->slotRequestComplete(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ModbusTag::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusTag::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ModbusTag::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ModbusTag::signalEventList)) {
                *result = 1;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ModbusRequest* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ModbusTag *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< ModbusRequest**>(_v) = _t->request(); break;
        case 1: *reinterpret_cast< uint*>(_v) = _t->value(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->adress(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->adressHi(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->eventList(); break;
        case 5: *reinterpret_cast< int*>(_v) = _t->historyCount(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ModbusTag *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setRequest(*reinterpret_cast< ModbusRequest**>(_v)); break;
        case 1: _t->setValue(*reinterpret_cast< uint*>(_v)); break;
        case 2: _t->setAdress(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setAdressHi(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setEventList(*reinterpret_cast< bool*>(_v)); break;
        case 5: _t->setHistoryCount(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ModbusTag::staticMetaObject = { {
    &BaseObject::staticMetaObject,
    qt_meta_stringdata_ModbusTag.data,
    qt_meta_data_ModbusTag,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ModbusTag::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ModbusTag::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ModbusTag.stringdata0))
        return static_cast<void*>(this);
    return BaseObject::qt_metacast(_clname);
}

int ModbusTag::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = BaseObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ModbusTag::valueChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ModbusTag::signalEventList()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
