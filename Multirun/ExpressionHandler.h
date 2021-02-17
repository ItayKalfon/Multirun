#pragma once

#include <string>

#include "VariableHandler.h"
#include "ExpressionType.h"
#include "OperatorHandler.h"

class ExpressionHandler
{
public:
	static ExpressionType getType(const std::string& data);
	static std::shared_ptr<IValue> getValue(const std::string& data);
	static std::shared_ptr<IValue> compute(std::vector<std::string> args);

private:
	static std::string executeOperators(std::vector<std::string> args);
};
