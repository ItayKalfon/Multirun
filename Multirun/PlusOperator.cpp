#include "PlusOperator.h"

PlusOperator::PlusOperator()
{
	this->_symbol = "+";
	this->_priority = Priority::HIGH;
	this->_shape = Shape::BOTH;
}

std::shared_ptr<IValue> PlusOperator::execute(const std::string& left, const std::string& right) const
{
	auto leftVal = ExpressionHandler::getValue(left);
	auto rightVal = ExpressionHandler::getValue(right);
	
	switch (leftVal->getType())
	{
	case ValueType::BOOLEAN:
		return ValueHandler::createValue(leftVal->toBoolean() + rightVal->toBoolean());
	case ValueType::FLOAT:
		return ValueHandler::createValue(leftVal->toFloat() + rightVal->toFloat());
	case ValueType::INTEGER:
		return ValueHandler::createValue(leftVal->toInt() + rightVal->toInt());
	case ValueType::STRING:
		return ValueHandler::createValue(leftVal->toString() + rightVal->toString());
	case ValueType::NONE:
		throw InvalidArgument();
	default:
		return ValueHandler::createValue();
	}
}