#pragma once

#include <string>
#include <unordered_map>

#include "Variable.h"
#include "InvalidArgument.h"

class VariableHandler
{
public:
	static bool isValidVariableName(const std::string& name);
	static bool isVariable(const std::string& name);

	static void setVariable(const std::string& name, const std::string& data);
	static void setVariable(const std::string& name, const Value& value);
	static void setVariable(const Variable& variable);
	static Variable getVariable(const std::string& name);

private:
	static std::unordered_map<std::string, Value> _variables;
};

