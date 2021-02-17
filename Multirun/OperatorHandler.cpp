#include "OperatorHandler.h"

const std::vector<std::shared_ptr<Operator>> OperatorHandler::_operators = [] {
	std::vector<std::shared_ptr<Operator>> operators = std::vector<std::shared_ptr<Operator>> { std::make_shared<AssignmentOperator>() };
	std::sort(operators.begin(), operators.end(), [](std::shared_ptr<Operator> first, std::shared_ptr<Operator> second) { return first->getPriority() > second->getPriority(); }); // Sort by priority
	return operators;
} ();

bool OperatorHandler::isOperator(const std::string& symbol)
{
	return OperatorHandler::getOperator(symbol) != nullptr;
}

std::shared_ptr<Operator> OperatorHandler::getOperator(const std::string& symbol)
{
	for (auto op = OperatorHandler::_operators.begin(); op < OperatorHandler::_operators.end(); op++)
	{
		if ((*op)->getSymbol() == symbol)
		{
			return *op;
		}
	}
	return nullptr;
}
