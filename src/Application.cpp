#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>
#include <chrono>

#include "Parser.h"
#include "Logger.h"
#include "FunctionsRegister.h"

int test1(int argc, char* argv[])
{
    std::ofstream  logPath("../log/log.log", std::ios::app);
    Logger logger(logPath);

    std::ifstream parameters("../res/sample.html");
    std::unordered_map<std::string, std::string> dictionary = parser::html::parse(parameters, &logger);

    std::string filepath = "../res/template.txt";
    std::ifstream input = std::ifstream(filepath);

    std::string mode = argv[1];
    if (mode == "-c")
    {
        parser::parameters::parse(input, std::cout, dictionary, &logger);
    }
    else if (mode == "-f")
    {
        std::ofstream output(argv[2]);
        parser::parameters::parse(input, output, dictionary, &logger);
    }
}

int main(int argc, char* argv[])
{
    //test1(argc, argv);
    FunctionsRegister functionsRegister;
    functionsRegister.AddFunction("lol", [](){return "ebat";});
    std::cout << functionsRegister.FindFunction("lol")();
}