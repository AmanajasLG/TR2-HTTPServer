#ifndef SOCKETSERVER_H
#define SOCKETSERVER_H
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

using namespace std;

class SocketServer : public QThread
{
  Q_OBJECT

public:
  SocketServer(int numPort = 8228);
  ~SocketServer();

  void run();
  void error(const char *msg)
  {
    perror(msg);
    close(serverSocket);
    terminate();
  }

  void GetRequest();

public slots:
  void SendResponse(QString buffer);

signals:
  void IncomingRequest(QString buffer);

private:
  int serverSocket;
  int clientSocket;
  int numPort;
  socklen_t clilen;
  QString buffer;
  struct sockaddr_in serv_addr, cli_addr;
};

#endif // SOCKETSERVER_H
