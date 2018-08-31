/****************************************************************************
** Meta object code from reading C++ file 'custom_menus.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../../modules/gui/qt/components/custom_menus.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'custom_menus.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_RendererAction_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RendererAction_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RendererAction_t qt_meta_stringdata_RendererAction = {
    {
QT_MOC_LITERAL(0, 0, 14) // "RendererAction"

    },
    "RendererAction"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RendererAction[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void RendererAction::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RendererAction::staticMetaObject = {
    { &QAction::staticMetaObject, qt_meta_stringdata_RendererAction.data,
      qt_meta_data_RendererAction,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RendererAction::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RendererAction::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RendererAction.stringdata0))
        return static_cast<void*>(this);
    return QAction::qt_metacast(_clname);
}

int RendererAction::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAction::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RendererMenu_t {
    QByteArrayData data[8];
    char stringdata0[109];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RendererMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RendererMenu_t qt_meta_stringdata_RendererMenu = {
    {
QT_MOC_LITERAL(0, 0, 12), // "RendererMenu"
QT_MOC_LITERAL(1, 13, 15), // "addRendererItem"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 20), // "vlc_renderer_item_t*"
QT_MOC_LITERAL(4, 51, 18), // "removeRendererItem"
QT_MOC_LITERAL(5, 70, 12), // "updateStatus"
QT_MOC_LITERAL(6, 83, 16), // "RendererSelected"
QT_MOC_LITERAL(7, 100, 8) // "QAction*"

    },
    "RendererMenu\0addRendererItem\0\0"
    "vlc_renderer_item_t*\0removeRendererItem\0"
    "updateStatus\0RendererSelected\0QAction*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RendererMenu[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       4,    1,   37,    2, 0x08 /* Private */,
       5,    1,   40,    2, 0x08 /* Private */,
       6,    1,   43,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, 0x80000000 | 7,    2,

       0        // eod
};

void RendererMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        RendererMenu *_t = static_cast<RendererMenu *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->addRendererItem((*reinterpret_cast< vlc_renderer_item_t*(*)>(_a[1]))); break;
        case 1: _t->removeRendererItem((*reinterpret_cast< vlc_renderer_item_t*(*)>(_a[1]))); break;
        case 2: _t->updateStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->RendererSelected((*reinterpret_cast< QAction*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject RendererMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_RendererMenu.data,
      qt_meta_data_RendererMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RendererMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RendererMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RendererMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int RendererMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
