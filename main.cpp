#include "proxy.hpp"
#include "inspector.hpp"
#include "dump.hpp"
#include "spider.hpp"
#include <QApplication>
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Proxy proxy;
    int port;

    if (argc == 1)
    {
        port = 8228;
    }
    else if (argc == 3)
    {
        if (!boost::iequals(argv[1], "-p"))
        {
            cout << "Argumento " << argv[1] << " invalido! " << endl;
            cout << "Execucao deve ter formato ./aracne OU ./aracne -p <numero da porta>" << endl;
            return 0;
        }
        port = stoi(argv[2]);
    }
    else
    {
        cout << "Numero invalido de argumentos! " << endl;
        cout << "Execucao deve ter formato ./aracne OU ./aracne -p <numero da porta>" << endl;
        return 0;
    }

    proxy.show();
    Dump *dump = new Dump(port);
    Spider *spider = new Spider(port);
    Inspector *inspec = new Inspector(port);

    QObject::connect(inspec, SIGNAL(RequestShouldShow(QString)), &proxy, SLOT(SetRequestContent(QString)), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(RequestReady(QString)), inspec, SLOT(SendRequest(QString)), Qt::QueuedConnection);
    QObject::connect(inspec, SIGNAL(ResponseShouldShow(QString)), &proxy, SLOT(SetResponseContent(QString)), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(ResponseReady(QString)), inspec, SLOT(SendResponse(QString)), Qt::QueuedConnection);

    dump->start();
    spider->start();
    inspec->start();

    return a.exec();
}
