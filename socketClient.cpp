#include "socketClient.hpp"

SocketClient::SocketClient()
{
}

void SocketClient::run()
{
}

void SocketClient::GetResponse()
{

    if (read(clientSocket, buffer, 10000) < 0)
    {
        error("ERROR from reading");
    }

    cout << buffer << endl;

    emit IncomingResponse(buffer);

    close(clientSocket);
}

void SocketClient::SendRequest(const char *buffer)
{

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    cout << buffer << endl;

    server = gethostbyname(GetHost(buffer).c_str());

    if (server == NULL || server->h_addr_list == NULL)
    {
        error("Could not get host address by name");
    }

    cout << buffer << endl;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    if (::connect(clientSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    if (write(clientSocket, buffer, strlen(buffer)) < 0)
        error("ERROR writing to socket");

    GetResponse();
}

string SocketClient::GetHost(const char *buffer)
{
    vector<string> data;
    boost::split(data, buffer, [](char c) { return c == ' ' || c == '\n'; });

    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (boost::iequals(data[i], "Host:"))
        {
            return data[i + 1];
        }
    }

    return const_cast<const char *>(data[0].c_str());
}