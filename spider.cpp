#include "spider.hpp"

Spider::Spider()
{
}

void Spider::run()
{
}

void Spider::SetUrl(QString url)
{
    this->url = url.toStdString();
    ConfigURL();
}

void Spider::ConfigURL()
{
    QString urlEdit = QString::fromStdString(url);
    urlEdit.replace(QString::fromStdString("http://"), QString::fromStdString(""));
    urlEdit.replace(QString::fromStdString("https://"), QString::fromStdString(""));

    cout << urlEdit.toStdString() << endl;

    string host, path;
}

void Spider::Parser(char *req, char *host)
{
    char aux[100000];
    int i = 0, j;
    memset(assets, 0, 100000);
    while (1)
    {
        while (req[i] != 'h' && req[i] != 's' && req[i] != '<')
        {
            i++;
        }
        if (req[i] == '<' && req[i + 1] == '/' && req[i + 2] == 'h' && req[i + 3] == 't' && req[i + 4] == 'm' && req[i + 5] == 'l')
            break;
        if (req[i] == 'h' && req[i + 1] == 'r' && req[i + 2] == 'e' && req[i + 3] == 'f' && req[i + 4] == '=' && req[i + 5] == '"')
        {
            i += 6;
            j = 0;
            while (req[i] != '"' && req[i] != 39)
            {
                aux[j] = req[i];
                j++;
                i++;
            }
            aux[j] = '\0';
            strcat(assets, aux);
            strcat(assets, "  ");
        }
        if (req[i] == 's' && req[i + 1] == 'r' && req[i + 2] == 'c' && req[i + 3] == '=' && req[i + 4] == '"')
        {
            i += 5;
            j = 0;
            while (req[i] != '"' && req[i] != 39)
            {
                aux[j] = req[i];
                j++;
                i++;
            }
            aux[j] = '\0';
            strcat(assets, aux);
            strcat(assets, "  ");
        }
        i++;
    }
    i = 0;
    char aux2[100000];
    memset(fassets, 0, 100000);
    count = 0;
    while (1)
    {
        j = 0;
        while (assets[i] != ' ')
        {
            aux[j] = assets[i];
            j++;
            i++;
        }
        aux[j] = '\0';
        if (aux[0] == 'h' && aux[1] == 't' && aux[2] == 't' && aux[3] == 'p' && aux[4] == 's')
        {
            i += 2;
        }
        else if (strstr(aux, host) != NULL)
        {
            j = 0;
            while (aux[j] != '.' && aux[j + 4] != '/')
                j++;
            int k = 0;
            while (aux[j] != '\0')
            {
                aux2[k] = aux[j];
                k++;
                j++;
            }
            aux2[k] = '\0';
            if (strlen(aux2) > 1)
            {
                strcat(fassets, aux);
                strcat(fassets, "\n");
                count++;
            }
            i += 2;
        }
        else if (aux[0] == 'h' && aux[1] == 't' && aux[2] == 't' && aux[3] == 'p')
        {
            i += 2;
        }
        else
        {
            //if(strstr(aux, ".css") == NULL && strstr(aux, ".js") == NULL && strstr(aux, ".png") == NULL && strstr(aux, ".jpg") == NULL){
            if (strlen(aux) > 1)
            {
                strcat(fassets, aux);
                strcat(fassets, "\n");
                count++;
            }
            i += 2;
        }
        if (assets[i] == '\0')
            break;
    }
    //printf("%s\n", fassets);
}

void Spider::ExecSpider(char *host, char *path, char *list)
{
    int sockfd, port = 80, bytes, sent, received, total;
    strcpy(req, "GET ");
    strcat(req, path);
    strcat(req, " HTTP/1.1\r\nHost: ");
    strcat(req, host);
    strcat(req, "\r\nConnection: close");
    strcat(req, "\r\n\r\n");
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char buffer[10000], resp[10000];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
    {
        printf("Error on creating socket\n");
        exit(0);
    }

    server = gethostbyname(host);
    if (server == NULL)
    {
        printf("Error on geting host by name\n");
        exit(0);
    }
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (::connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error on connecting to socket\n");
        exit(0);
    }
    total = strlen(req);
    sent = 0;

    do
    {
        bytes = write(sockfd, req + sent, total - sent);
        if (bytes < 0)
        {
            printf("Error on sending request to server\n");
            exit(0);
        }
        if (bytes == 0)
            break;
        sent += bytes;
    } while (sent < total);

    memset(resp, 0, sizeof(resp));
    total = sizeof(resp) - 1;
    received = 0;
    do
    {
        bytes = read(sockfd, resp + received, total - received);
        if (bytes < 0)
        {
            printf("Error on receiving response from server\n");
            exit(0);
        }
        if (bytes == 0)
            break;
        received += bytes;
    } while (received < total);

    close(sockfd);
    Parser(resp, host);
    strcpy(list, fassets);
    //printf("%s\n",list);
}
