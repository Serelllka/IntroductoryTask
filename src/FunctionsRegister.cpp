//
// Created by vprog on 9/11/2021.
//

#include "FunctionsRegister.h"
#include "MyException.h"

const std::function<std::string()> &FunctionsRegister::FindFunction(const std::string &functionName)
{
    auto obtainedFunction = _functions.find(functionName);
    if (obtainedFunction == _functions.end())
    {
        throw MyException("lol");
    }
    return obtainedFunction->second;
}

void FunctionsRegister::AddFunction(std::string functionName, std::function<std::string()> function)
{
    auto obtainedFunction = _functions.find(functionName);
    if (obtainedFunction != _functions.end())
    {
        return;
    }
    _functions.insert(std::make_pair(functionName, function));
}
