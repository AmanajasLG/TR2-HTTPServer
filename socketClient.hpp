#ifndef SOCKETCLIENT_H
#define SOCKETCLIENT_H
#include <QtCore>
#include <boost/algorithm/string.hpp>
#include <iostream>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <signal.h>
#include <string>
#include <syslog.h>
#include <err.h>

using namespace std;

class SocketClient : public QThread
{
  Q_OBJECT

public:
  SocketClient();

  void run();
  void GetResponse();

  string GetHost(QString buffer);
  void FirstPack();

  void error(const char *msg)
  {
    perror(msg);
    close(clientSocket);
    terminate();
  }

public slots:
  void SendRequest(QString buffer);

signals:
  void IncomingResponse(QString buffer);

private:
  int clientSocket;
  struct sockaddr_in serv_addr;
  QString buffer;
  struct hostent *server;
  struct in_addr ipv4addr;
};

#endif // SOCKETCLIENT_H
