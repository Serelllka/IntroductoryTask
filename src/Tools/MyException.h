#pragma once

#include <string>
#include <exception>
#include "Logger.h"

class MyException : public std::exception
{
public:
    MyException() = default;
    explicit MyException(const std::string& message);
    explicit MyException(const std::string& message, Logger& logger);

    virtual ~MyException() = default;
};
