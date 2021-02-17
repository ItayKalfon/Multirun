#pragma once

#include "IValue.h"

class Boolean : public IValue
{
public:
	Boolean(bool value);

	virtual int toInt() const;
	virtual std::string toString() const;
	virtual float toFloat() const;
	virtual bool toBoolean() const;

private:
	bool _value;
};

