/****************************************************************************
** Meta object code from reading C++ file 'qnode.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "src/qnode.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qnode.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QNode_t {
    QByteArrayData data[16];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QNode_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QNode_t qt_meta_stringdata_QNode = {
    {
QT_MOC_LITERAL(0, 0, 5), // "QNode"
QT_MOC_LITERAL(1, 6, 14), // "loggingUpdated"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "rosShutdown"
QT_MOC_LITERAL(4, 34, 20), // "NewjointDataReceived"
QT_MOC_LITERAL(5, 55, 12), // "SetActiveCSP"
QT_MOC_LITERAL(6, 68, 2), // "id"
QT_MOC_LITERAL(7, 71, 15), // "DoResetAllNodes"
QT_MOC_LITERAL(8, 87, 12), // "DoResetHands"
QT_MOC_LITERAL(9, 100, 11), // "DoResetLegs"
QT_MOC_LITERAL(10, 112, 15), // "DoActivateHands"
QT_MOC_LITERAL(11, 128, 14), // "DoActivateLegs"
QT_MOC_LITERAL(12, 143, 7), // "SetHome"
QT_MOC_LITERAL(13, 151, 11), // "DoReadError"
QT_MOC_LITERAL(14, 163, 25), // "ExternalOperationComleted"
QT_MOC_LITERAL(15, 189, 18) // "UpdateAllPositions"

    },
    "QNode\0loggingUpdated\0\0rosShutdown\0"
    "NewjointDataReceived\0SetActiveCSP\0id\0"
    "DoResetAllNodes\0DoResetHands\0DoResetLegs\0"
    "DoActivateHands\0DoActivateLegs\0SetHome\0"
    "DoReadError\0ExternalOperationComleted\0"
    "UpdateAllPositions"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QNode[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   79,    2, 0x06 /* Public */,
       3,    0,   80,    2, 0x06 /* Public */,
       4,    0,   81,    2, 0x06 /* Public */,
       5,    1,   82,    2, 0x06 /* Public */,
       7,    1,   85,    2, 0x06 /* Public */,
       8,    0,   88,    2, 0x06 /* Public */,
       9,    0,   89,    2, 0x06 /* Public */,
      10,    0,   90,    2, 0x06 /* Public */,
      11,    0,   91,    2, 0x06 /* Public */,
      12,    1,   92,    2, 0x06 /* Public */,
      13,    0,   95,    2, 0x06 /* Public */,
      14,    0,   96,    2, 0x06 /* Public */,
      15,    0,   97,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void QNode::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QNode *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->loggingUpdated(); break;
        case 1: _t->rosShutdown(); break;
        case 2: _t->NewjointDataReceived(); break;
        case 3: _t->SetActiveCSP((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->DoResetAllNodes((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->DoResetHands(); break;
        case 6: _t->DoResetLegs(); break;
        case 7: _t->DoActivateHands(); break;
        case 8: _t->DoActivateLegs(); break;
        case 9: _t->SetHome((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->DoReadError(); break;
        case 11: _t->ExternalOperationComleted(); break;
        case 12: _t->UpdateAllPositions(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::loggingUpdated)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::rosShutdown)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::NewjointDataReceived)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QNode::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::SetActiveCSP)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QNode::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::DoResetAllNodes)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::DoResetHands)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::DoResetLegs)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::DoActivateHands)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::DoActivateLegs)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (QNode::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::SetHome)) {
                *result = 9;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::DoReadError)) {
                *result = 10;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::ExternalOperationComleted)) {
                *result = 11;
                return;
            }
        }
        {
            using _t = void (QNode::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QNode::UpdateAllPositions)) {
                *result = 12;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QNode::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_QNode.data,
    qt_meta_data_QNode,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QNode::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QNode::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QNode.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QNode::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void QNode::loggingUpdated()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QNode::rosShutdown()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QNode::NewjointDataReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void QNode::SetActiveCSP(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QNode::DoResetAllNodes(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void QNode::DoResetHands()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void QNode::DoResetLegs()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void QNode::DoActivateHands()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void QNode::DoActivateLegs()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void QNode::SetHome(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}

// SIGNAL 10
void QNode::DoReadError()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}

// SIGNAL 11
void QNode::ExternalOperationComleted()
{
    QMetaObject::activate(this, &staticMetaObject, 11, nullptr);
}

// SIGNAL 12
void QNode::UpdateAllPositions()
{
    QMetaObject::activate(this, &staticMetaObject, 12, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
