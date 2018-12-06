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
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      14,    7,    6,    6, 0x05,
      34,    7,    6,    6, 0x05,

 // slots: signature, parameters, type, tag, flags
      55,    7,    6,    6, 0x0a,
      80,    7,    6,    6, 0x0a,
     106,    6,    6,    6, 0x0a,
     126,    6,    6,    6, 0x0a,
     151,    6,    6,    6, 0x0a,
     176,    6,    6,    6, 0x0a,
     202,    6,    6,    6, 0x0a,
     226,    6,    6,    6, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_Proxy[] = {
    "Proxy\0\0buffer\0RequestReady(char*)\0"
    "ResponseReady(char*)\0SetRequestContent(char*)\0"
    "SetResponseContent(char*)\0on_spider_clicked()\0"
    "on_back_init_1_clicked()\0"
    "on_back_init_2_clicked()\0"
    "on_send_request_clicked()\0"
    "on_send_reply_clicked()\0on_dump_clicked()\0"
};

void Proxy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Proxy *_t = static_cast<Proxy *>(_o);
        switch (_id) {
        case 0: _t->RequestReady((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->ResponseReady((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->SetRequestContent((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 3: _t->SetResponseContent((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 4: _t->on_spider_clicked(); break;
        case 5: _t->on_back_init_1_clicked(); break;
        case 6: _t->on_back_init_2_clicked(); break;
        case 7: _t->on_send_request_clicked(); break;
        case 8: _t->on_send_reply_clicked(); break;
        case 9: _t->on_dump_clicked(); break;
        default: ;
        }
    }
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
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void Proxy::RequestReady(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Proxy::ResponseReady(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
