#include "None.h"

None::None() : IValue(ValueType::NONE)
{
}

int None::toInt() const
{
    throw InvalidCast(ValueType::NONE, ValueType::INTEGER);
}

std::string None::toString() const
{
    throw InvalidCast(ValueType::NONE, ValueType::STRING);
}

float None::toFloat() const
{
    throw InvalidCast(ValueType::NONE, ValueType::FLOAT);
}

bool None::toBoolean() const
{
    throw InvalidCast(ValueType::NONE, ValueType::BOOLEAN);
}
