#pragma once

#include "IValue.h"
#include "InvalidCast.h"

class None : public IValue
{
public:
	None();

	virtual int toInt() const;
	virtual std::string toString() const;
	virtual float toFloat() const;
	virtual bool toBoolean() const;
};

