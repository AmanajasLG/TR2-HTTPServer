#ifndef INSPECTOR_H
#define INSPECTOR_H
#include <QtCore>

class Inspector : public QThread
{
  public:
    Inspector(int numPort = 8228);

    void run();

    QString GetRequest();
    void SendRequest(QString request);
    QString GetReply();
    void SendReply(QString reply);

  private:
    int numPort;
};

#endif // INSPECTOR_H
