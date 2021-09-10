#pragma once

#include <iostream>
#include <string>


class Logger
{
private:
    std::ostream& output;
public:
    Logger(std::ostream& output);
    ~Logger() = default;

    void logErr(const std::string& message);
    void logGen(const std::string& message);
};
