#pragma once

#include <string>

#include "None.h"

enum class Priority
{
	LOW,
	HIGH
};

enum class Shape
{
	LEFT,
	RIGHT,
	BOTH
};

class Operator
{
public:
	std::string getSymbol() const;
	Priority getPriority() const;
	Shape getShape() const;
	virtual std::shared_ptr<IValue> execute(const std::string& left, const std::string& right) const = 0;

protected:
	std::string _symbol;
	Priority _priority;
	Shape _shape;
};

