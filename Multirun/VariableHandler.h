#pragma once

#include <string>
#include <unordered_map>

#include "Variable.h"
#include "IValue.h"
#include "InvalidArgument.h"
#include "ValueHandler.h"

class VariableHandler
{
public:
	static bool isValidVariableName(const std::string& name);
	static bool isVariable(const std::string& name);

	static void setVariable(const std::string& name, const std::string& data);
	static void setVariable(const std::string& name, const std::shared_ptr<IValue>& value);
	static void setVariable(const Variable& variable);
	static Variable getVariable(const std::string& name);

private:
	static std::unordered_map<std::string, std::shared_ptr<IValue>> _variables;
};

