//
// Created by vprog on 9/9/2021.
//

#include "MyException.h"

MyException::MyException(const std::string &message)
{
    std::cerr << message;
}

MyException::MyException(const std::string &message, Logger& logger)
{
    std::cerr << message;
    logger.LogErr(message);
}
