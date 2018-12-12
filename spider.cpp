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
    //siteList.push_back(Site(NULL, 0, this->url));
    //father = siteList.back();
    ConfigURL();
}

std::set<std::string> Spider::ExtractHyperlinks(std::string text)
{
    static const regex hl_regex("<a href=\"([^#].*?)\"", std::regex_constants::icase);

    return {sregex_token_iterator(text.begin(), text.end(), hl_regex, 1),
            sregex_token_iterator{}};
}

void Spider::ConfigURL()
{
    QString urlEdit = QString::fromStdString(url);
    urlEdit.replace(QString::fromStdString("http://"), QString::fromStdString(""));
    urlEdit.replace(QString::fromStdString("https://"), QString::fromStdString(""));

    url = urlEdit.toStdString();

    int index = url.find_first_of('/');

    ExecSpider(const_cast<char *>(url.substr(0, index).c_str()), const_cast<char *>(url.substr(index).c_str()), 0, nullptr);
}

void Spider::ExecSpider(char *host, char *path, int lvl, Page *father)
{

    Page page;
    page.father = father;
    page.lvl = lvl;
    page.name = path;

    siteList.push_back(page);

    if (lvl > 1)
        return;

    int clientSocket, port = 80, bytes, sent, received, total;
    strcpy(req, "GET ");
    strcat(req, path);
    strcat(req, " HTTP/1.1\r\nHost: ");
    strcat(req, host);
    strcat(req, "\r\nConnection: close");
    strcat(req, "\r\n\r\n");
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char resp[1000000];

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket < 0)
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

    if (::connect(clientSocket, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    {
        printf("Error on connecting to socket\n");
        exit(0);
    }
    total = strlen(req);
    sent = 0;

    do
    {
        bytes = write(clientSocket, req + sent, total - sent);
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
        bytes = read(clientSocket, resp + received, total - received);
        if (bytes < 0)
        {
            printf("Error on receiving response from server\n");
            exit(0);
        }
        if (bytes == 0)
            break;
        received += bytes;
    } while (received < total);

    close(clientSocket);

    for (std::string hlink : ExtractHyperlinks(resp))
    {
        if (hlink.find("http") == string::npos)
        {
            if (hlink[0] != '/')
            {

                ExecSpider(host, const_cast<char *>(('/' + hlink).c_str()), page.lvl + 1, &page);
            }
            else
                ExecSpider(host, const_cast<char *>(hlink.c_str()), page.lvl + 1, &page);
        }
        else
        {
            Page pageOut;
            pageOut.father = &page;
            pageOut.lvl = page.lvl + 1;
            pageOut.name = hlink;

            siteList.push_back(pageOut);
        }
    }

    BuildTree();
}

void Spider::BuildTree()
{
    QString buffer;

    int size = siteList.size();
    for (int i = 0; i < size; i++)
    {
        Page pag = siteList.at(i);

        if (pag.lvl == 0)
        {
            buffer += QString::fromStdString(pag.name + "\n");
        }
        else if (pag.lvl == 1)
        {
            buffer += QString::fromStdString("   | " + pag.name + "\n");
        }
        else if (pag.lvl == 2)
        {
            buffer += QString::fromStdString("   |    | " + pag.name + "\n");
        }
        else
        {
            buffer += QString::fromStdString("   |    |    | " + pag.name + "\n");
        }
    }

    emit ShowTree(buffer);
}