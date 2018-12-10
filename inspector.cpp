#include "inspector.hpp"
#include <iostream>

Inspector::Inspector(int numPort)
{
    server = new SocketServer(numPort);
    client = new SocketClient();
    server->start();
    client->start();

    QObject::connect(server, SIGNAL(IncomingRequest(QString)), this, SLOT(RequestIncoming(QString)), Qt::QueuedConnection);
    QObject::connect(client, SIGNAL(IncomingResponse(QString)), this, SLOT(ResponseIncoming(QString)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SendRequestToServer(QString)), client, SLOT(SendRequest(QString)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SendResponseToClient(QString)), server, SLOT(SendResponse(QString)), Qt::QueuedConnection);

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

void Inspector::RequestIncoming(QString buffer)
{
    emit RequestShouldShow(buffer);
}

void Inspector::SendRequest(QString buffer)
{
    emit SendRequestToServer(buffer);
}

void Inspector::ResponseIncoming(QString buffer)
{
    emit ResponseShouldShow(buffer);
}

void Inspector::SendResponse(QString buffer)
{
    emit SendResponseToClient(buffer);
}