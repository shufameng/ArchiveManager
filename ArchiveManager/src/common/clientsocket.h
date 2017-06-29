#ifndef CLIENTSOCKET_H
#define CLIENTSOCKET_H

#include <winsock.h>

class ClientSocket
{
public:
    ClientSocket();

    static int initWinSocket();
    static int connectServer(SOCKET *s, char *pSerAddr, unsigned int uiSerPort);
    static int connectFileServer(SOCKET s);
};

#endif // CLIENTSOCKET_H
