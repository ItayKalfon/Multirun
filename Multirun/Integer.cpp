#include "Integer.h"

Integer::Integer(int value) : IValue(ValueType::INTEGER), _value(value)
{
}

int Integer::toInt() const
{
    return this->_value;
}

std::string Integer::toString() const
{
    return std::to_string(this->_value);
}

float Integer::toFloat() const
{
    return static_cast<float>(this->_value);
}

bool Integer::toBoolean() const
{
    return this->_value != 0;
}
