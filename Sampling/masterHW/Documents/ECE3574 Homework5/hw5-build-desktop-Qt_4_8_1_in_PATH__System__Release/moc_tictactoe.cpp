/****************************************************************************
** Meta object code from reading C++ file 'tictactoe.h'
**
** Created: Mon Oct 29 15:02:15 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hw5/tictactoe.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'tictactoe.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TicTacToe[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
      42,   10,   10,   10, 0x08,
      69,   10,   10,   10, 0x08,
      94,   10,   10,   10, 0x08,
     119,   10,   10,   10, 0x08,
     144,   10,   10,   10, 0x08,
     169,   10,   10,   10, 0x08,
     194,   10,   10,   10, 0x08,
     219,   10,   10,   10, 0x08,
     244,   10,   10,   10, 0x08,
     269,   10,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TicTacToe[] = {
    "TicTacToe\0\0returnToWelcomeSignal(QString)\0"
    "on_endGameButton_clicked()\0"
    "on_Grid1Button_clicked()\0"
    "on_Grid2Button_clicked()\0"
    "on_Grid3Button_clicked()\0"
    "on_Grid4Button_clicked()\0"
    "on_Grid5Button_clicked()\0"
    "on_Grid6Button_clicked()\0"
    "on_Grid7Button_clicked()\0"
    "on_Grid8Button_clicked()\0"
    "on_Grid9Button_clicked()\0"
};

void TicTacToe::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TicTacToe *_t = static_cast<TicTacToe *>(_o);
        switch (_id) {
        case 0: _t->returnToWelcomeSignal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->on_endGameButton_clicked(); break;
        case 2: _t->on_Grid1Button_clicked(); break;
        case 3: _t->on_Grid2Button_clicked(); break;
        case 4: _t->on_Grid3Button_clicked(); break;
        case 5: _t->on_Grid4Button_clicked(); break;
        case 6: _t->on_Grid5Button_clicked(); break;
        case 7: _t->on_Grid6Button_clicked(); break;
        case 8: _t->on_Grid7Button_clicked(); break;
        case 9: _t->on_Grid8Button_clicked(); break;
        case 10: _t->on_Grid9Button_clicked(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TicTacToe::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TicTacToe::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_TicTacToe,
      qt_meta_data_TicTacToe, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TicTacToe::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TicTacToe::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TicTacToe::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TicTacToe))
        return static_cast<void*>(const_cast< TicTacToe*>(this));
    return QWidget::qt_metacast(_clname);
}

int TicTacToe::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void TicTacToe::returnToWelcomeSignal(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
