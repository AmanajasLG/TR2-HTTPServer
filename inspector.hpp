#ifndef INSPECTOR_H
#define INSPECTOR_H
#include <QtCore>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <signal.h>
#include <string>
#include "socketServer.hpp"
#include "socketClient.hpp"

using namespace std;

class Inspector : public QThread
{
  Q_OBJECT

public:
  Inspector(int numPort);
  ~Inspector();

  void run();

private slots:

  void RequestIncoming(char *buffer);

  void SendRequest(char *buffer);

  void ResponseIncoming(char *buffer);

  void SendResponse(char *buffer);

signals:
  void RequestShouldShow(char *buffer);

  void SendRequestToServer(char *buffer);

  void ResponseShouldShow(char *buffer);

  void SendResponseToServer(char *buffer);

private:
};

#endif // INSPECTOR_H
