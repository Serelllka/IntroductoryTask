#pragma once

#include <string>
#include <vector>
#include <unordered_map>

#include "Logger.h"

namespace parser
{
    namespace parameters
    {
        void parse(std::istream& inputStream, std::ostream& outputStream,
                   const std::unordered_map<std::string, std::string>& dictionary, Logger* logger = nullptr);
    }

    namespace html
    {
        std::unordered_map<std::string, std::string> parse(std::istream& inputStream, Logger* logger = nullptr);
    }
}
