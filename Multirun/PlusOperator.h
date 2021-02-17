#pragma once

#include "Operator.h"
#include "ExpressionHandler.h"
#include "InvalidCast.h"

class PlusOperator : public Operator
{
public:
	PlusOperator();

	virtual std::shared_ptr<IValue> execute(const std::string& left, const std::string& right) const;
};
