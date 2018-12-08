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

  void RequestIncoming(const char *buffer);

  void SendRequest(const char *buffer);

  void ResponseIncoming(const char *buffer);

  void SendResponse(const char *buffer);

signals:
  void RequestShouldShow(const char *buffer);

  void SendRequestToServer(const char *buffer);

  void ResponseShouldShow(const char *buffer);

  void SendResponseToClient(const char *buffer);

private:
  SocketServer *server;
  SocketClient *client;
};

#endif // INSPECTOR_H
