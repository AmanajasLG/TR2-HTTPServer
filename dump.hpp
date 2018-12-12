#ifndef DUMP_H
#define DUMP_H
#include <QtCore>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

using namespace std;

class Dump : public QThread
{
  Q_OBJECT
public:
  Dump(int numPort = 8228);
  void run();
  void error(const char *msg)
  {
    perror(msg);
    close(serverSocket);
    terminate();
  }

  void createF(char *path, char *resp, char *host);
  void parseMes(char *mes, char *host);
  void getMes(char *host, char *path);

public slots:
  void ConfigURL(QString urlEdit);

private:
  int numPort;
  char assets[100000];
  char fassets[100000];
  char mes[100000];
  int count;
  char status[100000];
};

#endif // DUMP_H
