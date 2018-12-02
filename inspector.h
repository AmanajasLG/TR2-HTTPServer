#ifndef INSPECTOR_H
#define INSPECTOR_H
#include <QtCore>

class Inspector : public QThread
{
public:
    Inspector();
    QString GetRequest();
    void SendRequest(QString request);
    QString GetReply();
    void SendReply(QString reply);
};

#endif // INSPECTOR_H
