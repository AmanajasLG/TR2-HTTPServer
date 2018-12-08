#include "inspector.hpp"
#include <iostream>

Inspector::Inspector(int numPort)
{
    server = new SocketServer(numPort);
    client = new SocketClient();
    server->start();
    client->start();

    QObject::connect(server, SIGNAL(IncomingRequest(const char *)), this, SLOT(RequestIncoming(const char *)), Qt::QueuedConnection);
    QObject::connect(client, SIGNAL(IncomingResponse(const char *)), this, SLOT(ResponseIncoming(const char *)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SendRequestToServer(const char *)), client, SLOT(SendRequest(const char *)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SendResponseToClient(const char *)), server, SLOT(SendResponse(const char *)), Qt::QueuedConnection);

    server->GetRequest();
}

void Inspector::run()
{
}

Inspector::~Inspector()
{
    server->terminate();
    client->terminate();
}

void Inspector::RequestIncoming(const char *buffer)
{
    emit RequestShouldShow(buffer);
}

void Inspector::SendRequest(const char *buffer)
{
    emit SendRequestToServer(buffer);
}

void Inspector::ResponseIncoming(const char *buffer)
{
    emit ResponseShouldShow(buffer);
}

void Inspector::SendResponse(const char *buffer)
{
    emit SendResponseToClient(buffer);
}