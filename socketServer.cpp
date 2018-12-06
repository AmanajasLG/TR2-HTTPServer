#include "socketServer.hpp"

SocketServer::SocketServer(int portNum)
{
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket < 0)
        cout << "ERROR opening socket" << endl;

    bzero((char *)&serv_addr, sizeof(serv_addr));

    /* setup the host_addr structure for use in bind call */
    // server byte order
    serv_addr.sin_family = AF_INET;

    // automatically be filled with current host's IP address
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    // convert short integer value for port must be converted into network byte order
    serv_addr.sin_port = htons(portNum);

    if (bind(serverSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        cout << "ERROR on binding" << endl;

    listen(serverSocket, 10);

    clilen = sizeof(cli_addr);
}

void SocketServer::run()
{
    clientSocket = accept(serverSocket, (struct sockaddr *)&cli_addr, &clilen);
    if (clientSocket < 0)
        cout << "ERROR on accept" << endl;

    printf("server: got connection from %s port %d\n",
           inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));

    if (recv(clientSocket, buffer, 100000, MSG_WAITALL) < 0)
        cout << "ERROR on receive" << endl;

    emit IncomingRequest(buffer);

    exec();
}

void SocketServer::SendResponse(char *buffer)
{
    int n = write(clientSocket, buffer, strlen(buffer));

    if (n < 0)
        cout << "ERROR writing to socket" << endl;

    close(clientSocket);
}