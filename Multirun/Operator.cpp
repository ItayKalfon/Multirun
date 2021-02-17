#include "Operator.h"

std::string Operator::getSymbol() const
{
    return this->_symbol;
}

Priority Operator::getPriority() const
{
    return this->_priority;
}
