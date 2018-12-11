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
    buffer.clear();

    FirstPack();

    while (responseSize > 0)
    {
        cout << "RESPONSESIZE >: " << responseSize << endl;
        if ((n = recv(clientSocket, test, 10000, MSG_WAITALL)) < 0)
        {
            error("ERROR from reading");
        }

        if (n < 0)
            error("Erro ao ler no socket");
        else if (n > 0)
            responseSize -= n;

        buffer += QString::fromStdString(test);
    }

    cout << buffer.toStdString() << endl;

    emit IncomingResponse(buffer);

    close(clientSocket);
}

void SocketClient::FirstPack()
{
    char *tmpBuffer;
    int n;
    char test[10000];

    if ((n = recv(clientSocket, test, 10000, MSG_WAITALL)) < 0)
    {
        error("ERROR from reading");
    }

    cout << test << endl;

    responseSize = GetSize(test);

    if (responseSize == 0)
    {
        buffer = QString::fromStdString(test);
        return;
    }

    tmpBuffer = strstr(test, "\r\n\r\n");

    if (tmpBuffer != NULL)
    {
        tmpBuffer += 4;
        n = n - (int)(tmpBuffer - test);
    }

    if (n < 0)
        error("ERROR from reading");
    else if (n > 0)
        responseSize -= n;

    buffer = QString::fromStdString(test);
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
            cout << data[i + 1] << endl;
            return data[i + 1];
        }
    }

    return data[0];
}

int SocketClient::GetSize(QString buffer)
{
    vector<string> data;
    string utf8_text = buffer.toUtf8().constData();
    boost::split(data, utf8_text, [](QChar c) { return c == ' ' || c == '\n' || c == '\r'; });

    for (unsigned int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
        if (boost::iequals(data[i], "Content-Length:"))
        {
            cout << data[i + 1] << endl;
            return stoi(data[i + 1]);
        }
    }

    return 0;
}