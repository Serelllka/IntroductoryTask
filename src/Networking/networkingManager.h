#pragma  once

#include "../Tools/Logger.h"
#include "ListenSocket.h"

class NetworkingManager
{
private:
    Logger _logger;
    ListenSocket _listenSocket;
public:
    NetworkingManager(Logger& logger);
    ~NetworkingManager() = default;

    void Startup();
private:
    void InitWinsock();
};
