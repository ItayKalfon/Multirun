#pragma once

#include <string>
#include <unordered_map>

#include "Value.h"
#include "InvalidArgument.h"

class Variable
{
public:
	Variable(const std::string& name, const std::string& data);
	Variable(const std::string& name, const Value& value);

	std::string getName() const;
	Value getValue() const;

private:
	std::string _name;
	Value _value;
};

