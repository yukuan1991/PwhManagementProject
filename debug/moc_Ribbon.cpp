/****************************************************************************
** Meta object code from reading C++ file 'Ribbon.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../interface_control/Ribbon.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Ribbon.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Ribbon_t {
    QByteArrayData data[8];
    char stringdata0[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Ribbon_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Ribbon_t qt_meta_stringdata_Ribbon = {
    {
QT_MOC_LITERAL(0, 0, 6), // "Ribbon"
QT_MOC_LITERAL(1, 7, 7), // "fileNew"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 8), // "fileOpen"
QT_MOC_LITERAL(4, 25, 8), // "fileSave"
QT_MOC_LITERAL(5, 34, 10), // "fileSaveAs"
QT_MOC_LITERAL(6, 45, 8), // "fileExit"
QT_MOC_LITERAL(7, 54, 15) // "subwindowActive"

    },
    "Ribbon\0fileNew\0\0fileOpen\0fileSave\0"
    "fileSaveAs\0fileExit\0subwindowActive"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Ribbon[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,
       6,    0,   48,    2, 0x06 /* Public */,
       7,    1,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void Ribbon::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Ribbon *_t = static_cast<Ribbon *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->fileNew(); break;
        case 1: _t->fileOpen(); break;
        case 2: _t->fileSave(); break;
        case 3: _t->fileSaveAs(); break;
        case 4: _t->fileExit(); break;
        case 5: _t->subwindowActive((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ribbon::fileNew)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ribbon::fileOpen)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ribbon::fileSave)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ribbon::fileSaveAs)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Ribbon::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ribbon::fileExit)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Ribbon::*_t)(bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Ribbon::subwindowActive)) {
                *result = 5;
                return;
            }
        }
    }
}

const QMetaObject Ribbon::staticMetaObject = {
    { &QTabWidget::staticMetaObject, qt_meta_stringdata_Ribbon.data,
      qt_meta_data_Ribbon,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Ribbon::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Ribbon::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Ribbon.stringdata0))
        return static_cast<void*>(const_cast< Ribbon*>(this));
    return QTabWidget::qt_metacast(_clname);
}

int Ribbon::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabWidget::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void Ribbon::fileNew()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Ribbon::fileOpen()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Ribbon::fileSave()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Ribbon::fileSaveAs()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Ribbon::fileExit()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Ribbon::subwindowActive(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}
struct qt_meta_stringdata_RibbonButton_t {
    QByteArrayData data[1];
    char stringdata0[13];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RibbonButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RibbonButton_t qt_meta_stringdata_RibbonButton = {
    {
QT_MOC_LITERAL(0, 0, 12) // "RibbonButton"

    },
    "RibbonButton"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RibbonButton[] = {

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

void RibbonButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RibbonButton::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_RibbonButton.data,
      qt_meta_data_RibbonButton,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RibbonButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RibbonButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RibbonButton.stringdata0))
        return static_cast<void*>(const_cast< RibbonButton*>(this));
    return QPushButton::qt_metacast(_clname);
}

int RibbonButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RibbonMenu_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RibbonMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RibbonMenu_t qt_meta_stringdata_RibbonMenu = {
    {
QT_MOC_LITERAL(0, 0, 10) // "RibbonMenu"

    },
    "RibbonMenu"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RibbonMenu[] = {

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

void RibbonMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RibbonMenu::staticMetaObject = {
    { &QMenu::staticMetaObject, qt_meta_stringdata_RibbonMenu.data,
      qt_meta_data_RibbonMenu,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RibbonMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RibbonMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RibbonMenu.stringdata0))
        return static_cast<void*>(const_cast< RibbonMenu*>(this));
    return QMenu::qt_metacast(_clname);
}

int RibbonMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RibbonTool_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RibbonTool_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RibbonTool_t qt_meta_stringdata_RibbonTool = {
    {
QT_MOC_LITERAL(0, 0, 10) // "RibbonTool"

    },
    "RibbonTool"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RibbonTool[] = {

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

void RibbonTool::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RibbonTool::staticMetaObject = {
    { &QToolButton::staticMetaObject, qt_meta_stringdata_RibbonTool.data,
      qt_meta_data_RibbonTool,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RibbonTool::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RibbonTool::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RibbonTool.stringdata0))
        return static_cast<void*>(const_cast< RibbonTool*>(this));
    return QToolButton::qt_metacast(_clname);
}

int RibbonTool::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QToolButton::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RibbonBar_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RibbonBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RibbonBar_t qt_meta_stringdata_RibbonBar = {
    {
QT_MOC_LITERAL(0, 0, 9) // "RibbonBar"

    },
    "RibbonBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RibbonBar[] = {

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

void RibbonBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RibbonBar::staticMetaObject = {
    { &QTabBar::staticMetaObject, qt_meta_stringdata_RibbonBar.data,
      qt_meta_data_RibbonBar,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RibbonBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RibbonBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RibbonBar.stringdata0))
        return static_cast<void*>(const_cast< RibbonBar*>(this));
    return QTabBar::qt_metacast(_clname);
}

int RibbonBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTabBar::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RibbonEdit_t {
    QByteArrayData data[1];
    char stringdata0[11];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RibbonEdit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RibbonEdit_t qt_meta_stringdata_RibbonEdit = {
    {
QT_MOC_LITERAL(0, 0, 10) // "RibbonEdit"

    },
    "RibbonEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RibbonEdit[] = {

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

void RibbonEdit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RibbonEdit::staticMetaObject = {
    { &QLineEdit::staticMetaObject, qt_meta_stringdata_RibbonEdit.data,
      qt_meta_data_RibbonEdit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RibbonEdit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RibbonEdit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RibbonEdit.stringdata0))
        return static_cast<void*>(const_cast< RibbonEdit*>(this));
    return QLineEdit::qt_metacast(_clname);
}

int RibbonEdit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QLineEdit::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_LayoutHorizontal_t {
    QByteArrayData data[1];
    char stringdata0[17];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayoutHorizontal_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayoutHorizontal_t qt_meta_stringdata_LayoutHorizontal = {
    {
QT_MOC_LITERAL(0, 0, 16) // "LayoutHorizontal"

    },
    "LayoutHorizontal"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayoutHorizontal[] = {

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

void LayoutHorizontal::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject LayoutHorizontal::staticMetaObject = {
    { &QHBoxLayout::staticMetaObject, qt_meta_stringdata_LayoutHorizontal.data,
      qt_meta_data_LayoutHorizontal,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *LayoutHorizontal::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayoutHorizontal::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_LayoutHorizontal.stringdata0))
        return static_cast<void*>(const_cast< LayoutHorizontal*>(this));
    return QHBoxLayout::qt_metacast(_clname);
}

int LayoutHorizontal::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QHBoxLayout::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_RibbonMenuItem_t {
    QByteArrayData data[1];
    char stringdata0[15];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_RibbonMenuItem_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_RibbonMenuItem_t qt_meta_stringdata_RibbonMenuItem = {
    {
QT_MOC_LITERAL(0, 0, 14) // "RibbonMenuItem"

    },
    "RibbonMenuItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_RibbonMenuItem[] = {

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

void RibbonMenuItem::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject RibbonMenuItem::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_RibbonMenuItem.data,
      qt_meta_data_RibbonMenuItem,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *RibbonMenuItem::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *RibbonMenuItem::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_RibbonMenuItem.stringdata0))
        return static_cast<void*>(const_cast< RibbonMenuItem*>(this));
    return QWidget::qt_metacast(_clname);
}

int RibbonMenuItem::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
