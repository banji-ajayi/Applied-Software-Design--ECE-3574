/****************************************************************************
** Meta object code from reading C++ file 'mainlogin.h'
**
** Created: Thu Nov 1 14:02:13 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainlogin.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainlogin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_mainLogin[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      30,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      43,   10,   10,   10, 0x08,
      66,   10,   10,   10, 0x08,
      85,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_mainLogin[] = {
    "mainLogin\0\0goodLogin(QString)\0"
    "exitSignal()\0goodLoginSlot(QString)\0"
    "on_login_clicked()\0on_exit_clicked()\0"
};

void mainLogin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        mainLogin *_t = static_cast<mainLogin *>(_o);
        switch (_id) {
        case 0: _t->goodLogin((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->exitSignal(); break;
        case 2: _t->goodLoginSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_login_clicked(); break;
        case 4: _t->on_exit_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData mainLogin::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject mainLogin::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_mainLogin,
      qt_meta_data_mainLogin, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &mainLogin::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *mainLogin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *mainLogin::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_mainLogin))
        return static_cast<void*>(const_cast< mainLogin*>(this));
    return QWidget::qt_metacast(_clname);
}

int mainLogin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void mainLogin::goodLogin(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void mainLogin::exitSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
