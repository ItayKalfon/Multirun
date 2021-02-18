#pragma once

#include "Operator.h"
#include "OperatorHandler.h"

class PlusEqualOperator : public Operator
{
public:
	PlusEqualOperator();

	virtual std::shared_ptr<IValue> execute(const std::string& left, const std::string& right) const;
};

