#pragma once

#include <winsock2.h>
#include <ws2tcpip.h>
#include "../Tools/Logger.h"

class ListenSocket
{
private:
    SOCKET _socket;
    Logger _logger;
public:
    ListenSocket();
    ListenSocket(Logger& logger);
    ~ListenSocket() = default;

    void Init(addrinfo* info);
    void Bind(addrinfo* info);
    void Listen(int count = SOMAXCONN);
    void CloseSocket();
    SOCKET& GetSocket();
};
