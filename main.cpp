#include "proxy.hpp"
#include <QApplication>
#include <boost/algorithm/string.hpp>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Proxy proxy;

    if (argc == 1)
    {
        proxy.SetPort();
    }
    else if (argc == 3)
    {
        if (!boost::iequals(argv[1], "-p"))
        {
            cout << "Argumento " << argv[1] << " invalido! " << endl;
            cout << "Execucao deve ter formato ./aracne OU ./aracne -p <numero da porta>" << endl;
            return 0;
        }
        proxy.SetPort(stoi(argv[2]));
    }
    else
    {
        cout << "Numero invalido de argumentos! " << endl;
        cout << "Execucao deve ter formato ./aracne OU ./aracne -p <numero da porta>" << endl;
        return 0;
    }

    proxy.InitThreads();
    proxy.show();

    return a.exec();
}
