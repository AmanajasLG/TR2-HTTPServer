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

  void SetRequestContent(char *buffer);

  void SetResponseContent(char *buffer);

  void on_spider_clicked();

  void on_back_init_1_clicked();

  void on_back_init_2_clicked();

  void on_send_request_clicked();

  void on_send_reply_clicked();

  void on_dump_clicked();

signals:

  void RequestReady(char *buffer);

  void ResponseReady(char *buffer);

private:
  Ui::Proxy *ui;
};

#endif // PROXY_H
