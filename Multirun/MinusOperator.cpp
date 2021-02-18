#include "MinusOperator.h"

MinusOperator::MinusOperator()
{
	this->_symbol = "-";
	this->_priority = Priority::HIGH;
	this->_shape = Shape::BOTH;
}

std::shared_ptr<IValue> MinusOperator::execute(const std::string& left, const std::string& right) const
{
	auto leftValue = ExpressionHandler::getValue(left);
	auto rightValue = ExpressionHandler::getValue(right);

	switch (leftValue->getType())
	{
	case ValueType::BOOLEAN:
		return ValueHandler::createValue(leftValue->toBoolean() - rightValue->toBoolean());
	case ValueType::INTEGER:
		return ValueHandler::createValue(leftValue->toInt() - rightValue->toInt());
	case ValueType::FLOAT:
		return ValueHandler::createValue(leftValue->toFloat() - rightValue->toFloat());
	case ValueType::NONE:
		throw InvalidArgument();
	case ValueType::STRING:
		throw InvalidArgument();
	default:
		return ValueHandler::createValue();
	}
}
