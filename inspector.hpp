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

  void RequestIncoming(QString buffer);

  void SendRequest(QString buffer);

  void ResponseIncoming(QString buffer);

  void SendResponse(QString buffer);

signals:
  void RequestShouldShow(QString buffer);

  void SendRequestToServer(QString buffer);

  void ResponseShouldShow(QString buffer);

  void SendResponseToClient(QString buffer);

private:
  SocketServer *server;
  SocketClient *client;
};

#endif // INSPECTOR_H
