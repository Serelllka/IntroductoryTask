
#include <winsock.h>
#include "networkingManager.h"

networkingManager::networkingManager()
{
    WSADATA wsaData;
    int result;
    result = WSAStartup( MAKEWORD(2, 2), &wsaData);
    if (result != 0)
    {
        std::cerr << "Something went wrong" << std::endl;
        exit(1);
    }
}
