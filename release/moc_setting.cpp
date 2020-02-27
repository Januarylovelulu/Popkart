/****************************************************************************
** Meta object code from reading C++ file 'setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Setting_t {
    QByteArrayData data[10];
    char stringdata0[198];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Setting_t qt_meta_stringdata_Setting = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Setting"
QT_MOC_LITERAL(1, 8, 11), // "transparent"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "on_back_clicked"
QT_MOC_LITERAL(4, 37, 15), // "on_sure_clicked"
QT_MOC_LITERAL(5, 53, 34), // "on_transparent_output_valueCh..."
QT_MOC_LITERAL(6, 88, 8), // "position"
QT_MOC_LITERAL(7, 97, 33), // "on_transparent_input_valueCha..."
QT_MOC_LITERAL(8, 131, 31), // "on_transparent_btn_valueChanged"
QT_MOC_LITERAL(9, 163, 34) // "on_transparent_window_valueCh..."

    },
    "Setting\0transparent\0\0on_back_clicked\0"
    "on_sure_clicked\0on_transparent_output_valueChanged\0"
    "position\0on_transparent_input_valueChanged\0"
    "on_transparent_btn_valueChanged\0"
    "on_transparent_window_valueChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Setting[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   52,    2, 0x08 /* Private */,
       4,    0,   53,    2, 0x08 /* Private */,
       5,    1,   54,    2, 0x08 /* Private */,
       7,    1,   57,    2, 0x08 /* Private */,
       8,    1,   60,    2, 0x08 /* Private */,
       9,    1,   63,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void Setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Setting *_t = static_cast<Setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->transparent((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_back_clicked(); break;
        case 2: _t->on_sure_clicked(); break;
        case 3: _t->on_transparent_output_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_transparent_input_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_transparent_btn_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_transparent_window_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Setting::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Setting::transparent)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Setting::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Setting.data,
      qt_meta_data_Setting,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Setting::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Setting.stringdata0))
        return static_cast<void*>(const_cast< Setting*>(this));
    return QDialog::qt_metacast(_clname);
}

int Setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void Setting::transparent(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
