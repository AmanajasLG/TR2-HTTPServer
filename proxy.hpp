#ifndef PROXY_H
#define PROXY_H

#include <QMainWindow>
#include "inspector.hpp"
#include "dump.hpp"
#include "spider.hpp"

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
};

#endif // PROXY_H
