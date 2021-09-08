#include "Parser.h"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <ctime>

void parser::parameters::parse(std::istream& inputStream, std::ostream& outputStream,
                               const std::unordered_map<std::string, std::string>& dictionary)
{
    std::string line;
    //std::vector<parameter> listOfParams;

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
}

std::unordered_map<std::string, std::string> parser::html::parse(const std::string& filepath)
{
    std::unordered_map<std::string, std::string> dictionary;
    std::ifstream stream(filepath);
    if (!stream)
    {
        std::cerr << "Can't find file with such name: " << filepath << std::endl;
    }
    std::string line;
    std::string paramValue = "";

    int position = 0;
    while (stream)
    {
        char c;
        stream >> c;
        if (c == '<')
        {
            std::string paramName = "";
            stream >> c;
            while (c != '>')
            {
                paramName += c;
                stream >> c;
            }
            if (paramName == "root" || paramName == "/root") continue;
            std::string paramValue = "";
            if (!stream) throw "Oh shit file has been ended";
            stream >> c;
            while (c != '<')
            {
                paramValue += c;
                stream >> c;
            }
            if (paramName != "current_date")
                dictionary.insert(std::make_pair(paramName, paramValue));
            while (c != '>') stream >> c;
        }
    }

    return dictionary;
}

/*
 * <lol>lol</lol>
 */