/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Wiitar/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[22];
    char stringdata[388];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 22),
QT_MOC_LITERAL(2, 34, 0),
QT_MOC_LITERAL(3, 35, 5),
QT_MOC_LITERAL(4, 41, 27),
QT_MOC_LITERAL(5, 69, 4),
QT_MOC_LITERAL(6, 74, 21),
QT_MOC_LITERAL(7, 96, 23),
QT_MOC_LITERAL(8, 120, 21),
QT_MOC_LITERAL(9, 142, 23),
QT_MOC_LITERAL(10, 166, 17),
QT_MOC_LITERAL(11, 184, 17),
QT_MOC_LITERAL(12, 202, 17),
QT_MOC_LITERAL(13, 220, 17),
QT_MOC_LITERAL(14, 238, 16),
QT_MOC_LITERAL(15, 255, 18),
QT_MOC_LITERAL(16, 274, 16),
QT_MOC_LITERAL(17, 291, 18),
QT_MOC_LITERAL(18, 310, 18),
QT_MOC_LITERAL(19, 329, 20),
QT_MOC_LITERAL(20, 350, 17),
QT_MOC_LITERAL(21, 368, 19)
    },
    "MainWindow\0on_volume_valueChanged\0\0"
    "value\0on_midichannel_valueChanged\0"
    "arg1\0on_comboBox_activated\0"
    "on_program_valueChanged\0on_testButton_clicked\0"
    "on_testButton_2_clicked\0on_eChord_clicked\0"
    "on_fChord_clicked\0on_gChord_clicked\0"
    "on_aChord_clicked\0on_oneUp_clicked\0"
    "on_oneDown_clicked\0on_twoUp_clicked\0"
    "on_twoDown_clicked\0on_threeUp_clicked\0"
    "on_threeDown_clicked\0on_fourUp_clicked\0"
    "on_fourDown_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,  104,    2, 0x08 /* Private */,
       4,    1,  107,    2, 0x08 /* Private */,
       6,    1,  110,    2, 0x08 /* Private */,
       7,    1,  113,    2, 0x08 /* Private */,
       8,    0,  116,    2, 0x08 /* Private */,
       9,    0,  117,    2, 0x08 /* Private */,
      10,    0,  118,    2, 0x08 /* Private */,
      11,    0,  119,    2, 0x08 /* Private */,
      12,    0,  120,    2, 0x08 /* Private */,
      13,    0,  121,    2, 0x08 /* Private */,
      14,    0,  122,    2, 0x08 /* Private */,
      15,    0,  123,    2, 0x08 /* Private */,
      16,    0,  124,    2, 0x08 /* Private */,
      17,    0,  125,    2, 0x08 /* Private */,
      18,    0,  126,    2, 0x08 /* Private */,
      19,    0,  127,    2, 0x08 /* Private */,
      20,    0,  128,    2, 0x08 /* Private */,
      21,    0,  129,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->on_volume_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_midichannel_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->on_program_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_testButton_clicked(); break;
        case 5: _t->on_testButton_2_clicked(); break;
        case 6: _t->on_eChord_clicked(); break;
        case 7: _t->on_fChord_clicked(); break;
        case 8: _t->on_gChord_clicked(); break;
        case 9: _t->on_aChord_clicked(); break;
        case 10: _t->on_oneUp_clicked(); break;
        case 11: _t->on_oneDown_clicked(); break;
        case 12: _t->on_twoUp_clicked(); break;
        case 13: _t->on_twoDown_clicked(); break;
        case 14: _t->on_threeUp_clicked(); break;
        case 15: _t->on_threeDown_clicked(); break;
        case 16: _t->on_fourUp_clicked(); break;
        case 17: _t->on_fourDown_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
