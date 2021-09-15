#pragma once
#include <string>

class Parameter
{
public:
    enum class ParameterType
    {
        OPTIONAL = 1,
        REQUIRED,
        FUNCTIONAL
    };

    Parameter(ParameterType type);
    ~Parameter() = default;

    const std::string& GetValue();
private:
    std::string _value;
};

