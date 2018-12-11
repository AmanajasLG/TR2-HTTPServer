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
#include <fstream>
#include <iterator>
#include <set>
#include <regex>
#include <cstdio>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <vector>

using namespace std;

class Spider : public QThread
{
  Q_OBJECT

public:
  struct Page
  {
    Page *father;
    int lvl;
    string name;
  };

  Spider();
  void run();

  void ConfigURL();

  void Parser(char *req, char *host);
  void ExecSpider(char *host, char *path, int lvl, Page *father);
  void BuildTree();
  std::set<std::string> ExtractHyperlinks(std::string text);

public slots:
  void SetUrl(QString url);
signals:
  void ShowTree(QString tree);

private:
  string url;
  char assets[1000000];
  char fassets[1000000];
  char req[1000000];
  vector<Page> siteList;
  vector<Page> siteListOld;
  int count;
};

#endif // SPIDER_H
