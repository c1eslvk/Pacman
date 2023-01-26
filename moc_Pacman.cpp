/****************************************************************************
** Meta object code from reading C++ file 'Pacman.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "scr/Pacman.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Pacman.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Pacman_t {
    QByteArrayData data[13];
    char stringdata0[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Pacman_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Pacman_t qt_meta_stringdata_Pacman = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Pacman"
QT_MOC_LITERAL(1, 7, 13), // "increaseScore"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 5), // "score"
QT_MOC_LITERAL(4, 28, 10), // "startBoost"
QT_MOC_LITERAL(5, 39, 8), // "endBoost"
QT_MOC_LITERAL(6, 48, 10), // "ghostEaten"
QT_MOC_LITERAL(7, 59, 5), // "moved"
QT_MOC_LITERAL(8, 65, 6), // "xCoord"
QT_MOC_LITERAL(9, 72, 6), // "yCoord"
QT_MOC_LITERAL(10, 79, 11), // "executeMove"
QT_MOC_LITERAL(11, 91, 8), // "offBoost"
QT_MOC_LITERAL(12, 100, 10) // "finishGame"

    },
    "Pacman\0increaseScore\0\0score\0startBoost\0"
    "endBoost\0ghostEaten\0moved\0xCoord\0"
    "yCoord\0executeMove\0offBoost\0finishGame"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Pacman[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       4,    0,   57,    2, 0x06 /* Public */,
       5,    0,   58,    2, 0x06 /* Public */,
       6,    0,   59,    2, 0x06 /* Public */,
       7,    2,   60,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,   65,    2, 0x0a /* Public */,
      11,    0,   66,    2, 0x0a /* Public */,
      12,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Pacman::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Pacman *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->increaseScore((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->startBoost(); break;
        case 2: _t->endBoost(); break;
        case 3: _t->ghostEaten(); break;
        case 4: _t->moved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->executeMove(); break;
        case 6: _t->offBoost(); break;
        case 7: _t->finishGame(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Pacman::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacman::increaseScore)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Pacman::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacman::startBoost)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Pacman::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacman::endBoost)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Pacman::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacman::ghostEaten)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Pacman::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Pacman::moved)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Pacman::staticMetaObject = { {
    QMetaObject::SuperData::link<Moveable::staticMetaObject>(),
    qt_meta_stringdata_Pacman.data,
    qt_meta_data_Pacman,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Pacman::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Pacman::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Pacman.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsPixmapItem"))
        return static_cast< QGraphicsPixmapItem*>(this);
    return Moveable::qt_metacast(_clname);
}

int Pacman::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Moveable::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Pacman::increaseScore(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Pacman::startBoost()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Pacman::endBoost()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Pacman::ghostEaten()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Pacman::moved(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
