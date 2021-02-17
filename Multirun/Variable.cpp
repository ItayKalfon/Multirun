#include "Variable.h"

Variable::Variable(const std::string& name, const std::string& data) : _name(name), _value(Value(data))
{
}

Variable::Variable(const std::string& name, const Value& value) : _name(name), _value(value)
{
}

std::string Variable::getName() const
{
	return this->_name;
}

Value Variable::getValue() const
{
	return this->_value;
}
