#include "VariableHandler.h"

std::unordered_map<std::string, Value> VariableHandler::_variables;

bool VariableHandler::isValidVariableName(const std::string& name)
{
	for (auto it = name.begin(); it < name.end(); it++)
	{
		if (!(std::isalpha(*it) || *it == '_' || (it != name.begin() && std::isalnum(*it))))
		{
			return false;
		}
	}
	return true;
}

bool VariableHandler::isVariable(const std::string& name)
{
	return VariableHandler::_variables.find(name) != VariableHandler::_variables.end();
}

void VariableHandler::setVariable(const Variable& variable)
{
	VariableHandler::setVariable(variable.getName(), variable.getValue());
}

Variable VariableHandler::getVariable(const std::string& name)
{
	if (VariableHandler::isVariable(name))
	{
		return Variable(name, VariableHandler::_variables[name]);
	}
	else
	{
		throw InvalidArgument();
	}
}

void VariableHandler::setVariable(const std::string& name, const std::string& data)
{
	VariableHandler::setVariable(name, Value(data));
}

void VariableHandler::setVariable(const std::string& name, const Value& value)
{
	if (VariableHandler::isValidVariableName(name))
	{
		VariableHandler::_variables[name] = value;
	}
	else
	{
		throw InvalidArgument();
	}
}
