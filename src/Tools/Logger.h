#pragma once

#include <iostream>
#include <string>


class Logger
{
private:
    std::ostream& _output;
public:
    Logger(std::ostream& output);
    ~Logger() = default;

    void LogErr(const std::string& message);
    void LogGen(const std::string& message);
};
