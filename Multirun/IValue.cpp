#include "IValue.h"

IValue::IValue(const ValueType type) : _type(type)
{
}

ValueType IValue::getType() const
{
    return this->_type;
}
