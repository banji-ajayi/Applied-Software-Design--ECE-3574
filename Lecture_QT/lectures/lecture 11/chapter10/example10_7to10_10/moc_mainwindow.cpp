/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyMainWindow_t {
    QByteArrayData data[7];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MyMainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MyMainWindow_t qt_meta_stringdata_MyMainWindow = {
    {
QT_MOC_LITERAL(0, 0, 12),
QT_MOC_LITERAL(1, 13, 19),
QT_MOC_LITERAL(2, 33, 0),
QT_MOC_LITERAL(3, 34, 13),
QT_MOC_LITERAL(4, 48, 8),
QT_MOC_LITERAL(5, 57, 16),
QT_MOC_LITERAL(6, 74, 16)
    },
    "MyMainWindow\0documentWasModified\0\0"
    "initialWidget\0QWidget*\0clipboardChanged\0"
    "QClipboard::Mode\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyMainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   29,    2, 0x09,
       3,    0,   30,    2, 0x09,
       5,    1,   31,    2, 0x09,

 // slots: parameters
    QMetaType::Void,
    0x80000000 | 4,
    QMetaType::Void, 0x80000000 | 6,    2,

       0        // eod
};

void MyMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyMainWindow *_t = static_cast<MyMainWindow *>(_o);
        switch (_id) {
        case 0: _t->documentWasModified(); break;
        case 1: { QWidget* _r = _t->initialWidget();
            if (_a[0]) *reinterpret_cast< QWidget**>(_a[0]) = _r; }  break;
        case 2: _t->clipboardChanged((*reinterpret_cast< QClipboard::Mode(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MyMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MyMainWindow.data,
      qt_meta_data_MyMainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MyMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MyMainWindow.stringdata))
        return static_cast<void*>(const_cast< MyMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MyMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE