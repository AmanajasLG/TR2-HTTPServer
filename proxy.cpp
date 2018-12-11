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

    QString fix = ui->request->toPlainText();

    fix.replace(QString("\n"), QString("\r\n"));

    emit RequestReady(fix);
    ui->request->clear();
}

void Proxy::on_send_reply_clicked()
{
    if (ui->reply->toPlainText() == "")
        return;
    QString fix = ui->reply->toPlainText();

    fix.replace(QString("\n"), QString("\r\n"));

    emit ResponseReady(fix);
    ui->reply->clear();
}

void Proxy::SetRequestContent(QString buffer)
{
    ui->request->setPlainText(buffer);
}

void Proxy::SetResponseContent(QString buffer)
{
    ui->reply->setPlainText(buffer);
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
    emit StartSpider(ui->url->toPlainText());
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

void Proxy::on_start_clicked()
{
    emit StartProxy();
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
