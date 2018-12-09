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

  string GetHost(const char *buffer);

  void error(const char *msg)
  {
    perror(msg);
    terminate(1);
  }

public slots:
  void SendRequest(const char *buffer);

signals:
  void IncomingResponse(const char *buffer);

private:
  int clientSocket;
  struct sockaddr_in serv_addr;
  char buffer[100000];
  struct hostent *server;
  struct in_addr ipv4addr;
};

#endif // SOCKETCLIENT_H
