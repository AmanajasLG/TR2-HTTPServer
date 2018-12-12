#include "inspector.hpp"
#include <iostream>

Inspector::Inspector(int numPort)
{
    socket = new Socket(numPort);
    socket->start();

    QObject::connect(socket, SIGNAL(IncomingRequest(QString)), this, SLOT(RequestIncoming(QString)), Qt::QueuedConnection);
    QObject::connect(socket, SIGNAL(IncomingResponse(QString)), this, SLOT(ResponseIncoming(QString)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SendRequestToServer(QString)), socket, SLOT(SendRequestSlot(QString)), Qt::QueuedConnection);
    QObject::connect(this, SIGNAL(SendResponseToClient(QString)), socket, SLOT(SendResponseSlot(QString)), Qt::QueuedConnection);
}

void Inspector::run()
{
}

Inspector::~Inspector()
{
    socket->terminate();
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