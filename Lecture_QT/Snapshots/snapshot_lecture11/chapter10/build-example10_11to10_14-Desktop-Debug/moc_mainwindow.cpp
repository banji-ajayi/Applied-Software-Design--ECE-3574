/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../example10_11to10_14/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[16];
    char stringdata[333];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 12), // "displayImage"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "img"
QT_MOC_LITERAL(4, 29, 23), // "on_actionOpen_triggered"
QT_MOC_LITERAL(5, 53, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(6, 77, 24), // "on_actionClose_triggered"
QT_MOC_LITERAL(7, 102, 23), // "on_actionQuit_triggered"
QT_MOC_LITERAL(8, 126, 21), // "on_undoButton_clicked"
QT_MOC_LITERAL(9, 148, 21), // "on_redoButton_clicked"
QT_MOC_LITERAL(10, 170, 23), // "on_pushButton_3_clicked"
QT_MOC_LITERAL(11, 194, 21), // "on_saveButton_clicked"
QT_MOC_LITERAL(12, 216, 21), // "on_openButton_clicked"
QT_MOC_LITERAL(13, 238, 31), // "on_verticalMirrorButton_clicked"
QT_MOC_LITERAL(14, 270, 33), // "on_horizontalMirrorButton_cli..."
QT_MOC_LITERAL(15, 304, 28) // "on_adjustColorButton_clicked"

    },
    "MainWindow\0displayImage\0\0img\0"
    "on_actionOpen_triggered\0on_actionSave_triggered\0"
    "on_actionClose_triggered\0"
    "on_actionQuit_triggered\0on_undoButton_clicked\0"
    "on_redoButton_clicked\0on_pushButton_3_clicked\0"
    "on_saveButton_clicked\0on_openButton_clicked\0"
    "on_verticalMirrorButton_clicked\0"
    "on_horizontalMirrorButton_clicked\0"
    "on_adjustColorButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x0a /* Public */,
       4,    0,   82,    2, 0x08 /* Private */,
       5,    0,   83,    2, 0x08 /* Private */,
       6,    0,   84,    2, 0x08 /* Private */,
       7,    0,   85,    2, 0x08 /* Private */,
       8,    0,   86,    2, 0x08 /* Private */,
       9,    0,   87,    2, 0x08 /* Private */,
      10,    0,   88,    2, 0x08 /* Private */,
      11,    0,   89,    2, 0x08 /* Private */,
      12,    0,   90,    2, 0x08 /* Private */,
      13,    0,   91,    2, 0x08 /* Private */,
      14,    0,   92,    2, 0x08 /* Private */,
      15,    0,   93,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QImage,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->displayImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->on_actionOpen_triggered(); break;
        case 2: _t->on_actionSave_triggered(); break;
        case 3: _t->on_actionClose_triggered(); break;
        case 4: _t->on_actionQuit_triggered(); break;
        case 5: _t->on_undoButton_clicked(); break;
        case 6: _t->on_redoButton_clicked(); break;
        case 7: _t->on_pushButton_3_clicked(); break;
        case 8: _t->on_saveButton_clicked(); break;
        case 9: _t->on_openButton_clicked(); break;
        case 10: _t->on_verticalMirrorButton_clicked(); break;
        case 11: _t->on_horizontalMirrorButton_clicked(); break;
        case 12: _t->on_adjustColorButton_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
