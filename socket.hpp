#ifndef SOCKET_H
#define SOCKET_H
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
#include <fstream>

using namespace std;

class Socket : public QThread
{
  Q_OBJECT

public:
  Socket(int numPort = 8228);
  ~Socket();

  void run();
  void error(const char *msg)
  {
    perror(msg);
    close(serverSocket);
    terminate();
  }

  void GetRequest();
  void GetResponse();

  string GetHost(QString buffer);
  int GetSize(QString buffer);
  int FirstPack();
  void SendResponse(QString buffer);
  void SendRequest(QString buffer);

public slots:
  void SendRequestSlot(QString buffer) { SendRequest(buffer); }
  void SendResponseSlot(QString buffer) { SendResponse(buffer); }

signals:
  void IncomingRequest(QString buffer);
  void IncomingResponse(QString buffer);

private:
  int serverSocket;
  int clientServerSocket;
  int clientSocket;
  int numPort;
  socklen_t clilen;
  QString buffer;
  struct sockaddr_in serv_addr_server, cli_addr;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  int responseSize;
};

#endif // SOCKET_H
