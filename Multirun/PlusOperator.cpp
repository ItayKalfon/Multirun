#include "PlusOperator.h"

PlusOperator::PlusOperator()
{
	this->_symbol = "+";
	this->_priority = Priority::HIGH;
	this->_shape = Shape::BOTH;
}

std::shared_ptr<IValue> PlusOperator::execute(const std::string& left, const std::string& right) const
{
	// TODO: Implement operator
	return nullptr;
}