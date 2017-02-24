/****************************************************************************
** Meta object code from reading C++ file 'metadata.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../example13_5to13_9/metadata.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'metadata.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MetaData_t {
    QByteArrayData data[29];
    char stringdata[260];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MetaData_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MetaData_t qt_meta_stringdata_MetaData = {
    {
QT_MOC_LITERAL(0, 0, 8), // "MetaData"
QT_MOC_LITERAL(1, 9, 13), // "setTrackTitle"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5), // "title"
QT_MOC_LITERAL(4, 30, 9), // "setArtist"
QT_MOC_LITERAL(5, 40, 6), // "artist"
QT_MOC_LITERAL(6, 47, 12), // "setTrackTime"
QT_MOC_LITERAL(7, 60, 4), // "time"
QT_MOC_LITERAL(8, 65, 13), // "setAlbumTitle"
QT_MOC_LITERAL(9, 79, 14), // "setTrackNumber"
QT_MOC_LITERAL(10, 94, 1), // "n"
QT_MOC_LITERAL(11, 96, 8), // "setGenre"
QT_MOC_LITERAL(12, 105, 5), // "genre"
QT_MOC_LITERAL(13, 111, 9), // "setRating"
QT_MOC_LITERAL(14, 121, 10), // "StarRating"
QT_MOC_LITERAL(15, 132, 6), // "rating"
QT_MOC_LITERAL(16, 139, 10), // "setComment"
QT_MOC_LITERAL(17, 150, 7), // "comment"
QT_MOC_LITERAL(18, 158, 11), // "setFileName"
QT_MOC_LITERAL(19, 170, 8), // "fileName"
QT_MOC_LITERAL(20, 179, 10), // "TrackTitle"
QT_MOC_LITERAL(21, 190, 6), // "Artist"
QT_MOC_LITERAL(22, 197, 9), // "TrackTime"
QT_MOC_LITERAL(23, 207, 10), // "AlbumTitle"
QT_MOC_LITERAL(24, 218, 11), // "TrackNumber"
QT_MOC_LITERAL(25, 230, 5), // "Genre"
QT_MOC_LITERAL(26, 236, 6), // "Rating"
QT_MOC_LITERAL(27, 243, 7), // "Comment"
QT_MOC_LITERAL(28, 251, 8) // "FileName"

    },
    "MetaData\0setTrackTitle\0\0title\0setArtist\0"
    "artist\0setTrackTime\0time\0setAlbumTitle\0"
    "setTrackNumber\0n\0setGenre\0genre\0"
    "setRating\0StarRating\0rating\0setComment\0"
    "comment\0setFileName\0fileName\0TrackTitle\0"
    "Artist\0TrackTime\0AlbumTitle\0TrackNumber\0"
    "Genre\0Rating\0Comment\0FileName"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MetaData[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       9,   86, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x0a /* Public */,
       4,    1,   62,    2, 0x0a /* Public */,
       6,    1,   65,    2, 0x0a /* Public */,
       8,    1,   68,    2, 0x0a /* Public */,
       9,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      13,    1,   77,    2, 0x0a /* Public */,
      16,    1,   80,    2, 0x0a /* Public */,
      18,    1,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QTime,    7,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,

 // properties: name, type, flags
      20, QMetaType::QString, 0x00095103,
      21, QMetaType::QString, 0x00095103,
      22, QMetaType::QTime, 0x00095103,
      23, QMetaType::QString, 0x00095103,
      24, QMetaType::Int, 0x00095103,
      25, QMetaType::QString, 0x00095103,
      26, 0x80000000 | 14, 0x0009510b,
      27, QMetaType::QString, 0x00095103,
      28, QMetaType::QString, 0x00095103,

       0        // eod
};

void MetaData::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MetaData *_t = static_cast<MetaData *>(_o);
        switch (_id) {
        case 0: _t->setTrackTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->setArtist((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->setTrackTime((*reinterpret_cast< const QTime(*)>(_a[1]))); break;
        case 3: _t->setAlbumTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->setTrackNumber((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setGenre((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->setRating((*reinterpret_cast< StarRating(*)>(_a[1]))); break;
        case 7: _t->setComment((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->setFileName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StarRating >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 6:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< StarRating >(); break;
        }
    }

}

const QMetaObject MetaData::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MetaData.data,
      qt_meta_data_MetaData,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MetaData::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MetaData::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MetaData.stringdata))
        return static_cast<void*>(const_cast< MetaData*>(this));
    return QObject::qt_metacast(_clname);
}

int MetaData::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#ifndef QT_NO_PROPERTIES
      else if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = trackTitle(); break;
        case 1: *reinterpret_cast< QString*>(_v) = artist(); break;
        case 2: *reinterpret_cast< QTime*>(_v) = trackTime(); break;
        case 3: *reinterpret_cast< QString*>(_v) = albumTitle(); break;
        case 4: *reinterpret_cast< int*>(_v) = trackNumber(); break;
        case 5: *reinterpret_cast< QString*>(_v) = genre(); break;
        case 6: *reinterpret_cast< StarRating*>(_v) = rating(); break;
        case 7: *reinterpret_cast< QString*>(_v) = comment(); break;
        case 8: *reinterpret_cast< QString*>(_v) = fileName(); break;
        default: break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setTrackTitle(*reinterpret_cast< QString*>(_v)); break;
        case 1: setArtist(*reinterpret_cast< QString*>(_v)); break;
        case 2: setTrackTime(*reinterpret_cast< QTime*>(_v)); break;
        case 3: setAlbumTitle(*reinterpret_cast< QString*>(_v)); break;
        case 4: setTrackNumber(*reinterpret_cast< int*>(_v)); break;
        case 5: setGenre(*reinterpret_cast< QString*>(_v)); break;
        case 6: setRating(*reinterpret_cast< StarRating*>(_v)); break;
        case 7: setComment(*reinterpret_cast< QString*>(_v)); break;
        case 8: setFileName(*reinterpret_cast< QString*>(_v)); break;
        default: break;
        }
        _id -= 9;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 9;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 9;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
