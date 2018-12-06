#include "socketClient.hpp"

SocketClient::SocketClient()
{
}

void SocketClient::run()
{
}

void SocketClient::GetResponse()
{

    if (read(clientSocket, buffer, 100000) < 0)
        cout << "ERROR on receive" << endl;
    cout << buffer << endl;
    emit IncomingResponse(buffer);

    close(clientSocket);
}

void SocketClient::SendRequest(char *buffer)
{
    clientSocket = socket(AF_INET, SOCK_STREAM, 0);

    signal(SIGPIPE, SIG_IGN);

    server = gethostbyname(GetHost(buffer));

    if (server == NULL || server->h_addr_list == NULL)
    {
        cout << "Could not get host address by name" << endl;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);

    bcopy((char *)server->h_addr,
          (char *)&serv_addr.sin_addr.s_addr,
          server->h_length);

    if (::connect(clientSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        cout << "ERROR connecting" << endl;

    int n = write(clientSocket, buffer, strlen(buffer));
    if (n < 0)
        cout << "ERROR writing to socket" << endl;

    GetResponse();
}

char *SocketClient::GetHost(char *buffer)
{
    vector<string> data;
    vector<string> hostname;

    boost::split(data, buffer, [](char c) { return c == ' ' || c == '\n'; });

    for (unsigned int i = 0; i < data.size(); i++)
    {
        if (boost::iequals(data[i], "Host:"))
        {
            boost::split(hostname, data[i + 1], [](char c) { return c == '.'; });
            return const_cast<char *>(data[i + 1].c_str());
        }
    }

    return const_cast<char *>(data[0].c_str());
}