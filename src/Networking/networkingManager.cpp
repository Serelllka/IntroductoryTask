#define WIN32_LEAN_AND_MEAN
#define _WIN32_WINNT 0x0501
#define DEFAULT_BUFLEN 512
#define DEFAULT_PORT "27015"

#undef UNICODE

#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <cstdio>

#include "NetworkingManager.h"
#include "../Tools/MyException.h"

NetworkingManager::NetworkingManager(Logger& logger)
    : _logger(logger)
{
    try
    {
        InitWinsock();
    }
    catch (MyException& exception)
    {
        throw exception;
    }
}

void NetworkingManager::InitWinsock()
{
    WSADATA wsaData;
    int iResult = WSAStartup(MAKEWORD(2,2), &wsaData);
    if (iResult != 0)
    {
        throw MyException("WSAStartup failed with error: " + std::to_string(iResult), _logger);
    }
}

void NetworkingManager::Startup()
{
    SOCKET ClientSocket = INVALID_SOCKET;

    int iResult;

    addrinfo* result = NULL;

    int iSendResult;
    char recvbuf[DEFAULT_BUFLEN];
    int recvbuflen = DEFAULT_BUFLEN;

    addrinfo hints;
    ZeroMemory(&hints, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;
    hints.ai_flags = AI_PASSIVE;

    iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
    if ( iResult != 0 )
    {
        printf("getaddrinfo failed with error: %d\n", iResult);
        WSACleanup();
        exit(1);
    }

    try
    {
        _listenSocket.Init(result);
        _listenSocket.Bind(result);
        _listenSocket.Listen();
    }
    catch (MyException& exception)
    {
        _listenSocket.CloseSocket();
        freeaddrinfo(result);
        WSACleanup();
        throw exception;
    }
    freeaddrinfo(result);

    ClientSocket = accept(_listenSocket.GetSocket(), NULL, NULL);
    if (ClientSocket == INVALID_SOCKET)
    {
        printf("accept failed with error: %d\n", WSAGetLastError());
        closesocket(_listenSocket.GetSocket());
        WSACleanup();
        exit(1);
    }

    closesocket(_listenSocket.GetSocket());

    do {
        iResult = recv(ClientSocket, recvbuf, recvbuflen, 0);
        if (iResult > 0)
        {
            printf("Bytes received: %d\n", iResult);

            // Echo the buffer back to the sender
            iSendResult = send( ClientSocket, recvbuf, iResult, 0 );
            if (iSendResult == SOCKET_ERROR) {
                printf("send failed with error: %d\n", WSAGetLastError());
                closesocket(ClientSocket);
                WSACleanup();
                exit(1);
            }
            printf("Bytes sent: %d\n", iSendResult);
        }
        else if (iResult == 0)
        {
            printf("Connection closing...\n");
        }
        else
        {
            printf("recv failed with error: %d\n", WSAGetLastError());
            closesocket(ClientSocket);
            WSACleanup();
            exit (1);
        }

    } while (iResult > 0);

    // shutdown the connection since we're done
    iResult = shutdown(ClientSocket, SD_SEND);
    if (iResult == SOCKET_ERROR)
    {
        printf("shutdown failed with error: %d\n", WSAGetLastError());
        closesocket(ClientSocket);
        WSACleanup();
        exit (1);
    }

    // cleanup
    closesocket(ClientSocket);
    WSACleanup();
}