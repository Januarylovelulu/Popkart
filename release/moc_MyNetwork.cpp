/****************************************************************************
** Meta object code from reading C++ file 'MyNetwork.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MyNetwork.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyNetwork.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyNetwork_t {
    QByteArrayData data[22];
    char stringdata0[276];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyNetwork_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyNetwork_t qt_meta_stringdata_MyNetwork = {
    {
QT_MOC_LITERAL(0, 0, 9), // "MyNetwork"
QT_MOC_LITERAL(1, 10, 13), // "returnUrlInfo"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "msgs"
QT_MOC_LITERAL(4, 30, 10), // "returnJson"
QT_MOC_LITERAL(5, 41, 3), // "msg"
QT_MOC_LITERAL(6, 45, 30), // "returnDownloadProgressBarValue"
QT_MOC_LITERAL(7, 76, 3), // "num"
QT_MOC_LITERAL(8, 80, 21), // "returnDownloadStatute"
QT_MOC_LITERAL(9, 102, 3), // "str"
QT_MOC_LITERAL(10, 106, 26), // "returnDownloadSpeedAndTime"
QT_MOC_LITERAL(11, 133, 4), // "time"
QT_MOC_LITERAL(12, 138, 20), // "returnDownloadFinish"
QT_MOC_LITERAL(13, 159, 19), // "returnDownloadError"
QT_MOC_LITERAL(14, 179, 25), // "on_updateDataReadProgress"
QT_MOC_LITERAL(15, 205, 3), // "now"
QT_MOC_LITERAL(16, 209, 3), // "all"
QT_MOC_LITERAL(17, 213, 14), // "on_getFileSize"
QT_MOC_LITERAL(18, 228, 10), // "on_getJson"
QT_MOC_LITERAL(19, 239, 14), // "QNetworkReply*"
QT_MOC_LITERAL(20, 254, 5), // "reply"
QT_MOC_LITERAL(21, 260, 15) // "on_getJsonTimer"

    },
    "MyNetwork\0returnUrlInfo\0\0msgs\0returnJson\0"
    "msg\0returnDownloadProgressBarValue\0"
    "num\0returnDownloadStatute\0str\0"
    "returnDownloadSpeedAndTime\0time\0"
    "returnDownloadFinish\0returnDownloadError\0"
    "on_updateDataReadProgress\0now\0all\0"
    "on_getFileSize\0on_getJson\0QNetworkReply*\0"
    "reply\0on_getJsonTimer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyNetwork[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       4,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       8,    1,   78,    2, 0x06 /* Public */,
      10,    1,   81,    2, 0x06 /* Public */,
      12,    0,   84,    2, 0x06 /* Public */,
      13,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    2,   88,    2, 0x08 /* Private */,
      17,    2,   93,    2, 0x08 /* Private */,
      18,    1,   98,    2, 0x08 /* Private */,
      21,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   15,   16,
    QMetaType::Void, QMetaType::LongLong, QMetaType::LongLong,   15,   16,
    QMetaType::Void, 0x80000000 | 19,   20,
    QMetaType::Void,

       0        // eod
};

void MyNetwork::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyNetwork *_t = static_cast<MyNetwork *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->returnUrlInfo((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->returnJson((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->returnDownloadProgressBarValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->returnDownloadStatute((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->returnDownloadSpeedAndTime((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->returnDownloadFinish(); break;
        case 6: _t->returnDownloadError((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_updateDataReadProgress((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 8: _t->on_getFileSize((*reinterpret_cast< qint64(*)>(_a[1])),(*reinterpret_cast< qint64(*)>(_a[2]))); break;
        case 9: _t->on_getJson((*reinterpret_cast< QNetworkReply*(*)>(_a[1]))); break;
        case 10: _t->on_getJsonTimer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QNetworkReply* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyNetwork::*_t)(QStringList );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnUrlInfo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MyNetwork::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnJson)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MyNetwork::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnDownloadProgressBarValue)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MyNetwork::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnDownloadStatute)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MyNetwork::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnDownloadSpeedAndTime)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MyNetwork::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnDownloadFinish)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MyNetwork::*_t)(QString );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyNetwork::returnDownloadError)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MyNetwork::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyNetwork.data,
      qt_meta_data_MyNetwork,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyNetwork::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyNetwork::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyNetwork.stringdata0))
        return static_cast<void*>(const_cast< MyNetwork*>(this));
    return QObject::qt_metacast(_clname);
}

int MyNetwork::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void MyNetwork::returnUrlInfo(QStringList _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyNetwork::returnJson(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyNetwork::returnDownloadProgressBarValue(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MyNetwork::returnDownloadStatute(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MyNetwork::returnDownloadSpeedAndTime(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MyNetwork::returnDownloadFinish()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void MyNetwork::returnDownloadError(QString _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
QT_END_MOC_NAMESPACE
