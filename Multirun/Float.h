#pragma once

#include "IValue.h"
#include "Utilities.h"

class Float : public IValue
{
public:
	Float(float value);

	virtual int toInt() const;
	virtual std::string toString() const;
	virtual float toFloat() const;
	virtual bool toBoolean() const;

private:
	float _value;
};

