#include "OperatorHandler.h"

const std::vector<std::shared_ptr<Operator>> OperatorHandler::_operators = [] {
	std::vector<std::shared_ptr<Operator>> operators = std::vector<std::shared_ptr<Operator>> {
		static_cast<std::shared_ptr<Operator>>(std::make_shared<AssignmentOperator>()),
		static_cast<std::shared_ptr<Operator>>(std::make_shared<PlusOperator>()),
		static_cast<std::shared_ptr<Operator>>(std::make_shared<MinusOperator>())
	};
	std::sort(operators.begin(), operators.end(), [] (std::shared_ptr<Operator> first, std::shared_ptr<Operator> second) { return first->getPriority() > second->getPriority(); }); // Sort by priority
	return operators;
} ();

bool OperatorHandler::isOperator(const std::string& symbol)
{
	return OperatorHandler::getOperator(symbol) != nullptr;
}

std::shared_ptr<Operator> OperatorHandler::getOperator(const std::string& symbol)
{
	for (auto op : OperatorHandler::_operators)
	{
		if (op->getSymbol() == symbol)
		{
			return op;
		}
	}
	return nullptr;
}

std::vector<std::shared_ptr<Operator>> OperatorHandler::getOperators()
{
	return OperatorHandler::_operators;
}
