/********************************************************************************
** Form generated from reading UI file 'proxy.ui'
**
** Created by: Qt User Interface Compiler version 4.8.7
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROXY_H
#define UI_PROXY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QStackedWidget>
#include <QtGui/QTextEdit>
#include <QtGui/QTreeView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Proxy
{
public:
    QWidget *centralWidget;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QPushButton *spider;
    QPushButton *dump;
    QPushButton *send_request;
    QPushButton *send_reply;
    QTextEdit *url;
    QTextEdit *request;
    QTextEdit *reply;
    QWidget *page_2;
    QTreeView *tree;
    QPushButton *back_init_1;
    QPushButton *dump_2;
    QLabel *spider_label;
    QWidget *page_3;
    QPushButton *back_init_2;
    QTreeView *tree_2;
    QLabel *dump_label_2;

    void setupUi(QMainWindow *Proxy)
    {
        if (Proxy->objectName().isEmpty())
            Proxy->setObjectName(QString::fromUtf8("Proxy"));
        Proxy->resize(492, 613);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Proxy->sizePolicy().hasHeightForWidth());
        Proxy->setSizePolicy(sizePolicy);
        Proxy->setCursor(QCursor(Qt::ArrowCursor));
        centralWidget = new QWidget(Proxy);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        stackedWidget = new QStackedWidget(centralWidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));
        stackedWidget->setGeometry(QRect(0, 0, 491, 611));
        page = new QWidget();
        page->setObjectName(QString::fromUtf8("page"));
        spider = new QPushButton(page);
        spider->setObjectName(QString::fromUtf8("spider"));
        spider->setGeometry(QRect(310, 20, 75, 23));
        dump = new QPushButton(page);
        dump->setObjectName(QString::fromUtf8("dump"));
        dump->setGeometry(QRect(400, 20, 75, 23));
        send_request = new QPushButton(page);
        send_request->setObjectName(QString::fromUtf8("send_request"));
        send_request->setGeometry(QRect(88, 570, 75, 23));
        send_reply = new QPushButton(page);
        send_reply->setObjectName(QString::fromUtf8("send_reply"));
        send_reply->setGeometry(QRect(325, 570, 75, 23));
        url = new QTextEdit(page);
        url->setObjectName(QString::fromUtf8("url"));
        url->setGeometry(QRect(10, 20, 281, 21));
        url->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        request = new QTextEdit(page);
        request->setObjectName(QString::fromUtf8("request"));
        request->setGeometry(QRect(10, 70, 231, 491));
        reply = new QTextEdit(page);
        reply->setObjectName(QString::fromUtf8("reply"));
        reply->setGeometry(QRect(250, 70, 231, 491));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QString::fromUtf8("page_2"));
        tree = new QTreeView(page_2);
        tree->setObjectName(QString::fromUtf8("tree"));
        tree->setGeometry(QRect(10, 60, 471, 501));
        back_init_1 = new QPushButton(page_2);
        back_init_1->setObjectName(QString::fromUtf8("back_init_1"));
        back_init_1->setGeometry(QRect(320, 580, 75, 23));
        dump_2 = new QPushButton(page_2);
        dump_2->setObjectName(QString::fromUtf8("dump_2"));
        dump_2->setGeometry(QRect(410, 580, 75, 23));
        spider_label = new QLabel(page_2);
        spider_label->setObjectName(QString::fromUtf8("spider_label"));
        spider_label->setGeometry(QRect(10, 9, 391, 41));
        QFont font;
        font.setPointSize(17);
        font.setBold(true);
        font.setWeight(75);
        spider_label->setFont(font);
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QString::fromUtf8("page_3"));
        back_init_2 = new QPushButton(page_3);
        back_init_2->setObjectName(QString::fromUtf8("back_init_2"));
        back_init_2->setGeometry(QRect(400, 581, 75, 23));
        tree_2 = new QTreeView(page_3);
        tree_2->setObjectName(QString::fromUtf8("tree_2"));
        tree_2->setGeometry(QRect(10, 61, 471, 501));
        dump_label_2 = new QLabel(page_3);
        dump_label_2->setObjectName(QString::fromUtf8("dump_label_2"));
        dump_label_2->setGeometry(QRect(10, 10, 391, 41));
        dump_label_2->setFont(font);
        stackedWidget->addWidget(page_3);
        Proxy->setCentralWidget(centralWidget);

        retranslateUi(Proxy);

        QMetaObject::connectSlotsByName(Proxy);
    } // setupUi

    void retranslateUi(QMainWindow *Proxy)
    {
        Proxy->setWindowTitle(QApplication::translate("Proxy", "Proxy", 0, QApplication::UnicodeUTF8));
        spider->setText(QApplication::translate("Proxy", "SPIDER", 0, QApplication::UnicodeUTF8));
        dump->setText(QApplication::translate("Proxy", "DUMP", 0, QApplication::UnicodeUTF8));
        send_request->setText(QApplication::translate("Proxy", "REQUEST", 0, QApplication::UnicodeUTF8));
        send_reply->setText(QApplication::translate("Proxy", "REPLY", 0, QApplication::UnicodeUTF8));
        back_init_1->setText(QApplication::translate("Proxy", "BACK", 0, QApplication::UnicodeUTF8));
        dump_2->setText(QApplication::translate("Proxy", "DUMP", 0, QApplication::UnicodeUTF8));
        spider_label->setText(QApplication::translate("Proxy", "SPIDER", 0, QApplication::UnicodeUTF8));
        back_init_2->setText(QApplication::translate("Proxy", "BACK", 0, QApplication::UnicodeUTF8));
        dump_label_2->setText(QApplication::translate("Proxy", "DUMP", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Proxy: public Ui_Proxy {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROXY_H
