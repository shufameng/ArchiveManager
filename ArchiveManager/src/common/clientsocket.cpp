#include "ClientSocket.h"
#include <QDebug>
#include "IniLoader.h"

ClientSocket::ClientSocket()
{

}

int ClientSocket::initWinSocket()
{
    WSADATA wsa;
    int rev = WSAStartup(MAKEWORD(1, 1), &wsa); //initial ws2_32.dll by a process
    return rev;
}

int ClientSocket::connectServer(SOCKET *s, char *pSerAddr, unsigned int uiSerPort)
{
    *s = ::socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (INVALID_SOCKET == *s) {
        qDebug() << "created socket is invalid.";
        return -1;
    }

    SOCKADDR_IN serveraddr;
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(uiSerPort);
    serveraddr.sin_addr.S_un.S_addr = inet_addr(pSerAddr);

    int rev;
    // try more than 1 times
//    for( int i = 0; i < 5; i ++  )
//    {
//        qDebug() << "try to connect...";
//        rev = ::connect( *s, ( SOCKADDR * )&serveraddr, sizeof( serveraddr ));
//        if( rev == 0 )  //连接成功，跳出循环
//        {
//            break;
//        }
//        ::Sleep( 100 );
//     }

    // try only 1 time
    rev = ::connect(*s, (SOCKADDR *)&serveraddr, sizeof(serveraddr));

    // check result
    if(rev != 0)
    {
        qDebug() << QString("failed to connect to %1:%2, error code(%3)").arg(QString::fromLocal8Bit(pSerAddr), QString::number(uiSerPort), QString::number(GetLastError()));
        return rev;
    }

    return rev;
}


int ClientSocket::connectFileServer(SOCKET s)
{
    FsNetConfig conf = IniLoader::loadFsNetConfig();
    QByteArray aHost = conf.host.toLocal8Bit();
    return connectServer(&s, aHost.data(), conf.port);
}

