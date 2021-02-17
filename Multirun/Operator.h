#pragma once

#include <string>

#include "Value.h"

enum class Priority
{
	LOW,
	HIGH
};

class Operator
{
public:
	std::string getSymbol() const;
	Priority getPriority() const;
	virtual Value execute(const std::string& left, const std::string& right) const = 0;

protected:
	std::string _symbol;
	Priority _priority;
};

