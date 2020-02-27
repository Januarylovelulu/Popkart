/****************************************************************************
** Meta object code from reading C++ file 'shortcutchange.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../shortcutchange.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'shortcutchange.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ShortcutChange_t {
    QByteArrayData data[13];
    char stringdata0[200];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ShortcutChange_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ShortcutChange_t qt_meta_stringdata_ShortcutChange = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ShortcutChange"
QT_MOC_LITERAL(1, 15, 24), // "on_hideInput_textChanged"
QT_MOC_LITERAL(2, 40, 0), // ""
QT_MOC_LITERAL(3, 41, 4), // "arg1"
QT_MOC_LITERAL(4, 46, 24), // "on_showInput_textChanged"
QT_MOC_LITERAL(5, 71, 28), // "on_seamlessInput_textChanged"
QT_MOC_LITERAL(6, 100, 11), // "on_shortcut"
QT_MOC_LITERAL(7, 112, 6), // "boolen"
QT_MOC_LITERAL(8, 119, 15), // "on_back_clicked"
QT_MOC_LITERAL(9, 135, 15), // "on_sure_clicked"
QT_MOC_LITERAL(10, 151, 14), // "on_timeoutShow"
QT_MOC_LITERAL(11, 166, 14), // "on_timeoutHide"
QT_MOC_LITERAL(12, 181, 18) // "on_timeoutSeamless"

    },
    "ShortcutChange\0on_hideInput_textChanged\0"
    "\0arg1\0on_showInput_textChanged\0"
    "on_seamlessInput_textChanged\0on_shortcut\0"
    "boolen\0on_back_clicked\0on_sure_clicked\0"
    "on_timeoutShow\0on_timeoutHide\0"
    "on_timeoutSeamless"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ShortcutChange[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x08 /* Private */,
       4,    1,   62,    2, 0x08 /* Private */,
       5,    1,   65,    2, 0x08 /* Private */,
       6,    1,   68,    2, 0x08 /* Private */,
       8,    0,   71,    2, 0x08 /* Private */,
       9,    0,   72,    2, 0x08 /* Private */,
      10,    0,   73,    2, 0x08 /* Private */,
      11,    0,   74,    2, 0x08 /* Private */,
      12,    0,   75,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::Bool,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ShortcutChange::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ShortcutChange *_t = static_cast<ShortcutChange *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_hideInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->on_showInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->on_seamlessInput_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_shortcut((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 4: _t->on_back_clicked(); break;
        case 5: _t->on_sure_clicked(); break;
        case 6: _t->on_timeoutShow(); break;
        case 7: _t->on_timeoutHide(); break;
        case 8: _t->on_timeoutSeamless(); break;
        default: ;
        }
    }
}

const QMetaObject ShortcutChange::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_ShortcutChange.data,
      qt_meta_data_ShortcutChange,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ShortcutChange::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ShortcutChange::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ShortcutChange.stringdata0))
        return static_cast<void*>(const_cast< ShortcutChange*>(this));
    return QDialog::qt_metacast(_clname);
}

int ShortcutChange::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
