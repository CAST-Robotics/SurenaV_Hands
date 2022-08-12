/****************************************************************************
** Meta object code from reading C++ file 'robot.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/robot.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'robot.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Robot_t {
    QByteArrayData data[29];
    char stringdata0[339];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Robot_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Robot_t qt_meta_stringdata_Robot = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Robot"
QT_MOC_LITERAL(1, 6, 10), // "ReadErrors"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 23), // "ReadAllInitialPositions"
QT_MOC_LITERAL(4, 42, 11), // "StatusCheck"
QT_MOC_LITERAL(5, 54, 10), // "Initialize"
QT_MOC_LITERAL(6, 65, 4), // "Home"
QT_MOC_LITERAL(7, 70, 2), // "id"
QT_MOC_LITERAL(8, 73, 12), // "CleanAndExit"
QT_MOC_LITERAL(9, 86, 20), // "NewjointDataReceived"
QT_MOC_LITERAL(10, 107, 7), // "Timeout"
QT_MOC_LITERAL(11, 115, 11), // "HommingLoop"
QT_MOC_LITERAL(12, 127, 16), // "FeedBackReceived"
QT_MOC_LITERAL(13, 144, 14), // "QList<int16_t>"
QT_MOC_LITERAL(14, 159, 2), // "ft"
QT_MOC_LITERAL(15, 162, 14), // "QList<int32_t>"
QT_MOC_LITERAL(16, 177, 9), // "positions"
QT_MOC_LITERAL(17, 187, 12), // "positionsInc"
QT_MOC_LITERAL(18, 200, 15), // "QList<uint16_t>"
QT_MOC_LITERAL(19, 216, 16), // "bump_sensor_list"
QT_MOC_LITERAL(20, 233, 12), // "QList<float>"
QT_MOC_LITERAL(21, 246, 13), // "imu_data_list"
QT_MOC_LITERAL(22, 260, 6), // "SetLed"
QT_MOC_LITERAL(23, 267, 9), // "ActiveCSP"
QT_MOC_LITERAL(24, 277, 13), // "ResetAllNodes"
QT_MOC_LITERAL(25, 291, 10), // "ResetHands"
QT_MOC_LITERAL(26, 302, 13), // "ActivateHands"
QT_MOC_LITERAL(27, 316, 12), // "ActivateLegs"
QT_MOC_LITERAL(28, 329, 9) // "ResetLegs"

    },
    "Robot\0ReadErrors\0\0ReadAllInitialPositions\0"
    "StatusCheck\0Initialize\0Home\0id\0"
    "CleanAndExit\0NewjointDataReceived\0"
    "Timeout\0HommingLoop\0FeedBackReceived\0"
    "QList<int16_t>\0ft\0QList<int32_t>\0"
    "positions\0positionsInc\0QList<uint16_t>\0"
    "bump_sensor_list\0QList<float>\0"
    "imu_data_list\0SetLed\0ActiveCSP\0"
    "ResetAllNodes\0ResetHands\0ActivateHands\0"
    "ActivateLegs\0ResetLegs"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Robot[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x0a /* Public */,
       3,    0,  100,    2, 0x0a /* Public */,
       4,    0,  101,    2, 0x0a /* Public */,
       5,    0,  102,    2, 0x0a /* Public */,
       6,    1,  103,    2, 0x0a /* Public */,
       8,    0,  106,    2, 0x0a /* Public */,
       9,    0,  107,    2, 0x0a /* Public */,
      10,    0,  108,    2, 0x0a /* Public */,
      11,    0,  109,    2, 0x0a /* Public */,
      12,    5,  110,    2, 0x0a /* Public */,
      22,    1,  121,    2, 0x0a /* Public */,
      23,    1,  124,    2, 0x0a /* Public */,
      24,    1,  127,    2, 0x0a /* Public */,
      25,    0,  130,    2, 0x0a /* Public */,
      26,    0,  131,    2, 0x0a /* Public */,
      27,    0,  132,    2, 0x0a /* Public */,
      28,    0,  133,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15, 0x80000000 | 15, 0x80000000 | 18, 0x80000000 | 20,   14,   16,   17,   19,   21,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Robot::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Robot *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->ReadErrors(); break;
        case 1: { bool _r = _t->ReadAllInitialPositions();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->StatusCheck(); break;
        case 3: _t->Initialize(); break;
        case 4: _t->Home((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->CleanAndExit(); break;
        case 6: _t->NewjointDataReceived(); break;
        case 7: _t->Timeout(); break;
        case 8: _t->HommingLoop(); break;
        case 9: _t->FeedBackReceived((*reinterpret_cast< QList<int16_t>(*)>(_a[1])),(*reinterpret_cast< QList<int32_t>(*)>(_a[2])),(*reinterpret_cast< QList<int32_t>(*)>(_a[3])),(*reinterpret_cast< QList<uint16_t>(*)>(_a[4])),(*reinterpret_cast< QList<float>(*)>(_a[5]))); break;
        case 10: _t->SetLed((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->ActiveCSP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->ResetAllNodes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->ResetHands(); break;
        case 14: _t->ActivateHands(); break;
        case 15: _t->ActivateLegs(); break;
        case 16: _t->ResetLegs(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 4:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<float> >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Robot::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_Robot.data,
    qt_meta_data_Robot,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Robot::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Robot::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Robot.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Robot::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
