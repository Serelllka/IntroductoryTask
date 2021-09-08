#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "Parser.h"

int main(int argc, char* argv[])
{
    //std::fstream inf("../res/template.txt", std::ifstream::in);

    std::string filepath	= "../res/template.txt";
    std::string output		= "../res/out.txt";
    std::string parameters	= "../res/sample.html";

    std::ifstream input(filepath);
    std::ofstream out(output);

    std::unordered_map<std::string, std::string> dictionary = parser::html::parse(parameters);
    parser::parameters::parse(input, out, dictionary);

    std::ifstream stream(output);

    std::string line;
    while (getline(stream, line))
    {
        std::cout << line << std::endl;
    }
}