/****************************************************************************
** Meta object code from reading C++ file 'welcomeuser.h'
**
** Created: Fri Oct 26 16:42:28 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hw5/welcomeuser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'welcomeuser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_WelcomeUser[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      13,   12,   12,   12, 0x05,
      26,   12,   12,   12, 0x05,
      52,   12,   12,   12, 0x05,

 // slots: signature, parameters, type, tag, flags
      77,   12,   12,   12, 0x08,
     107,   12,   12,   12, 0x08,
     132,   12,   12,   12, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_WelcomeUser[] = {
    "WelcomeUser\0\0exitSignal()\0"
    "changePassSignal(QString)\0"
    "startGameSignal(QString)\0"
    "on_changePassButton_clicked()\0"
    "on_startButton_clicked()\0"
    "on_exitButton_clicked()\0"
};

void WelcomeUser::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        WelcomeUser *_t = static_cast<WelcomeUser *>(_o);
        switch (_id) {
        case 0: _t->exitSignal(); break;
        case 1: _t->changePassSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->startGameSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->on_changePassButton_clicked(); break;
        case 4: _t->on_startButton_clicked(); break;
        case 5: _t->on_exitButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData WelcomeUser::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject WelcomeUser::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_WelcomeUser,
      qt_meta_data_WelcomeUser, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &WelcomeUser::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *WelcomeUser::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *WelcomeUser::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_WelcomeUser))
        return static_cast<void*>(const_cast< WelcomeUser*>(this));
    return QWidget::qt_metacast(_clname);
}

int WelcomeUser::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WelcomeUser::exitSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void WelcomeUser::changePassSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void WelcomeUser::startGameSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
