/****************************************************************************
** Meta object code from reading C++ file 'processthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MotorControl/processthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ProcessThread_t {
    QByteArrayData data[12];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ProcessThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ProcessThread_t qt_meta_stringdata_ProcessThread = {
    {
QT_MOC_LITERAL(0, 0, 13), // "ProcessThread"
QT_MOC_LITERAL(1, 14, 10), // "PIDBrowser"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 2), // "kp"
QT_MOC_LITERAL(4, 29, 2), // "ki"
QT_MOC_LITERAL(5, 32, 2), // "kd"
QT_MOC_LITERAL(6, 35, 3), // "cmd"
QT_MOC_LITERAL(7, 39, 10), // "TUNBrowser"
QT_MOC_LITERAL(8, 50, 3), // "str"
QT_MOC_LITERAL(9, 54, 11), // "updategraph"
QT_MOC_LITERAL(10, 66, 1), // "x"
QT_MOC_LITERAL(11, 68, 1) // "y"

    },
    "ProcessThread\0PIDBrowser\0\0kp\0ki\0kd\0"
    "cmd\0TUNBrowser\0str\0updategraph\0x\0y"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProcessThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   29,    2, 0x06 /* Public */,
       7,    1,   38,    2, 0x06 /* Public */,
       9,    2,   41,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    3,    4,    5,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Double, QMetaType::Double,   10,   11,

       0        // eod
};

void ProcessThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ProcessThread *_t = static_cast<ProcessThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->PIDBrowser((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 1: _t->TUNBrowser((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->updategraph((*reinterpret_cast< double(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (ProcessThread::*_t)(QString , QString , QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::PIDBrowser)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (ProcessThread::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::TUNBrowser)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (ProcessThread::*_t)(double , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ProcessThread::updategraph)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject ProcessThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_ProcessThread.data,
      qt_meta_data_ProcessThread,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *ProcessThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProcessThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int ProcessThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void ProcessThread::PIDBrowser(QString _t1, QString _t2, QString _t3, QString _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProcessThread::TUNBrowser(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProcessThread::updategraph(double _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
