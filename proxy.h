#ifndef PROXY_H
#define PROXY_H

#include <QMainWindow>
#include "inspector.h"
#include "dump.h"
#include "spider.h"

namespace Ui {
class Proxy;
}

class Proxy : public QMainWindow
{
    Q_OBJECT

public:
    explicit Proxy(QWidget *parent = nullptr);
    ~Proxy();

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
    QString urlSpider = "";
};

#endif // PROXY_H
