#include "Variable.h"

Variable::Variable(const std::string& name, const std::string& data) : _name(name), _value(ValueHandler::getValue(data))
{
}

Variable::Variable(const std::string& name, const std::shared_ptr<IValue>& value) : _name(name), _value(value)
{
}

std::string Variable::getName() const
{
	return this->_name;
}

std::shared_ptr<IValue> Variable::getValue() const
{
	return this->_value;
}
