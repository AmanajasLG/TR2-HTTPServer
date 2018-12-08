#include "socketServer.hpp"

SocketServer::SocketServer(int portNum)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        error("ERROR opening socket");

    bzero((char *)&serv_addr, sizeof(serv_addr));

    /* setup the host_addr structure for use in bind call */
    // server byte order
    serv_addr.sin_family = AF_INET;

    // automatically be filled with current host's IP address
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
    serv_addr.sin_port = htons(portNum);

    if (bind(serverSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(serverSocket, 10);

    clilen = sizeof(cli_addr);
}

SocketServer::~SocketServer()
{
    close(serverSocket);
}

void SocketServer::run()
{
    exec();
}

void SocketServer::GetRequest()
{
    clientSocket = accept(serverSocket, (struct sockaddr *)&cli_addr, &clilen);
    if (clientSocket < 0)
        error("ERROR on accept");

    cout << "CLIENT GET " << clientSocket << endl;

    printf("server: got connection from %s port %d\n",
           inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    if (read(clientSocket, buffer, 100000) < 0)
        error("ERROR on receive");

    vector<string> data;
    boost::split(data, buffer, [](char c) { return c == ' ' || c == '\n'; });

    if (boost::iequals(data[0], "CONNECT"))
    {
        const char *connectBuffer = string("200 OK").c_str();
        SendResponse(connectBuffer);
        close(clientSocket);

        GetRequest();
    }
    else
    {
        emit IncomingRequest(buffer);
    }
}

void SocketServer::SendResponse(const char *buffer)
{
    cout << "CLIENT SEND " << clientSocket << endl;

    cout << "SERVER: " << buffer << endl;

    if (send(clientSocket, buffer, strlen(buffer), MSG_CONFIRM) < 0)
        error("ERROR writing to socket");

    close(clientSocket);

    GetRequest();
}