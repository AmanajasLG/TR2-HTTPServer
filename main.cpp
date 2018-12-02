#include "proxy.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Proxy proxy;
    proxy.show();

    return a.exec();
}
