#pragma once

#include "Operator.h"
#include "ExpressionHandler.h"

class MinusOperator : public Operator
{
public:
	MinusOperator();

	virtual std::shared_ptr<IValue> execute(const std::string& left, const std::string& right) const;
};

