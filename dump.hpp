#ifndef DUMP_H
#define DUMP_H
#include <QtCore>

class Dump : public QThread
{
  public:
    Dump(int numPort = 8228);
    void run();

  private:
    int numPort;
};

#endif // DUMP_H
