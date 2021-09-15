#pragma once

#include <winsock2.h>

class ClientSocket
{
private:
    SOCKET _socket;
public:
    ClientSocket();
    ~ClientSocket() = default;
};
