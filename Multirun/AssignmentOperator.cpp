#include "AssignmentOperator.h"

AssignmentOperator::AssignmentOperator()
{
	this->_symbol = "=";
	this->_priority = Priority::LOW;
	this->_shape = Shape::BOTH;
}

Value AssignmentOperator::execute(const std::string& left, const std::string& right) const
{
	if (ExpressionHandler::getType(left) == ExpressionType::VARIABLE && ExpressionHandler::getType(right) == ExpressionType::VALUE)
	{
		VariableHandler::setVariable(left, right);
	}
	else if (ExpressionHandler::getType(left) == ExpressionType::VARIABLE && ExpressionHandler::getType(right) == ExpressionType::VARIABLE)
	{
		VariableHandler::setVariable(left, VariableHandler::getVariable(right).getValue());
	}
	else
	{
		throw InvalidArgument();
	}
	return Value();
}
