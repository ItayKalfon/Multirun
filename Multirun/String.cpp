#include "String.h"

String::String(const std::string& value) : IValue(ValueType::STRING), _value(value)
{
}

int String::toInt() const
{
    try
    {
        return std::stoi(this->_value);
    }
    catch (const std::logic_error&)
    {
        throw InvalidCast(ValueType::STRING, ValueType::INTEGER);
    }
}

std::string String::toString() const
{
    return this->_value;
}

float String::toFloat() const
{
    try
    {
        return std::stof(this->_value);
    }
    catch (const std::logic_error&)
    {
        throw InvalidCast(ValueType::STRING, ValueType::FLOAT);
    }
}

bool String::toBoolean() const
{
    if (this->_value == "true")
    {
        return true;
    }
    else if (this->_value == "false")
    {
        return false;
    }
    else
    {
        throw InvalidCast(ValueType::STRING, ValueType::BOOLEAN);
    }
}
