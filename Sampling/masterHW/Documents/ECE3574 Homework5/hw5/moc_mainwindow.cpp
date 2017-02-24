/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Thu Nov 1 14:02:10 2012
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x08,
      36,   11,   11,   11, 0x08,
      55,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
     104,   11,   11,   11, 0x08,
     130,   11,   11,   11, 0x08,
     165,   11,   11,   11, 0x08,
     193,   11,   11,   11, 0x08,
     219,   11,   11,   11, 0x08,
     249,   11,   11,   11, 0x08,
     279,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0displayWelcome(QString)\0"
    "displayMainLogin()\0displayRegister()\0"
    "displayChangePassword(QString)\0"
    "displayTicTacToe(QString)\0"
    "on_actionRegister_User_triggered()\0"
    "on_actionLogout_triggered()\0"
    "on_actionExit_triggered()\0"
    "on_actionNew_game_triggered()\0"
    "on_actionEnd_game_triggered()\0"
    "on_actionChange_Password_triggered()\0"
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->displayWelcome((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->displayMainLogin(); break;
        case 2: _t->displayRegister(); break;
        case 3: _t->displayChangePassword((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->displayTicTacToe((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->on_actionRegister_User_triggered(); break;
        case 6: _t->on_actionLogout_triggered(); break;
        case 7: _t->on_actionExit_triggered(); break;
        case 8: _t->on_actionNew_game_triggered(); break;
        case 9: _t->on_actionEnd_game_triggered(); break;
        case 10: _t->on_actionChange_Password_triggered(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
