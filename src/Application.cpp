#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "Parser.h"

int main(int argc, char* argv[])
{
    std::ifstream parameters("../res/sample.html");
    std::unordered_map<std::string, std::string> dictionary = parser::html::parse(parameters);

    std::string filepath = "../res/template.txt";
    std::ifstream input = std::ifstream(filepath);

    std::string mode = argv[1];
    if (mode == "-c")
    {
        parser::parameters::parse(input, std::cout, dictionary);
    }
    else if (mode == "-f")
    {
        std::ofstream output(argv[2]);
        parser::parameters::parse(input, output, dictionary);
    }
}