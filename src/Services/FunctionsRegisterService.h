#pragma once

#include<unordered_map>
#include<string>
#include<functional>

class FunctionsRegisterService
{
private:
    std::unordered_map<std::string, std::function<std::string()>> _functions;
public:
    FunctionsRegisterService() = default;
    ~FunctionsRegisterService() = default;

    const std::function<std::string()>& FindFunction(const std::string& functionName);
    void AddFunction(std::string functionName, std::function<std::string()> function);
};
