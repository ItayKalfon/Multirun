#pragma once

#include <string>
#include <unordered_map>

#include "InvalidArgument.h"
#include "ValueHandler.h"
#include "IValue.h"

class Variable
{
public:
	Variable(const std::string& name, const std::string& data);
	Variable(const std::string& name, const std::shared_ptr<IValue>& value);

	std::string getName() const;
	std::shared_ptr<IValue> getValue() const;

private:
	std::string _name;
	std::shared_ptr<IValue> _value;
};

