#pragma once

#include <string>
#include <exception>
#include "Logger.h"

class MyException : public std::exception
{
    MyException() = default;
    MyException(const std::string& message);
    MyException(Logger& logger, const std::string& message);
    virtual ~MyException() = default;
};
