#pragma once

#include <string>

#include "ValueType.h"

class IValue
{
public:
	IValue(const ValueType type);

	virtual int toInt() const = 0;
	virtual std::string toString() const = 0;
	virtual float toFloat() const = 0;
	virtual bool toBoolean() const = 0;

	virtual ValueType getType() const;

protected:
	ValueType _type;
};

