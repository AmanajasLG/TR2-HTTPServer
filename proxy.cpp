#include "proxy.h"
#include "ui_proxy.h"

Proxy::Proxy(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Proxy)
{
    ui->setupUi(this);

}

Proxy::~Proxy()
{
    delete ui;
}

void Proxy::on_spider_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    spider->SetUrl(ui->url->toPlainText());
    ui->tree->
}

void Proxy::on_back_init_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Proxy::on_back_init_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void Proxy::on_dump_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
