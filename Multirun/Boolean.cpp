#include "Boolean.h"

Boolean::Boolean(bool value) : IValue(ValueType::BOOLEAN), _value(value)
{
}

int Boolean::toInt() const
{
    return this->_value ? 1 : 0;
}

std::string Boolean::toString() const
{
    return this->_value ? "true" : "false";
}

float Boolean::toFloat() const
{
    return this->_value ? 1.0f : 0.0f;
}

bool Boolean::toBoolean() const
{
    return this->_value;
}
