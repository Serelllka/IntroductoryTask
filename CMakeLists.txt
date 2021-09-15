cmake_minimum_required(VERSION 3.19)
project(IntroductoryTask)

set(CMAKE_CXX_STANDARD 17)

#link_directories(IntroductoryTask ws2_32.dll, Mswsock.lib, AdvApi32.lib)
#add_dependencies(ws2_32.lib)

add_executable(IntroductoryTask
        src/Application.cpp
        src/Tools/Parser.cpp                        src/Tools/Parser.h
        src/Tools/Logger.cpp                        src/Tools/Logger.h
        src/Tools/MyException.cpp                   src/Tools/MyException.h
        src/Services/FunctionsRegisterService.cpp   src/Services/FunctionsRegisterService.h
        src/Entities/Parameter.cpp                  src/Entities/Parameter.h
        src/Networking/networkingManager.cpp        src/Networking/networkingManager.h
        src/Networking/ListenSocket.cpp             src/Networking/ListenSocket.h
        src/Networking/ClientSocket.cpp             src/Networking/ClientSocket.h)

if(WIN32)
    target_link_libraries(IntroductoryTask wsock32 ws2_32)
endif()