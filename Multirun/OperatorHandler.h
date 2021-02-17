#pragma once

#include <vector>
#include <memory>
#include <algorithm>

#include "AssignmentOperator.h"

class OperatorHandler
{
public:
	static bool isOperator(const std::string& symbol);
	static std::shared_ptr<Operator> getOperator(const std::string& symbol);

private:
	static const std::vector<std::shared_ptr<Operator>> _operators;
};

