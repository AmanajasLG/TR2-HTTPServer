/****************************************************************************
** Meta object code from reading C++ file 'proxy.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "proxy.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'proxy.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Proxy[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       7,    6,    6,    6, 0x08,
      27,    6,    6,    6, 0x08,
      52,    6,    6,    6, 0x08,
      77,    6,    6,    6, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Proxy[] = {
    "Proxy\0\0on_spider_clicked()\0"
    "on_back_init_1_clicked()\0"
    "on_back_init_2_clicked()\0on_dump_clicked()\0"
};

void Proxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Proxy *_t = static_cast<Proxy *>(_o);
        switch (_id) {
        case 0: _t->on_spider_clicked(); break;
        case 1: _t->on_back_init_1_clicked(); break;
        case 2: _t->on_back_init_2_clicked(); break;
        case 3: _t->on_dump_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData Proxy::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Proxy::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Proxy,
      qt_meta_data_Proxy, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Proxy::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Proxy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Proxy::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Proxy))
        return static_cast<void*>(const_cast< Proxy*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Proxy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
