/****************************************************************************
** Meta object code from reading C++ file 'Ghost.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "scr/Ghost.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ghost.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ghost_t {
    QByteArrayData data[9];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ghost_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ghost_t qt_meta_stringdata_Ghost = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Ghost"
QT_MOC_LITERAL(1, 6, 8), // "makeBlue"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "makeRegular"
QT_MOC_LITERAL(4, 28, 11), // "executeMove"
QT_MOC_LITERAL(5, 40, 7), // "setLive"
QT_MOC_LITERAL(6, 48, 15), // "catchPlayerMove"
QT_MOC_LITERAL(7, 64, 12), // "playerXCoord"
QT_MOC_LITERAL(8, 77, 12) // "playerYCoord"

    },
    "Ghost\0makeBlue\0\0makeRegular\0executeMove\0"
    "setLive\0catchPlayerMove\0playerXCoord\0"
    "playerYCoord"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ghost[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    2,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    7,    8,

       0        // eod
};

void Ghost::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Ghost *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->makeBlue(); break;
        case 1: _t->makeRegular(); break;
        case 2: _t->executeMove(); break;
        case 3: _t->setLive(); break;
        case 4: _t->catchPlayerMove((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Ghost::staticMetaObject = { {
    QMetaObject::SuperData::link<Moveable::staticMetaObject>(),
    qt_meta_stringdata_Ghost.data,
    qt_meta_data_Ghost,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Ghost::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ghost::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ghost.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsRectItem"))
        return static_cast< QGraphicsRectItem*>(this);
    return Moveable::qt_metacast(_clname);
}

int Ghost::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Moveable::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
