#include "inspector.hpp"
#include <iostream>

Inspector::Inspector(int numPort)
{
    SocketServer *server = new SocketServer(numPort);
    SocketClient *client = new SocketClient();
    server->start();
    client->start();

    QObject::connect(server, SIGNAL(IncomingRequest(char *)), this, SLOT(RequestIncoming(char *)));
    QObject::connect(client, SIGNAL(IncomingResponse(char *)), this, SLOT(ResponseIncoming(char *)));
    QObject::connect(this, SIGNAL(SendRequestToServer(char *)), client, SLOT(SendRequest(char *)));
}

void Inspector::run()
{
}

Inspector::~Inspector()
{
}

void Inspector::RequestIncoming(char *buffer)
{
    emit RequestShouldShow(buffer);
}

void Inspector::SendRequest(char *buffer)
{
    emit SendRequestToServer(buffer);
}

void Inspector::ResponseIncoming(char *buffer)
{
    emit ResponseShouldShow(buffer);
}

void Inspector::SendResponse(char *buffer)
{
    emit SendResponseToServer(buffer);
}