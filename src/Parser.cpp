#include "Parser.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>

void parser::parameters::parse(std::istream& inputStream, std::ostream& outputStream,
                               const std::unordered_map<std::string, std::string>& dictionary, Logger* logger)
{
    std::string line;

    while(getline(inputStream, line))
    {
        std::string lineCopy;
        size_t index = 0;
        while(index < line.size())
        {
            if(line[index] != '{')
            {
                lineCopy += line[index];
            }
            else
            {
                std::string paramName = "";
                ++index;
                while(line[index] != '}')
                {
                    paramName += line[index];
                    ++index;
                }

                if (paramName[0] == '*')
                {
                    paramName = paramName.substr(1);
                    if (dictionary.find(paramName) == dictionary.end())
                    {
                    }
                }

                auto item = dictionary.find(paramName);
                if (item != dictionary.end())
                {
                    lineCopy += item->second;
                }
            }
            ++index;
        }
        lineCopy += '\n';

        outputStream << lineCopy;
    }

    logger->logGen("buffer was successfully parsed");
}

std::unordered_map<std::string, std::string> parser::html::parse(std::istream& inputStream, Logger* logger)
{
    std::unordered_map<std::string, std::string> dictionary;
    std::string line;
    std::string paramValue = "";

    int position = 0;
    while (inputStream)
    {
        char c;
        inputStream >> c;
        if (c == '<')
        {
            std::string paramName = "";
            inputStream >> c;
            while (c != '>')
            {
                paramName += c;
                inputStream >> c;
            }
            if (paramName == "root" || paramName == "/root") continue;
            std::string paramValue = "";
            if (!inputStream)
            {
                throw "Oh shit file has been ended";
            }
            inputStream >> c;
            while (c != '<')
            {
                paramValue += c;
                inputStream >> c;
            }
            if (paramName != "current_date")
                dictionary.insert(std::make_pair(paramName, paramValue));
            while (c != '>') inputStream >> c;
        }
    }

    logger->logGen("parameters were successfully framed");

    return dictionary;
}