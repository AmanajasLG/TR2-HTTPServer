#ifndef PROXY_H
#define PROXY_H

#include <QMainWindow>
#include "inspector.hpp"
#include "dump.hpp"
#include "spider.hpp"

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

    void SetPort(int numPort = 8228) { this->numPort = numPort; }
    void InitThreads();

  private slots:
    void on_spider_clicked();

    void on_back_init_1_clicked();

    void on_back_init_2_clicked();

    void on_dump_clicked();

  private:
    Ui::Proxy *ui;
    Inspector *inspec;
    Dump *dump;
    Spider *spider;
    int numPort;
};

#endif // PROXY_H
