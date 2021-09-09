#include "Logger.h"

#include <ctime>

Logger::Logger(std::ostream& output)
    : output(output)
{}

void Logger::logGen(std::string &message)
{
    output << "string";
}

void Logger::logGen(std::string &message)
{

}

