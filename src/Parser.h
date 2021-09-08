#pragma once

#include<string>
#include<vector>

#include<unordered_map>

struct parameter
{
    std::string name;
    bool is_required;
};

namespace parser
{
    namespace parameters
    {
        void parse(std::istream& inputStream, std::ostream& outputStream,
                   const std::unordered_map<std::string, std::string>& dictionary);
    }

    namespace html
    {
        std::unordered_map<std::string, std::string> parse(const std::string& filepath);
    }
}
