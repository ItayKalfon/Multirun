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

	if (leftVal->getType() == ValueType::NONE || rightVal->getType() == ValueType::NONE)
	{
		throw InvalidArgument();
	}
	
	switch (leftVal->getType())
	{
	case ValueType::BOOLEAN:
		return ValueHandler::createValue(leftVal->toBoolean() + rightVal->toBoolean());
	case ValueType::FLOAT:
		return ValueHandler::createValue(rightVal->toFloat() + rightVal->toFloat());
	case ValueType::INTEGER:
		return ValueHandler::createValue(leftVal->toInt() + rightVal->toInt());
	case ValueType::STRING:
		return ValueHandler::createValue(leftVal->toString() + rightVal->toString());
	default:
		return std::make_shared<None>();
	}
}