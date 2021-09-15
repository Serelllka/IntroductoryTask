#include "Logger.h"

#include <chrono>

Logger::Logger(std::ostream& output)
    : _output(output)
{}

void Logger::LogErr(const std::string &message)
{
    std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    _output << ctime(&tt) << "error: " << message << std::endl;
}

void Logger::LogGen(const std::string &message)
{
    std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    _output << ctime(&tt) << "generation: " << message << std::endl;
}

