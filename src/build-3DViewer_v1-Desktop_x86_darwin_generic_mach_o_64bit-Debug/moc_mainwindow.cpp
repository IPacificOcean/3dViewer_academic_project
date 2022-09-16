/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../3DViewer_v1/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QScreen>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    const uint offsetsAndSize[38];
    char stringdata0[399];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 10), // "MainWindow"
QT_MOC_LITERAL(11, 19), // "on_openFile_clicked"
QT_MOC_LITERAL(31, 0), // ""
QT_MOC_LITERAL(32, 35), // "on_doubleSpinBox_Scale_valueC..."
QT_MOC_LITERAL(68, 10), // "valueScale"
QT_MOC_LITERAL(79, 17), // "on_update_clicked"
QT_MOC_LITERAL(97, 34), // "on_spinBox_line_width_valueCh..."
QT_MOC_LITERAL(132, 5), // "value"
QT_MOC_LITERAL(138, 34), // "on_spinBox_point_size_valueCh..."
QT_MOC_LITERAL(173, 16), // "on_color_clicked"
QT_MOC_LITERAL(190, 17), // "on_Pthoto_clicked"
QT_MOC_LITERAL(208, 13), // "create_screen"
QT_MOC_LITERAL(222, 28), // "on_stop_and_save_GIF_clicked"
QT_MOC_LITERAL(251, 8), // "save_gif"
QT_MOC_LITERAL(260, 23), // "on_optimization_clicked"
QT_MOC_LITERAL(284, 23), // "on_gebug_cactus_clicked"
QT_MOC_LITERAL(308, 42), // "on_comboBox_point_form_curren..."
QT_MOC_LITERAL(351, 5), // "index"
QT_MOC_LITERAL(357, 41) // "on_comboBox_line_form_current..."

    },
    "MainWindow\0on_openFile_clicked\0\0"
    "on_doubleSpinBox_Scale_valueChanged\0"
    "valueScale\0on_update_clicked\0"
    "on_spinBox_line_width_valueChanged\0"
    "value\0on_spinBox_point_size_valueChanged\0"
    "on_color_clicked\0on_Pthoto_clicked\0"
    "create_screen\0on_stop_and_save_GIF_clicked\0"
    "save_gif\0on_optimization_clicked\0"
    "on_gebug_cactus_clicked\0"
    "on_comboBox_point_form_currentIndexChanged\0"
    "index\0on_comboBox_line_form_currentIndexChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   98,    2, 0x08,    1 /* Private */,
       3,    1,   99,    2, 0x08,    2 /* Private */,
       5,    0,  102,    2, 0x08,    4 /* Private */,
       6,    1,  103,    2, 0x08,    5 /* Private */,
       8,    1,  106,    2, 0x08,    7 /* Private */,
       9,    0,  109,    2, 0x08,    9 /* Private */,
      10,    0,  110,    2, 0x08,   10 /* Private */,
      11,    0,  111,    2, 0x08,   11 /* Private */,
      12,    0,  112,    2, 0x08,   12 /* Private */,
      13,    0,  113,    2, 0x08,   13 /* Private */,
      14,    0,  114,    2, 0x08,   14 /* Private */,
      15,    0,  115,    2, 0x08,   15 /* Private */,
      16,    1,  116,    2, 0x08,   16 /* Private */,
      18,    1,  119,    2, 0x08,   18 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Double,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void, QMetaType::Int,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, QMetaType::Int,   17,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->on_openFile_clicked(); break;
        case 1: _t->on_doubleSpinBox_Scale_valueChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 2: _t->on_update_clicked(); break;
        case 3: _t->on_spinBox_line_width_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_spinBox_point_size_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_color_clicked(); break;
        case 6: _t->on_Pthoto_clicked(); break;
        case 7: _t->create_screen(); break;
        case 8: _t->on_stop_and_save_GIF_clicked(); break;
        case 9: _t->save_gif(); break;
        case 10: _t->on_optimization_clicked(); break;
        case 11: _t->on_gebug_cactus_clicked(); break;
        case 12: _t->on_comboBox_point_form_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->on_comboBox_line_form_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_MainWindow.offsetsAndSize,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MainWindow_t
, QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<double, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 14;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
