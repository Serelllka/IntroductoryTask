#pragma once

#include<string>

class Logger
{
private:
    std::ostream& output;
public:
    Logger(std::ostream& output);
    ~Logger() = default;

    void logErr(std::string& message);
    void logGen(std::string& message);
};
