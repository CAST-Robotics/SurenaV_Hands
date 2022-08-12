/****************************************************************************
** Meta object code from reading C++ file 'epos.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/epos.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'epos.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Epos_t {
    QByteArrayData data[16];
    char stringdata0[176];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Epos_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Epos_t qt_meta_stringdata_Epos = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Epos"
QT_MOC_LITERAL(1, 5, 12), // "NewDataReady"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 5), // "Dummy"
QT_MOC_LITERAL(4, 25, 16), // "FeedBackReceived"
QT_MOC_LITERAL(5, 42, 14), // "QList<int16_t>"
QT_MOC_LITERAL(6, 57, 2), // "ft"
QT_MOC_LITERAL(7, 60, 14), // "QList<int32_t>"
QT_MOC_LITERAL(8, 75, 9), // "positions"
QT_MOC_LITERAL(9, 85, 12), // "positionsInc"
QT_MOC_LITERAL(10, 98, 15), // "QList<uint16_t>"
QT_MOC_LITERAL(11, 114, 16), // "bump_sensor_list"
QT_MOC_LITERAL(12, 131, 12), // "QList<float>"
QT_MOC_LITERAL(13, 144, 13), // "imu_data_list"
QT_MOC_LITERAL(14, 158, 12), // "DataReceived"
QT_MOC_LITERAL(15, 171, 4) // "data"

    },
    "Epos\0NewDataReady\0\0Dummy\0FeedBackReceived\0"
    "QList<int16_t>\0ft\0QList<int32_t>\0"
    "positions\0positionsInc\0QList<uint16_t>\0"
    "bump_sensor_list\0QList<float>\0"
    "imu_data_list\0DataReceived\0data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Epos[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x06 /* Public */,
       3,    0,   35,    2, 0x06 /* Public */,
       4,    5,   36,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,   47,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 7, 0x80000000 | 7, 0x80000000 | 10, 0x80000000 | 12,    6,    8,    9,   11,   13,

 // slots: parameters
    QMetaType::Void, QMetaType::QByteArray,   15,

       0        // eod
};

void Epos::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Epos *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->NewDataReady(); break;
        case 1: _t->Dummy(); break;
        case 2: _t->FeedBackReceived((*reinterpret_cast< QList<int16_t>(*)>(_a[1])),(*reinterpret_cast< QList<int32_t>(*)>(_a[2])),(*reinterpret_cast< QList<int32_t>(*)>(_a[3])),(*reinterpret_cast< QList<uint16_t>(*)>(_a[4])),(*reinterpret_cast< QList<float>(*)>(_a[5]))); break;
        case 3: _t->DataReceived((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<float> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Epos::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Epos::NewDataReady)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Epos::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Epos::Dummy)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Epos::*)(QList<int16_t> , QList<int32_t> , QList<int32_t> , QList<uint16_t> , QList<float> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Epos::FeedBackReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Epos::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Epos.data,
    qt_meta_data_Epos,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Epos::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Epos::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Epos.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Epos::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void Epos::NewDataReady()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Epos::Dummy()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Epos::FeedBackReceived(QList<int16_t> _t1, QList<int32_t> _t2, QList<int32_t> _t3, QList<uint16_t> _t4, QList<float> _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
