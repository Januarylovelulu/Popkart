/****************************************************************************
** Meta object code from reading C++ file 'dpi.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../dpi.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dpi.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_DPI_t {
    QByteArrayData data[9];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DPI_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DPI_t qt_meta_stringdata_DPI = {
    {
QT_MOC_LITERAL(0, 0, 3), // "DPI"
QT_MOC_LITERAL(1, 4, 15), // "on_sure_clicked"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 15), // "on_back_clicked"
QT_MOC_LITERAL(4, 37, 22), // "on_radioButton_clicked"
QT_MOC_LITERAL(5, 60, 24), // "on_radioButton_2_clicked"
QT_MOC_LITERAL(6, 85, 28), // "on_lineEdit_width_textEdited"
QT_MOC_LITERAL(7, 114, 4), // "arg1"
QT_MOC_LITERAL(8, 119, 29) // "on_lineEdit_height_textEdited"

    },
    "DPI\0on_sure_clicked\0\0on_back_clicked\0"
    "on_radioButton_clicked\0on_radioButton_2_clicked\0"
    "on_lineEdit_width_textEdited\0arg1\0"
    "on_lineEdit_height_textEdited"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DPI[] = {

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
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    0,   46,    2, 0x08 /* Private */,
       5,    0,   47,    2, 0x08 /* Private */,
       6,    1,   48,    2, 0x08 /* Private */,
       8,    1,   51,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,

       0        // eod
};

void DPI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DPI *_t = static_cast<DPI *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_sure_clicked(); break;
        case 1: _t->on_back_clicked(); break;
        case 2: _t->on_radioButton_clicked(); break;
        case 3: _t->on_radioButton_2_clicked(); break;
        case 4: _t->on_lineEdit_width_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->on_lineEdit_height_textEdited((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject DPI::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DPI.data,
      qt_meta_data_DPI,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DPI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DPI::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DPI.stringdata0))
        return static_cast<void*>(const_cast< DPI*>(this));
    return QDialog::qt_metacast(_clname);
}

int DPI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
