#pragma once

#include <string>

#include "VariableHandler.h"
#include "ExpressionType.h"
#include "OperatorHandler.h"
#include "Value.h"

class ExpressionHandler
{
public:
	static ExpressionType getType(const std::string& data);
	static Value compute(const std::vector<std::string>& args);
};
