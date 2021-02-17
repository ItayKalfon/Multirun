#include "Float.h"

Float::Float(float value) : IValue(ValueType::FLOAT), _value(value)
{
}

int Float::toInt() const
{
    return static_cast<int>(this->_value);
}

std::string Float::toString() const
{
    return Utilities::toString(this->_value);
}

float Float::toFloat() const
{
    return this->_value;
}

bool Float::toBoolean() const
{
    return this->_value != 0.0f;
}
