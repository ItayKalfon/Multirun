#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "AssignmentOperator.h"
#include "PlusOperator.h"
#include "MinusOperator.h"

class OperatorHandler
{
public:
	static bool isOperator(const std::string& symbol);
	static std::shared_ptr<Operator> getOperator(const std::string& symbol);
	static std::vector<std::shared_ptr<Operator>> getOperators();

private:
	static const std::vector<std::shared_ptr<Operator>> _operators;
};

