#include "socketClient.hpp"

SocketClient::SocketClient()
{
}

void SocketClient::run()
{
}

void SocketClient::GetResponse()
{
    int n;
    char test[10000];

    if (read(clientSocket, test, 10000) < 0)
    {
        error("ERROR from reading");
    }


    cout << test  << endl;

    buffer = QString::fromStdString(test);

    emit IncomingResponse(buffer);

    close(clientSocket);
}

void SocketClient::SendRequest(QString buffer)
{

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(GetHost(buffer.toStdString().c_str()).c_str());

    if (server == NULL || server->h_addr_list == NULL)
    {
        error("Could not get host address by name");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    bcopy((QChar *)server->h_addr,
          (QChar *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    if (::connect(clientSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");


    if (write(clientSocket, buffer.toStdString().c_str(), buffer.size()) < 0)
        error("ERROR writing to socket");
    

    GetResponse();
}

string SocketClient::GetHost(QString buffer)
{
    vector<string> data;
    string utf8_text = buffer.toUtf8().constData();
    boost::split(data, utf8_text, [](QChar c) { return c == ' ' || c == '\n' || c == '\r'; });

    for (unsigned int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
        if (boost::iequals(data[i], "Host:"))
        {
            cout << data[i+1] << endl;
            return data[i + 1];
        }
    }

    return data[0];
}