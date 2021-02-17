#pragma once

#include "IValue.h"
#include "InvalidCast.h"

class String : public IValue
{
public:
	String(const std::string& value);

	virtual int toInt() const;
	virtual std::string toString() const;
	virtual float toFloat() const;
	virtual bool toBoolean() const;

private:
	std::string _value;
};

