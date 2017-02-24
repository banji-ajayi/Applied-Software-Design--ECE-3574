/****************************************************************************
** Meta object code from reading C++ file 'simulatorgui.h'
**
** Created: Sat Mar 23 19:21:31 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "simulatorgui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'simulatorgui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_SimulatorGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      23,   14,   13,   13, 0x05,
      44,   13,   13,   13, 0x05,
      57,   13,   13,   13, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   69,   13,   13, 0x0a,
     109,  102,   13,   13, 0x0a,
     145,  133,   13,   13, 0x0a,
     200,  180,   13,   13, 0x0a,
     260,  236,   13,   13, 0x0a,
     299,  286,   13,   13, 0x0a,
     330,  325,   13,   13, 0x0a,
     354,   13,   13,   13, 0x0a,
     373,   13,   13,   13, 0x08,
     399,   13,   13,   13, 0x08,
     425,   13,   13,   13, 0x08,
     444,   13,   13,   13, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_SimulatorGui[] = {
    "SimulatorGui\0\0fileName\0newFileOpen(QString)\0"
    "stepPushed()\0runPushed()\0var\0"
    "acceptInstruction(QVariant&)\0output\0"
    "inputErrorSlot(QString)\0value,count\0"
    "acceptNewAccumulatorValue(int,int)\0"
    "address,value,count\0"
    "acceptChangeMemoryData(int,int,int)\0"
    "count,instructionNumber\0"
    "acceptNewPCValue(int,int)\0output,count\0"
    "acceptOutput(QString,int)\0item\0"
    "acceptOverflow(QString)\0acceptHaltSignal()\0"
    "on_actionOpen_triggered()\0"
    "on_actionExit_triggered()\0on_step_released()\0"
    "on_run_released()\0"
};

void SimulatorGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        SimulatorGui *_t = static_cast<SimulatorGui *>(_o);
        switch (_id) {
        case 0: _t->newFileOpen((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->stepPushed(); break;
        case 2: _t->runPushed(); break;
        case 3: _t->acceptInstruction((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 4: _t->inputErrorSlot((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->acceptNewAccumulatorValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->acceptChangeMemoryData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 7: _t->acceptNewPCValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->acceptOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->acceptOverflow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->acceptHaltSignal(); break;
        case 11: _t->on_actionOpen_triggered(); break;
        case 12: _t->on_actionExit_triggered(); break;
        case 13: _t->on_step_released(); break;
        case 14: _t->on_run_released(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData SimulatorGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject SimulatorGui::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_SimulatorGui,
      qt_meta_data_SimulatorGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &SimulatorGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *SimulatorGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *SimulatorGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SimulatorGui))
        return static_cast<void*>(const_cast< SimulatorGui*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int SimulatorGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void SimulatorGui::newFileOpen(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SimulatorGui::stepPushed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void SimulatorGui::runPushed()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
