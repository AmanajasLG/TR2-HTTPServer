#ifndef SPIDER_H
#define SPIDER_H
#include <QtCore>
#include <boost/algorithm/string.hpp>
#include <iostream>
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
#include <vector>
#include <fcntl.h>

using namespace std;

class Spider : public QThread
{
  Q_OBJECT

public:
  Spider();
  void run();

  void ConfigURL();

  void Parser(char *req, char *host);
  void ExecSpider(char *host, char *path, char *list);

public slots:
  void SetUrl(QString url);

private:
  string url;
  char assets[100000];
  char fassets[100000];
  char req[100000];
  char list[100000];
  int count;
};

#endif // SPIDER_H
