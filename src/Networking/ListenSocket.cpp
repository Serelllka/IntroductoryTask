#include "ListenSocket.h"
#include "../Tools/MyException.h"


void ListenSocket::Init(addrinfo* info)
{
    _socket = socket(info->ai_family, info->ai_socktype, info->ai_protocol);
    if (_socket == INVALID_SOCKET)
    {
        throw MyException("socket failed with error: " +  std::to_string(WSAGetLastError()), _logger);
    }
}

void ListenSocket::Bind(addrinfo* info)
{
    int iResult = bind( _socket, info->ai_addr, (int)info->ai_addrlen);
    if (iResult == SOCKET_ERROR)
    {
        throw MyException("socket failed with error: " +  std::to_string(WSAGetLastError()), _logger);
    }
}

void ListenSocket::Listen(int count)
{
    listen(_socket, count);
}

SOCKET& ListenSocket::GetSocket()
{
    return _socket;
}

ListenSocket::ListenSocket()
    : _logger(std::cout), _socket(INVALID_SOCKET)
{}

void ListenSocket::CloseSocket()
{
    closesocket(_socket);
}

ListenSocket::ListenSocket(Logger& logger)
    : _logger(logger), _socket(INVALID_SOCKET)
{}
