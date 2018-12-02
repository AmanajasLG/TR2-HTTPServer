#include "proxy.hpp"
#include "ui_proxy.h"
#include <qt4/QtGui/QMessageBox>

Proxy::Proxy(QWidget *parent) : QMainWindow(parent),
                                ui(new Ui::Proxy)
{
    ui->setupUi(this);
    inspec = new Inspector();
    dump = new Dump();
    spider = new Spider();

    inspec->start();
    dump->start();
    spider->start();
}

Proxy::~Proxy()
{
    delete ui;
}

void Proxy::on_spider_clicked()
{
    if (ui->url->toPlainText() == "")
    {
        QMessageBox msg;
        msg.setStyleSheet("QMessageBox{text-align: center; }");
        msg.setText("Insira uma url!");
        msg.exec();
        return;
    }

    ui->stackedWidget->setCurrentIndex(1);
    spider->SetUrl(ui->url->toPlainText());
    ui->url->clear();
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
    if (ui->url->toPlainText() == "")
    {
        QMessageBox msg;
        msg.setText("Insira uma url!");
        msg.exec();
        return;
    }

    ui->stackedWidget->setCurrentIndex(2);
    spider->SetUrl(ui->url->toPlainText());
    ui->url->clear();
}
