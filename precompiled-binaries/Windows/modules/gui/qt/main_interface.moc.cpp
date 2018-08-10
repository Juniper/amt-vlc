/****************************************************************************
** Meta object code from reading C++ file 'main_interface.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../modules/gui/qt/main_interface.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_interface.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainInterface_t {
    QByteArrayData data[65];
    char stringdata0[965];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainInterface_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainInterface_t qt_meta_stringdata_MainInterface = {
    {
QT_MOC_LITERAL(0, 0, 13), // "MainInterface"
QT_MOC_LITERAL(1, 14, 11), // "askGetVideo"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 14), // "vout_window_t*"
QT_MOC_LITERAL(4, 42, 5), // "bool*"
QT_MOC_LITERAL(5, 48, 15), // "askReleaseVideo"
QT_MOC_LITERAL(6, 64, 16), // "askVideoToResize"
QT_MOC_LITERAL(7, 81, 21), // "askVideoSetFullScreen"
QT_MOC_LITERAL(8, 103, 13), // "askVideoOnTop"
QT_MOC_LITERAL(9, 117, 18), // "minimalViewToggled"
QT_MOC_LITERAL(10, 136, 26), // "fullscreenInterfaceToggled"
QT_MOC_LITERAL(11, 163, 9), // "askToQuit"
QT_MOC_LITERAL(12, 173, 7), // "askBoss"
QT_MOC_LITERAL(13, 181, 8), // "askRaise"
QT_MOC_LITERAL(14, 190, 10), // "kc_pressed"
QT_MOC_LITERAL(15, 201, 12), // "dockPlaylist"
QT_MOC_LITERAL(16, 214, 8), // "b_docked"
QT_MOC_LITERAL(17, 223, 17), // "toggleMinimalView"
QT_MOC_LITERAL(18, 241, 14), // "togglePlaylist"
QT_MOC_LITERAL(19, 256, 23), // "toggleUpdateSystrayMenu"
QT_MOC_LITERAL(20, 280, 21), // "showUpdateSystrayMenu"
QT_MOC_LITERAL(21, 302, 21), // "hideUpdateSystrayMenu"
QT_MOC_LITERAL(22, 324, 21), // "toggleAdvancedButtons"
QT_MOC_LITERAL(23, 346, 25), // "toggleInterfaceFullScreen"
QT_MOC_LITERAL(24, 372, 9), // "toggleFSC"
QT_MOC_LITERAL(25, 382, 23), // "setInterfaceAlwaysOnTop"
QT_MOC_LITERAL(26, 406, 22), // "setStatusBarVisibility"
QT_MOC_LITERAL(27, 429, 9), // "b_visible"
QT_MOC_LITERAL(28, 439, 21), // "setPlaylistVisibility"
QT_MOC_LITERAL(29, 461, 12), // "getVideoSlot"
QT_MOC_LITERAL(30, 474, 7), // "i_width"
QT_MOC_LITERAL(31, 482, 8), // "i_height"
QT_MOC_LITERAL(32, 491, 16), // "releaseVideoSlot"
QT_MOC_LITERAL(33, 508, 8), // "emitBoss"
QT_MOC_LITERAL(34, 517, 9), // "emitRaise"
QT_MOC_LITERAL(35, 527, 11), // "reloadPrefs"
QT_MOC_LITERAL(36, 539, 18), // "toolBarConfUpdated"
QT_MOC_LITERAL(37, 558, 5), // "debug"
QT_MOC_LITERAL(38, 564, 16), // "recreateToolbars"
QT_MOC_LITERAL(39, 581, 7), // "setName"
QT_MOC_LITERAL(40, 589, 18), // "setVLCWindowsTitle"
QT_MOC_LITERAL(41, 608, 5), // "title"
QT_MOC_LITERAL(42, 614, 18), // "handleSystrayClick"
QT_MOC_LITERAL(43, 633, 33), // "QSystemTrayIcon::ActivationRe..."
QT_MOC_LITERAL(44, 667, 24), // "updateSystrayTooltipName"
QT_MOC_LITERAL(45, 692, 26), // "updateSystrayTooltipStatus"
QT_MOC_LITERAL(46, 719, 16), // "showCryptedLabel"
QT_MOC_LITERAL(47, 736, 14), // "handleKeyPress"
QT_MOC_LITERAL(48, 751, 10), // "QKeyEvent*"
QT_MOC_LITERAL(49, 762, 13), // "showBuffering"
QT_MOC_LITERAL(50, 776, 11), // "resizeStack"
QT_MOC_LITERAL(51, 788, 1), // "w"
QT_MOC_LITERAL(52, 790, 1), // "h"
QT_MOC_LITERAL(53, 792, 12), // "setVideoSize"
QT_MOC_LITERAL(54, 805, 16), // "videoSizeChanged"
QT_MOC_LITERAL(55, 822, 18), // "setVideoFullScreen"
QT_MOC_LITERAL(56, 841, 13), // "setVideoOnTop"
QT_MOC_LITERAL(57, 855, 7), // "setBoss"
QT_MOC_LITERAL(58, 863, 8), // "setRaise"
QT_MOC_LITERAL(59, 872, 22), // "voutReleaseMouseEvents"
QT_MOC_LITERAL(60, 895, 15), // "showResumePanel"
QT_MOC_LITERAL(61, 911, 7), // "int64_t"
QT_MOC_LITERAL(62, 919, 15), // "hideResumePanel"
QT_MOC_LITERAL(63, 935, 14), // "resumePlayback"
QT_MOC_LITERAL(64, 950, 14) // "onInputChanged"

    },
    "MainInterface\0askGetVideo\0\0vout_window_t*\0"
    "bool*\0askReleaseVideo\0askVideoToResize\0"
    "askVideoSetFullScreen\0askVideoOnTop\0"
    "minimalViewToggled\0fullscreenInterfaceToggled\0"
    "askToQuit\0askBoss\0askRaise\0kc_pressed\0"
    "dockPlaylist\0b_docked\0toggleMinimalView\0"
    "togglePlaylist\0toggleUpdateSystrayMenu\0"
    "showUpdateSystrayMenu\0hideUpdateSystrayMenu\0"
    "toggleAdvancedButtons\0toggleInterfaceFullScreen\0"
    "toggleFSC\0setInterfaceAlwaysOnTop\0"
    "setStatusBarVisibility\0b_visible\0"
    "setPlaylistVisibility\0getVideoSlot\0"
    "i_width\0i_height\0releaseVideoSlot\0"
    "emitBoss\0emitRaise\0reloadPrefs\0"
    "toolBarConfUpdated\0debug\0recreateToolbars\0"
    "setName\0setVLCWindowsTitle\0title\0"
    "handleSystrayClick\0QSystemTrayIcon::ActivationReason\0"
    "updateSystrayTooltipName\0"
    "updateSystrayTooltipStatus\0showCryptedLabel\0"
    "handleKeyPress\0QKeyEvent*\0showBuffering\0"
    "resizeStack\0w\0h\0setVideoSize\0"
    "videoSizeChanged\0setVideoFullScreen\0"
    "setVideoOnTop\0setBoss\0setRaise\0"
    "voutReleaseMouseEvents\0showResumePanel\0"
    "int64_t\0hideResumePanel\0resumePlayback\0"
    "onInputChanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainInterface[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      53,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      11,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    5,  279,    2, 0x06 /* Public */,
       5,    0,  290,    2, 0x06 /* Public */,
       6,    2,  291,    2, 0x06 /* Public */,
       7,    1,  296,    2, 0x06 /* Public */,
       8,    1,  299,    2, 0x06 /* Public */,
       9,    1,  302,    2, 0x06 /* Public */,
      10,    1,  305,    2, 0x06 /* Public */,
      11,    0,  308,    2, 0x06 /* Public */,
      12,    0,  309,    2, 0x06 /* Public */,
      13,    0,  310,    2, 0x06 /* Public */,
      14,    0,  311,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      15,    1,  312,    2, 0x0a /* Public */,
      15,    0,  315,    2, 0x2a /* Public | MethodCloned */,
      17,    1,  316,    2, 0x0a /* Public */,
      18,    0,  319,    2, 0x0a /* Public */,
      19,    0,  320,    2, 0x0a /* Public */,
      20,    0,  321,    2, 0x0a /* Public */,
      21,    0,  322,    2, 0x0a /* Public */,
      22,    0,  323,    2, 0x0a /* Public */,
      23,    0,  324,    2, 0x0a /* Public */,
      24,    0,  325,    2, 0x0a /* Public */,
      25,    1,  326,    2, 0x0a /* Public */,
      26,    1,  329,    2, 0x0a /* Public */,
      28,    1,  332,    2, 0x0a /* Public */,
      29,    5,  335,    2, 0x0a /* Public */,
      32,    0,  346,    2, 0x0a /* Public */,
      33,    0,  347,    2, 0x0a /* Public */,
      34,    0,  348,    2, 0x0a /* Public */,
      35,    0,  349,    2, 0x0a /* Public */,
      36,    0,  350,    2, 0x0a /* Public */,
      37,    0,  351,    2, 0x09 /* Protected */,
      38,    0,  352,    2, 0x09 /* Protected */,
      39,    1,  353,    2, 0x09 /* Protected */,
      40,    1,  356,    2, 0x09 /* Protected */,
      40,    0,  359,    2, 0x29 /* Protected | MethodCloned */,
      42,    1,  360,    2, 0x09 /* Protected */,
      44,    1,  363,    2, 0x09 /* Protected */,
      45,    1,  366,    2, 0x09 /* Protected */,
      46,    1,  369,    2, 0x09 /* Protected */,
      47,    1,  372,    2, 0x09 /* Protected */,
      49,    1,  375,    2, 0x09 /* Protected */,
      50,    2,  378,    2, 0x09 /* Protected */,
      53,    2,  383,    2, 0x09 /* Protected */,
      54,    2,  388,    2, 0x09 /* Protected */,
      55,    1,  393,    2, 0x09 /* Protected */,
      56,    1,  396,    2, 0x09 /* Protected */,
      57,    0,  399,    2, 0x09 /* Protected */,
      58,    0,  400,    2, 0x09 /* Protected */,
      59,    0,  401,    2, 0x09 /* Protected */,
      60,    1,  402,    2, 0x09 /* Protected */,
      62,    0,  405,    2, 0x09 /* Protected */,
      63,    0,  406,    2, 0x09 /* Protected */,
      64,    1,  407,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, QMetaType::UInt, QMetaType::Bool, 0x80000000 | 4,    2,    2,    2,    2,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,   16,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, QMetaType::Bool,   27,
    QMetaType::Void, 0x80000000 | 3, QMetaType::UInt, QMetaType::UInt, QMetaType::Bool, 0x80000000 | 4,    2,   30,   31,    2,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::QString,   41,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 43,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, 0x80000000 | 48,    2,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   51,   52,
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 61,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void MainInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainInterface *_t = static_cast<MainInterface *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->askGetVideo((*reinterpret_cast< vout_window_t*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool*(*)>(_a[5]))); break;
        case 1: _t->askReleaseVideo(); break;
        case 2: _t->askVideoToResize((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 3: _t->askVideoSetFullScreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->askVideoOnTop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->minimalViewToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->fullscreenInterfaceToggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->askToQuit(); break;
        case 8: _t->askBoss(); break;
        case 9: _t->askRaise(); break;
        case 10: _t->kc_pressed(); break;
        case 11: _t->dockPlaylist((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->dockPlaylist(); break;
        case 13: _t->toggleMinimalView((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 14: _t->togglePlaylist(); break;
        case 15: _t->toggleUpdateSystrayMenu(); break;
        case 16: _t->showUpdateSystrayMenu(); break;
        case 17: _t->hideUpdateSystrayMenu(); break;
        case 18: _t->toggleAdvancedButtons(); break;
        case 19: _t->toggleInterfaceFullScreen(); break;
        case 20: _t->toggleFSC(); break;
        case 21: _t->setInterfaceAlwaysOnTop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 22: _t->setStatusBarVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 23: _t->setPlaylistVisibility((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 24: _t->getVideoSlot((*reinterpret_cast< vout_window_t*(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2])),(*reinterpret_cast< uint(*)>(_a[3])),(*reinterpret_cast< bool(*)>(_a[4])),(*reinterpret_cast< bool*(*)>(_a[5]))); break;
        case 25: _t->releaseVideoSlot(); break;
        case 26: _t->emitBoss(); break;
        case 27: _t->emitRaise(); break;
        case 28: _t->reloadPrefs(); break;
        case 29: _t->toolBarConfUpdated(); break;
        case 30: _t->debug(); break;
        case 31: _t->recreateToolbars(); break;
        case 32: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 33: _t->setVLCWindowsTitle((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 34: _t->setVLCWindowsTitle(); break;
        case 35: _t->handleSystrayClick((*reinterpret_cast< QSystemTrayIcon::ActivationReason(*)>(_a[1]))); break;
        case 36: _t->updateSystrayTooltipName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 37: _t->updateSystrayTooltipStatus((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 38: _t->showCryptedLabel((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 39: _t->handleKeyPress((*reinterpret_cast< QKeyEvent*(*)>(_a[1]))); break;
        case 40: _t->showBuffering((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 41: _t->resizeStack((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 42: _t->setVideoSize((*reinterpret_cast< uint(*)>(_a[1])),(*reinterpret_cast< uint(*)>(_a[2]))); break;
        case 43: _t->videoSizeChanged((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 44: _t->setVideoFullScreen((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 45: _t->setVideoOnTop((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 46: _t->setBoss(); break;
        case 47: _t->setRaise(); break;
        case 48: _t->voutReleaseMouseEvents(); break;
        case 49: _t->showResumePanel((*reinterpret_cast< int64_t(*)>(_a[1]))); break;
        case 50: _t->hideResumePanel(); break;
        case 51: _t->resumePlayback(); break;
        case 52: _t->onInputChanged((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (MainInterface::*_t)(vout_window_t * , unsigned  , unsigned  , bool , bool * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askGetVideo)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askReleaseVideo)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)(unsigned int , unsigned int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askVideoToResize)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askVideoSetFullScreen)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askVideoOnTop)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::minimalViewToggled)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::fullscreenInterfaceToggled)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askToQuit)) {
                *result = 7;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askBoss)) {
                *result = 8;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::askRaise)) {
                *result = 9;
                return;
            }
        }
        {
            typedef void (MainInterface::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainInterface::kc_pressed)) {
                *result = 10;
                return;
            }
        }
    }
}

const QMetaObject MainInterface::staticMetaObject = {
    { &QVLCMW::staticMetaObject, qt_meta_stringdata_MainInterface.data,
      qt_meta_data_MainInterface,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *MainInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainInterface.stringdata0))
        return static_cast<void*>(this);
    return QVLCMW::qt_metacast(_clname);
}

int MainInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QVLCMW::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 53)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 53;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 53)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 53;
    }
    return _id;
}

// SIGNAL 0
void MainInterface::askGetVideo(vout_window_t * _t1, unsigned  _t2, unsigned  _t3, bool _t4, bool * _t5)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainInterface::askReleaseVideo()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void MainInterface::askVideoToResize(unsigned int _t1, unsigned int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MainInterface::askVideoSetFullScreen(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MainInterface::askVideoOnTop(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MainInterface::minimalViewToggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MainInterface::fullscreenInterfaceToggled(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void MainInterface::askToQuit()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void MainInterface::askBoss()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void MainInterface::askRaise()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}

// SIGNAL 10
void MainInterface::kc_pressed()
{
    QMetaObject::activate(this, &staticMetaObject, 10, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
