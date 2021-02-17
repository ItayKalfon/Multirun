#include "PlusOperator.h"

PlusOperator::PlusOperator()
{
	this->_symbol = "+";
	this->_priority = Priority::HIGH;
	this->_shape = Shape::BOTH;
}

Value PlusOperator::execute(const std::string& left, const std::string& right) const
{
	Value leftVal;
	Value rightVal;
	if (ExpressionHandler::getType(left) == ExpressionType::VALUE && ExpressionHandler::getType(right) == ExpressionType::VALUE)
	{
		leftVal = Value(left);
		rightVal = Value(right);
	}
	else if (ExpressionHandler::getType(left) == ExpressionType::VARIABLE && ExpressionHandler::getType(right) == ExpressionType::VALUE)
	{
		leftVal = VariableHandler::getVariable(left).getValue();
		rightVal = Value(right);
	}
	else if (ExpressionHandler::getType(left) == ExpressionType::VALUE && ExpressionHandler::getType(right) == ExpressionType::VARIABLE)
	{
		leftVal = Value(left);
		rightVal = VariableHandler::getVariable(right).getValue();
	}
	else if (ExpressionHandler::getType(left) == ExpressionType::VARIABLE && ExpressionHandler::getType(right) == ExpressionType::VARIABLE)
	{
		leftVal = VariableHandler::getVariable(left).getValue();
		rightVal = VariableHandler::getVariable(right).getValue();
	}
	else
	{
		throw InvalidArgument();
	}
	rightVal.castTo(leftVal.getType());
	float rightFloatVal = 0.0f;
	float leftFloatVal = 0.0f;
	int rightIntVal = 0;
	int leftIntVal = 0;
	std::string rightStrVal = "";
	std::string leftStrVal = "";
	switch (leftVal.getType())
	{
	case ValueType::FLOAT:
		leftVal.getValue(leftFloatVal);
		rightVal.getValue(rightFloatVal);
		return Value(std::to_string(rightFloatVal + leftFloatVal));
	case ValueType::INTEGER:
		leftVal.getValue(leftIntVal);
		rightVal.getValue(rightIntVal);
		return Value(std::to_string(rightIntVal + leftIntVal));
	case ValueType::STRING:
		leftVal.getValue(leftStrVal);
		rightVal.getValue(rightStrVal);
		return Value("'" + leftStrVal + rightStrVal + "'");
	default:
		throw InvalidCast();
	}
	return Value();
}