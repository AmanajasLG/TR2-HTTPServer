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
    if (ui->request->toPlainText() == "")
        return;

    sleep(0.2);
    emit RequestReady(ui->request->toPlainText().toLocal8Bit().data());
    ui->request->clear();
}

void Proxy::on_send_reply_clicked()
{
    if (ui->reply->toPlainText() == "")
        return;

    sleep(0.2);
    cout << "PROXY: " << ui->reply->toPlainText().toLocal8Bit().data() << endl;
    emit ResponseReady(ui->reply->toPlainText().toLocal8Bit().data());
    ui->reply->clear();
}

void Proxy::SetRequestContent(const char *buffer)
{
    sleep(0.2);
    ui->request->setPlainText(QString::fromStdString(string(buffer)));
}

void Proxy::SetResponseContent(const char *buffer)
{
    sleep(0.2);
    ui->reply->setPlainText(QString::fromStdString(string(buffer)));
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
