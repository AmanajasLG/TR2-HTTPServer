#include "proxy.hpp"
#include "ui_proxy.h"
#include <qt4/QtGui/QMessageBox>

Proxy::Proxy(QWidget *parent) : QMainWindow(parent),
                                ui(new Ui::Proxy)

{
    ui->setupUi(this);
}

Proxy::~Proxy()
{
    delete ui;
}

void Proxy::on_send_request_clicked()
{
    char *request = ui->request->toPlainText().toLocal8Bit().data();
    ui->request->clear();
    emit RequestReady(request);
}

void Proxy::on_send_reply_clicked()
{
    emit ResponseReady(ui->reply->toPlainText().toLocal8Bit().data());
    ui->reply->clear();
}

void Proxy::SetRequestContent(char *buffer)
{
    ui->request->setText(QString::fromStdString(string(buffer)));
}

void Proxy::SetResponseContent(char *buffer)
{
    ui->reply->setText(QString::fromStdString(string(buffer)));
}

void Proxy::on_spider_clicked()
{
    if (ui->url->toPlainText() == "")
    {
        QMessageBox msg;
        msg.setStyleSheet("QLabel{width: 80px }");
        msg.setText("Insira uma url!");
        msg.exec();
        return;
    }

    ui->stackedWidget->setCurrentIndex(1);
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
    ui->url->clear();
}
