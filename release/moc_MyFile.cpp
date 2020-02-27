/****************************************************************************
** Meta object code from reading C++ file 'MyFile.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../MyFile.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'MyFile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MyFile_t {
    QByteArrayData data[14];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyFile_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyFile_t qt_meta_stringdata_MyFile = {
    {
QT_MOC_LITERAL(0, 0, 6), // "MyFile"
QT_MOC_LITERAL(1, 7, 14), // "sendCmdMessage"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 3), // "str"
QT_MOC_LITERAL(4, 27, 5), // "isEnd"
QT_MOC_LITERAL(5, 33, 16), // "on_getCmdMessage"
QT_MOC_LITERAL(6, 50, 10), // "SelectAttr"
QT_MOC_LITERAL(7, 61, 9), // "selectAll"
QT_MOC_LITERAL(8, 71, 9), // "selectExe"
QT_MOC_LITERAL(9, 81, 9), // "selectApp"
QT_MOC_LITERAL(10, 91, 10), // "selectHtml"
QT_MOC_LITERAL(11, 102, 11), // "selectMusic"
QT_MOC_LITERAL(12, 114, 13), // "selectPictrue"
QT_MOC_LITERAL(13, 128, 10) // "selectText"

    },
    "MyFile\0sendCmdMessage\0\0str\0isEnd\0"
    "on_getCmdMessage\0SelectAttr\0selectAll\0"
    "selectExe\0selectApp\0selectHtml\0"
    "selectMusic\0selectPictrue\0selectText"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyFile[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       1,   30, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void,

 // enums: name, flags, count, data
       6, 0x0,    7,   34,

 // enum data: key, value
       7, uint(MyFile::selectAll),
       8, uint(MyFile::selectExe),
       9, uint(MyFile::selectApp),
      10, uint(MyFile::selectHtml),
      11, uint(MyFile::selectMusic),
      12, uint(MyFile::selectPictrue),
      13, uint(MyFile::selectText),

       0        // eod
};

void MyFile::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MyFile *_t = static_cast<MyFile *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendCmdMessage((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->on_getCmdMessage(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (MyFile::*_t)(QString , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MyFile::sendCmdMessage)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MyFile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_MyFile.data,
      qt_meta_data_MyFile,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MyFile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyFile::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MyFile.stringdata0))
        return static_cast<void*>(const_cast< MyFile*>(this));
    return QObject::qt_metacast(_clname);
}

int MyFile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MyFile::sendCmdMessage(QString _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
