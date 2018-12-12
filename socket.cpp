#include "socket.hpp"

Socket::Socket(int numPort) : numPort(numPort)
{
}

Socket::~Socket()
{
    close(serverSocket);
}

void Socket::run()
{
    exec();
}

void Socket::GetRequest()
{
    int tr = 1;
    char test[1000000] = {0};

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        error("ERROR opening socket");

    bzero((QChar *)&serv_addr_server, sizeof(serv_addr_server));

    /* setup the host_addr structure for use in bind call */
    // server byte order
    serv_addr_server.sin_family = AF_INET;

    // automatically be filled with current host's IP address
    serv_addr_server.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
    serv_addr_server.sin_port = htons(numPort);

    if (setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &tr, sizeof(int)) == -1)
    {
        perror("ERROR on setsockopt");
    }

    if (bind(serverSocket, (struct sockaddr *)&serv_addr_server, sizeof(serv_addr_server)) < 0)
        error("ERROR on binding");

    listen(serverSocket, 2000000);

    clilen = sizeof(cli_addr);

    clientServerSocket = accept(serverSocket, (struct sockaddr *)&cli_addr, &clilen);
    if (clientServerSocket < 0)
        error("ERROR on accept");

    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    if (setsockopt(clientServerSocket, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv, sizeof tv) == -1)
    {
        perror("ERROR on setsockopt");
    }

    printf("server: got connection from %s port %d\n",
           inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    close(serverSocket);

    memset(test, 0, sizeof(test));
    if (read(clientServerSocket, test, 1000000) < 0)
    {
        error("Error on receiving");
    }

    buffer.clear();
    buffer = QString::fromStdString(test);

    vector<string> data;
    boost::split(data, test, [](QChar c) { return c == ' ' || c == '\n'; });

    cout << "PASSO AQUI" << endl;

    cout << buffer.toStdString() << endl;

    if (boost::iequals(data[0], "GET"))
    {
        emit IncomingRequest(buffer);
    }
    else
    {
        time_t rawtime;
        struct tm *timeinfo;
        time(&rawtime);
        timeinfo = localtime(&rawtime);
        char hour[80];
        strftime(hour, 80, "%a, %d %b %G %T GMT", timeinfo);
        QString connectBuffer = string("HTTP/1.1 200 OK\r\n"
                                       "Date: " +
                                       string(hour) +
                                       " GMT\r\n"
                                       "Server: Apache/2.2.15 (CentOS)\r\n"
                                       "X-Content-Type-Options: nosniff\r\n"
                                       "X-Powered-By: PHP/7.0.21\r\n\r\n")
                                    .c_str();
        SendResponse(connectBuffer);

        GetRequest();
    }
}

void Socket::SendRequest(QString buffer)
{
    cout << "AGORA AQUI" << endl;

    cout << buffer.toStdString() << endl;
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    struct timeval tv;
    tv.tv_sec = 10;
    tv.tv_usec = 0;
    if (setsockopt(clientSocket, SOL_SOCKET, SO_RCVTIMEO, (const void *)&tv, sizeof tv) == -1)
    {
        perror("ERROR on setsockopt");
    }

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

    int bytes = write(clientSocket, buffer.toStdString().c_str(), buffer.size());
    if (bytes < 0)
    {
        error("ERROR on sending");
    }

    GetResponse();
}

void Socket::GetResponse()
{
    cout << "AQUI" << endl;

    char test[1000000] = {0};
    char testSize[10000] = {0};
    buffer.clear();
    memset(test, 0, sizeof(test));
    int total = sizeof(test) - 1;
    int received = 0;
    int bytes;
    char *tmpBuffer;

    if ((received = read(clientSocket, test, 1000000)) < 0)
    {
        error("ERROR from reading");
    }

    cout << "\n\n\nTEST\n\n"
         << endl;

    cout << test << endl;

    cout << "\n\n\nEND TEST\n\n"
         << endl;

    bytes = received;

    if ((responseSize = GetSize(QString::fromStdString(test))) != 0)
    {
        buffer = QString::fromStdString(test);

        tmpBuffer = strstr(test, "\r\n\r\n");

        if (tmpBuffer != NULL)
        {
            tmpBuffer += 4;
            bytes = bytes - (int)(tmpBuffer - test);
        }

        if (bytes < 0)
            error("ERROR from reading");
        else if (bytes > 0)
            responseSize -= bytes;

        while (responseSize > 0)
        {
            bytes = read(clientSocket, testSize, 10000);
            if (bytes < 0)
            {
                error("Error on receiving");
                break;
            }
            else if (bytes > 0)
                responseSize -= bytes;

            buffer += QString::fromStdString(testSize);
        }
    }
    else
    {
        do
        {
            bytes = read(clientSocket, test + received, total - received);
            if (bytes < 0)
            {
                error("Error on receiving");
                break;
            }

            if (bytes == 0)
                break;
            received += bytes;
        } while (received < total);

        buffer = QString::fromStdString(test);
    }

    emit IncomingResponse(buffer);

    close(clientSocket);
}

void Socket::SendResponse(QString buffer)
{
    cout << "FINALMENTE AQUI" << endl;
    cout << buffer.toStdString() << endl;
    int bytes = write(clientServerSocket, buffer.toStdString().c_str(), buffer.size());
    if (bytes < 0)
    {
        error("ERROR on sending");
    }

    close(clientServerSocket);
    buffer.clear();

    GetRequest();
}

string Socket::GetHost(QString buffer)
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

int Socket::GetSize(QString buffer)
{
    vector<string> data;
    string utf8_text = buffer.toStdString();
    boost::split(data, utf8_text, [](QChar c) { return c == ' ' || c == '\n' || c == '\r'; });

    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (boost::iequals(data[i], "Content-Length:"))
            return stoi(data[i + 1]);
        else if (boost::iequals(data[i], "<!DOCTYPE"))
            break;
    }

    return 0;
}