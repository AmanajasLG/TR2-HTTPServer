#ifndef PROXY_H
#define PROXY_H

#include <QMainWindow>
#include "inspector.hpp"
#include "dump.hpp"
#include "spider.hpp"
#include <QTimer>

namespace Ui
{
class Proxy;
}

class Proxy : public QMainWindow
{
  Q_OBJECT

public:
  Proxy(QWidget *parent = nullptr);
  ~Proxy();

public slots:

  void SetRequestContent(QString buffer);

  void SetResponseContent(QString buffer);

  void SetTreeContent(QString buffer);

  void on_spider_clicked();

  void on_back_init_1_clicked();

  void on_back_init_2_clicked();

  void on_send_request_clicked();

  void on_send_reply_clicked();

  void on_start_clicked();

  void on_dump_clicked();

  void on_dump_2_clicked();

signals:
  void StartProxy();

  void StartSpider(QString url);

  void StartDump(QString url);

  void RequestReady(QString buffer);

  void ResponseReady(QString buffer);

private:
  Ui::Proxy *ui;
  QString url;
};

#endif // PROXY_H
