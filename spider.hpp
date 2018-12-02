#ifndef SPIDER_H
#define SPIDER_H
#include <QtCore>
#include <iostream>

using namespace std;

class Spider : public QThread
{
  public:
    Spider();

    void run();

    void SetUrl(QString url)
    {
        this->url = url.toStdString();
        cout << this->url << endl;
    }

  private:
    string url;
};

#endif // SPIDER_H
