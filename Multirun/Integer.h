#pragma once

#include "IValue.h"

class Integer : public IValue
{
public:
	Integer(int value);

	virtual int toInt() const;
	virtual std::string toString() const;
	virtual float toFloat() const;
	virtual bool toBoolean() const;

private:
	int _value;
};

