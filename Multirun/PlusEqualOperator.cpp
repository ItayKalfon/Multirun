#include "PlusEqualOperator.h"

PlusEqualOperator::PlusEqualOperator()
{
	this->_symbol = "+=";
	this->_priority = Priority::LOW;
	this->_shape = Shape::BOTH;
}

std::shared_ptr<IValue> PlusEqualOperator::execute(const std::string& left, const std::string& right) const
{
	return OperatorHandler::getOperator("=")->execute(left, Utilities::toString(OperatorHandler::getOperator("+")->execute(left, right)));
}
