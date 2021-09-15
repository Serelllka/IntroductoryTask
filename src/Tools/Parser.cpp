#include "Parser.h"
#include "MyException.h"

#include <iostream>
#include <string>
#include <unordered_map>
#include <ctime>

Parser::Parser(Logger& logger)
        : _logger(logger)
{}

void Parser::parameters(std::istream& inputStream, std::ostream& outputStream,
                               const std::unordered_map<std::string, std::string>& dictionary)
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

    _logger.LogGen("parameters were successfully framed");
}

std::unordered_map<std::string, std::string> Parser::html(std::istream& inputStream)
{
    std::unordered_map<std::string, std::string> dictionary;
    std::string line;

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
            if (paramName == "root" || paramName == "/root")
            {
                continue;
            }
            std::string paramValue = "";
            if (!inputStream)
            {
                throw MyException("this file can't be parsed correctly");
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

    _logger.LogGen("parameters were successfully parsed");

    return dictionary;
}