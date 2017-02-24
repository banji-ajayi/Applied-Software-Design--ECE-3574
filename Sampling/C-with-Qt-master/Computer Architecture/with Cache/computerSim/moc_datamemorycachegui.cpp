/****************************************************************************
** Meta object code from reading C++ file 'datamemorycachegui.h'
**
** Created: Sun Apr 7 23:50:49 2013
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "datamemorycachegui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'datamemorycachegui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DataMemoryCacheGui[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      72,   20,   19,   19, 0x05,
     103,   19,   19,   19, 0x05,

 // slots: signature, parameters, type, tag, flags
     123,  114,   19,   19, 0x0a,
     174,  167,   19,   19, 0x0a,
     204,   19,   19,   19, 0x0a,
     231,  226,   19,   19, 0x08,
     273,  226,   19,   19, 0x08,
     315,   19,   19,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DataMemoryCacheGui[] = {
    "DataMemoryCacheGui\0\0"
    "cacheSize,numberOfBlocks,blockSizeGiven,cacheStatus\0"
    "CacheEnabled(int,int,int,bool)\0"
    "cacheOff()\0theCache\0"
    "acceptNewCacheData(QMap<QString,BlockData>)\0"
    "status\0acceptCacheGuiHitOrMiss(bool)\0"
    "acceptClearCacheGui()\0arg1\0"
    "on_cacheSize_currentIndexChanged(QString)\0"
    "on_blockSize_currentIndexChanged(QString)\0"
    "on_setCacheSize_released()\0"
};

void DataMemoryCacheGui::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DataMemoryCacheGui *_t = static_cast<DataMemoryCacheGui *>(_o);
        switch (_id) {
        case 0: _t->CacheEnabled((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4]))); break;
        case 1: _t->cacheOff(); break;
        case 2: _t->acceptNewCacheData((*reinterpret_cast< QMap<QString,BlockData>(*)>(_a[1]))); break;
        case 3: _t->acceptCacheGuiHitOrMiss((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->acceptClearCacheGui(); break;
        case 5: _t->on_cacheSize_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->on_blockSize_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_setCacheSize_released(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData DataMemoryCacheGui::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DataMemoryCacheGui::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_DataMemoryCacheGui,
      qt_meta_data_DataMemoryCacheGui, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DataMemoryCacheGui::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DataMemoryCacheGui::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DataMemoryCacheGui::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DataMemoryCacheGui))
        return static_cast<void*>(const_cast< DataMemoryCacheGui*>(this));
    return QWidget::qt_metacast(_clname);
}

int DataMemoryCacheGui::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void DataMemoryCacheGui::CacheEnabled(int _t1, int _t2, int _t3, bool _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DataMemoryCacheGui::cacheOff()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}
QT_END_MOC_NAMESPACE
