/****************************************************************************
** Meta object code from reading C++ file 'inspector.hpp'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "inspector.hpp"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'inspector.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Inspector[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   11,   10,   10, 0x05,
      43,   11,   10,   10, 0x05,
      70,   11,   10,   10, 0x05,
      96,   11,   10,   10, 0x05,

 // slots: signature, parameters, type, tag, flags
     124,   11,   10,   10, 0x08,
     147,   11,   10,   10, 0x08,
     166,   11,   10,   10, 0x08,
     190,   11,   10,   10, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_Inspector[] = {
    "Inspector\0\0buffer\0RequestShouldShow(char*)\0"
    "SendRequestToServer(char*)\0"
    "ResponseShouldShow(char*)\0"
    "SendResponseToServer(char*)\0"
    "RequestIncoming(char*)\0SendRequest(char*)\0"
    "ResponseIncoming(char*)\0SendResponse(char*)\0"
};

void Inspector::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        Inspector *_t = static_cast<Inspector *>(_o);
        switch (_id) {
        case 0: _t->RequestShouldShow((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 1: _t->SendRequestToServer((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 2: _t->ResponseShouldShow((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 3: _t->SendResponseToServer((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 4: _t->RequestIncoming((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 5: _t->SendRequest((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 6: _t->ResponseIncoming((*reinterpret_cast< char*(*)>(_a[1]))); break;
        case 7: _t->SendResponse((*reinterpret_cast< char*(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData Inspector::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject Inspector::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_Inspector,
      qt_meta_data_Inspector, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Inspector::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Inspector::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Inspector::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Inspector))
        return static_cast<void*>(const_cast< Inspector*>(this));
    return QThread::qt_metacast(_clname);
}

int Inspector::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void Inspector::RequestShouldShow(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Inspector::SendRequestToServer(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Inspector::ResponseShouldShow(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Inspector::SendResponseToServer(char * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
