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
    proxy.show();
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

    Dump *dump = new Dump(port);
    Spider *spider = new Spider();
    Inspector *inspec = new Inspector(port);

    QObject::connect(inspec, SIGNAL(RequestShouldShow(QString)), &proxy, SLOT(SetRequestContent(QString)), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(RequestReady(QString)), inspec, SLOT(SendRequest(QString)), Qt::QueuedConnection);
    QObject::connect(inspec, SIGNAL(ResponseShouldShow(QString)), &proxy, SLOT(SetResponseContent(QString)), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(ResponseReady(QString)), inspec, SLOT(SendResponse(QString)), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(StartProxy()), inspec, SLOT(ProxyInit()), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(StartDump(QString)), dump, SLOT(ConfigURL(QString)), Qt::QueuedConnection);
    QObject::connect(&proxy, SIGNAL(StartSpider(QString)), spider, SLOT(SetUrl(QString)), Qt::QueuedConnection);
    QObject::connect(spider, SIGNAL(ShowTree(QString)), &proxy, SLOT(SetTreeContent(QString)), Qt::QueuedConnection);

    dump->start();
    spider->start();
    inspec->start();

    return a.exec();
}
