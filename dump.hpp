#ifndef DUMP_H
#define DUMP_H
#include <QtCore>

class Dump : public QThread
{
public:
    Dump();
    void run();
};

#endif // DUMP_H
