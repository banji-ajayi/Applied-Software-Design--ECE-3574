/****************************************************************************
** Meta object code from reading C++ file 'textbook.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../example11_8to11_11/textbook.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'textbook.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Textbook_t {
    QByteArrayData data[10];
    char stringdata[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Textbook_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Textbook_t qt_meta_stringdata_Textbook = {
    {
QT_MOC_LITERAL(0, 0, 8), // "Textbook"
QT_MOC_LITERAL(1, 9, 9), // "setAuthor"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 9), // "newAuthor"
QT_MOC_LITERAL(4, 30, 8), // "setTitle"
QT_MOC_LITERAL(5, 39, 8), // "newTitle"
QT_MOC_LITERAL(6, 48, 7), // "setIsbn"
QT_MOC_LITERAL(7, 56, 7), // "newIsbn"
QT_MOC_LITERAL(8, 64, 10), // "setYearPub"
QT_MOC_LITERAL(9, 75, 7) // "newYear"

    },
    "Textbook\0setAuthor\0\0newAuthor\0setTitle\0"
    "newTitle\0setIsbn\0newIsbn\0setYearPub\0"
    "newYear"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Textbook[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::UInt,    9,

       0        // eod
};

void Textbook::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Textbook *_t = static_cast<Textbook *>(_o);
        switch (_id) {
        case 0: _t->setAuthor((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setIsbn((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->setYearPub((*reinterpret_cast< uint(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject Textbook::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Textbook.data,
      qt_meta_data_Textbook,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Textbook::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Textbook::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Textbook.stringdata))
        return static_cast<void*>(const_cast< Textbook*>(this));
    return QObject::qt_metacast(_clname);
}

int Textbook::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
