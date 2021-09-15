#include <iostream>
#include <string>
#include <fstream>
#include <unordered_map>

#include "Tools/Parser.h"
#include "Services/FunctionsRegisterService.h"
#include "Networking/NetworkingManager.h"

int test1(int argc, char* argv[])
{
    std::ofstream  logPath("../log/log.log", std::ios::app);
    Logger logger(logPath);
    Parser parser(logger);

    std::ifstream parameters("../res/sample.html");
    std::unordered_map<std::string, std::string> dictionary = parser.html(parameters);

    std::string filepath = "../res/template.txt";
    std::ifstream input = std::ifstream(filepath);

    std::string mode = argv[1];
    if (mode == "-c")
    {
        parser.parameters(input, std::cout, dictionary);
    }
    else if (mode == "-f")
    {
        std::ofstream output(argv[2]);
        parser.parameters(input, output, dictionary);
    }
}

int main(int argc, char* argv[])
{
    //std::ofstream  logPath("../log/log.log", std::ios::app);
    //Logger logger(logPath);
    //networkingManager nm;
    test1(argc, argv);
    //FunctionsRegister functionsRegister;
    //functionsRegister.AddFunction("lol", [](){return "ebat";});
    //std::cout << functionsRegister.FindFunction("lol")();
    //NetworkingManager networkingManager(logger);
    //networkingManager.Startup();
}