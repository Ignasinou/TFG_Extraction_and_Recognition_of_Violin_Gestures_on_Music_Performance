/****************************************************************************
** Meta object code from reading C++ file 'choosingAndTrack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "choosingAndTrack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'choosingAndTrack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_choosingAndTrack_t {
    QByteArrayData data[35];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_choosingAndTrack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_choosingAndTrack_t qt_meta_stringdata_choosingAndTrack = {
    {
QT_MOC_LITERAL(0, 0, 16), // "choosingAndTrack"
QT_MOC_LITERAL(1, 17, 11), // "morphObject"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 8), // "cv::Mat&"
QT_MOC_LITERAL(4, 39, 6), // "thresh"
QT_MOC_LITERAL(5, 46, 7), // "drawBow"
QT_MOC_LITERAL(6, 54, 2), // "x1"
QT_MOC_LITERAL(7, 57, 2), // "y1"
QT_MOC_LITERAL(8, 60, 2), // "x2"
QT_MOC_LITERAL(9, 63, 2), // "y2"
QT_MOC_LITERAL(10, 66, 7), // "cv::Mat"
QT_MOC_LITERAL(11, 74, 11), // "cameraframe"
QT_MOC_LITERAL(12, 86, 12), // "object2Found"
QT_MOC_LITERAL(13, 99, 8), // "trackBow"
QT_MOC_LITERAL(14, 108, 4), // "int&"
QT_MOC_LITERAL(15, 113, 5), // "x1Bow"
QT_MOC_LITERAL(16, 119, 5), // "y1Bow"
QT_MOC_LITERAL(17, 125, 5), // "x2Bow"
QT_MOC_LITERAL(18, 131, 5), // "y2Bow"
QT_MOC_LITERAL(19, 137, 14), // "thresholdTrack"
QT_MOC_LITERAL(20, 152, 10), // "cameraFeed"
QT_MOC_LITERAL(21, 163, 10), // "drawViolin"
QT_MOC_LITERAL(22, 174, 2), // "x3"
QT_MOC_LITERAL(23, 177, 2), // "y3"
QT_MOC_LITERAL(24, 180, 12), // "object3Found"
QT_MOC_LITERAL(25, 193, 11), // "trackViolin"
QT_MOC_LITERAL(26, 205, 8), // "x1Violin"
QT_MOC_LITERAL(27, 214, 8), // "y1Violin"
QT_MOC_LITERAL(28, 223, 8), // "x2Violin"
QT_MOC_LITERAL(29, 232, 8), // "y2Violin"
QT_MOC_LITERAL(30, 241, 8), // "x3Violin"
QT_MOC_LITERAL(31, 250, 8), // "y3Violin"
QT_MOC_LITERAL(32, 259, 14), // "numberToString"
QT_MOC_LITERAL(33, 274, 11), // "std::string"
QT_MOC_LITERAL(34, 286, 6) // "number"

    },
    "choosingAndTrack\0morphObject\0\0cv::Mat&\0"
    "thresh\0drawBow\0x1\0y1\0x2\0y2\0cv::Mat\0"
    "cameraframe\0object2Found\0trackBow\0"
    "int&\0x1Bow\0y1Bow\0x2Bow\0y2Bow\0"
    "thresholdTrack\0cameraFeed\0drawViolin\0"
    "x3\0y3\0object3Found\0trackViolin\0x1Violin\0"
    "y1Violin\0x2Violin\0y2Violin\0x3Violin\0"
    "y3Violin\0numberToString\0std::string\0"
    "number"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_choosingAndTrack[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       5,    6,   47,    2, 0x08 /* Private */,
      13,    6,   60,    2, 0x08 /* Private */,
      21,    9,   73,    2, 0x08 /* Private */,
      25,    8,   92,    2, 0x08 /* Private */,
      32,    1,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 10, QMetaType::Bool,    6,    7,    8,    9,   11,   12,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 10, 0x80000000 | 10,   15,   16,   17,   18,   19,   20,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, 0x80000000 | 10, QMetaType::Bool, QMetaType::Bool,    6,    7,    8,    9,   22,   23,   11,   12,   24,
    QMetaType::Void, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 14, 0x80000000 | 10, 0x80000000 | 10,   26,   27,   28,   29,   30,   31,   19,   20,
    0x80000000 | 33, QMetaType::Int,   34,

       0        // eod
};

void choosingAndTrack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        choosingAndTrack *_t = static_cast<choosingAndTrack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->morphObject((*reinterpret_cast< cv::Mat(*)>(_a[1]))); break;
        case 1: _t->drawBow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< cv::Mat(*)>(_a[5])),(*reinterpret_cast< bool(*)>(_a[6]))); break;
        case 2: _t->trackBow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< cv::Mat(*)>(_a[5])),(*reinterpret_cast< cv::Mat(*)>(_a[6]))); break;
        case 3: _t->drawViolin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< cv::Mat(*)>(_a[7])),(*reinterpret_cast< bool(*)>(_a[8])),(*reinterpret_cast< bool(*)>(_a[9]))); break;
        case 4: _t->trackViolin((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6])),(*reinterpret_cast< cv::Mat(*)>(_a[7])),(*reinterpret_cast< cv::Mat(*)>(_a[8]))); break;
        case 5: { std::string _r = _t->numberToString((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< std::string*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    }
}

const QMetaObject choosingAndTrack::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_choosingAndTrack.data,
      qt_meta_data_choosingAndTrack,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *choosingAndTrack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *choosingAndTrack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_choosingAndTrack.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int choosingAndTrack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
