#include "Logger.h"

#include <chrono>

Logger::Logger(std::ostream& output)
    : output(output)
{}

void Logger::logErr(const std::string &message)
{
    std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    output << ctime(&tt) << "error: " << message << std::endl;
}

void Logger::logGen(const std::string &message)
{
    std::time_t tt = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    output << ctime(&tt) << "generation: " << message << std::endl;
}

