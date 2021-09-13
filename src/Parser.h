#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Logger.h"

class Parser
{
public:
    Parser(std::ostream& output);
    ~Parser() = default;

    void parameters(std::istream& inputStream, std::ostream& outputStream,
               const std::unordered_map<std::string, std::string>& dictionary);

    std::unordered_map<std::string, std::string> html(std::istream& inputStream);
private:
    Logger _logger;
};