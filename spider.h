#ifndef SPIDER_H
#define SPIDER_H
#include <QtCore>

class Spider : public QThread
{
public:
    Spider();
    void SetUrl(QString url){this->url = url;}
private:
    QString url = "";
};

#endif // SPIDER_H
