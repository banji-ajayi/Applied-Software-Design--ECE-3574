/****************************************************************************
** Meta object code from reading C++ file 'computer.h'
**
** Created: Sun Apr 7 23:50:46 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "computer.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'computer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Computer[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      23,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      15,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,   10,    9,    9, 0x05,
      49,   43,    9,    9, 0x05,
      81,   69,    9,    9, 0x05,
     130,  110,    9,    9, 0x05,
     160,   69,    9,    9, 0x05,
     193,   69,    9,    9, 0x05,
     236,  212,    9,    9, 0x05,
     287,  274,    9,    9, 0x05,
     320,  315,    9,    9, 0x05,
     338,    9,    9,    9, 0x05,
     360,  351,    9,    9, 0x05,
     407,  398,    9,    9, 0x05,
     443,  436,    9,    9, 0x05,
     467,  436,    9,    9, 0x05,
     489,    9,    9,    9, 0x05,

 // slots: signature, parameters, type, tag, flags
     516,  507,    9,    9, 0x0a,
     536,    9,    9,    9, 0x0a,
     553,    9,    9,    9, 0x0a,
     569,    9,    9,    9, 0x0a,
     583,    9,    9,    9, 0x0a,
     621,  597,    9,    9, 0x0a,
     655,    9,    9,    9, 0x0a,
     724,  672,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Computer[] = {
    "Computer\0\0var\0returnInstruction(QVariant&)\0"
    "error\0inputError(QString)\0value,count\0"
    "newAccumulatorValue(int,int)\0"
    "address,value,count\0changeMemoryData(int,int,int)\0"
    "loadNewAccumulatorValue(int,int)\0"
    "addSignal(int,int)\0count,instructionNumber\0"
    "newProgramCounterValueSignal(int,int)\0"
    "output,count\0standardOutput(QString,int)\0"
    "item\0overFlow(QString)\0haltSignal()\0"
    "theCache\0newCacheData(QMap<QString,BlockData>)\0"
    "cacheOut\0returnMemoryBlock(BlockData)\0"
    "status\0cacheGuiHitOrMiss(bool)\0"
    "simGuiHitOrMiss(bool)\0clearCacheTable()\0"
    "fileName\0initialize(QString)\0"
    "stepPushedSlot()\0runPushedSlot()\0"
    "acceptReset()\0acceptClear()\0"
    "newInstruction,location\0"
    "acceptNewInstruction(QString,int)\0"
    "acceptCacheOff()\0"
    "cacheSize,numberOfBlocks,blockSizeGiven,cacheStatus\0"
    "acceptCacheEnable(int,int,int,bool)\0"
};

void Computer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Computer *_t = static_cast<Computer *>(_o);
        switch (_id) {
        case 0: _t->returnInstruction((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->inputError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->newAccumulatorValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->changeMemoryData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        case 4: _t->loadNewAccumulatorValue((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->addSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 6: _t->newProgramCounterValueSignal((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: _t->standardOutput((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->overFlow((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->haltSignal(); break;
        case 10: _t->newCacheData((*reinterpret_cast< QMap<QString,BlockData>(*)>(_a[1]))); break;
        case 11: _t->returnMemoryBlock((*reinterpret_cast< BlockData(*)>(_a[1]))); break;
        case 12: _t->cacheGuiHitOrMiss((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->simGuiHitOrMiss((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->clearCacheTable(); break;
        case 15: _t->initialize((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 16: _t->stepPushedSlot(); break;
        case 17: _t->runPushedSlot(); break;
        case 18: _t->acceptReset(); break;
        case 19: _t->acceptClear(); break;
        case 20: _t->acceptNewInstruction((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 21: _t->acceptCacheOff(); break;
        case 22: _t->acceptCacheEnable((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Computer::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Computer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Computer,
      qt_meta_data_Computer, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Computer::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Computer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Computer::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Computer))
        return static_cast<void*>(const_cast< Computer*>(this));
    return QObject::qt_metacast(_clname);
}

int Computer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 23)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 23;
    }
    return _id;
}

// SIGNAL 0
void Computer::returnInstruction(QVariant & _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Computer::inputError(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Computer::newAccumulatorValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Computer::changeMemoryData(int _t1, int _t2, int _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Computer::loadNewAccumulatorValue(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void Computer::addSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void Computer::newProgramCounterValueSignal(int _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Computer::standardOutput(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void Computer::overFlow(QString _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void Computer::haltSignal()
{
    QMetaObject::activate(this, &staticMetaObject, 9, 0);
}

// SIGNAL 10
void Computer::newCacheData(QMap<QString,BlockData> _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 10, _a);
}

// SIGNAL 11
void Computer::returnMemoryBlock(BlockData _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 11, _a);
}

// SIGNAL 12
void Computer::cacheGuiHitOrMiss(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 12, _a);
}

// SIGNAL 13
void Computer::simGuiHitOrMiss(bool _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 13, _a);
}

// SIGNAL 14
void Computer::clearCacheTable()
{
    QMetaObject::activate(this, &staticMetaObject, 14, 0);
}
QT_END_MOC_NAMESPACE
