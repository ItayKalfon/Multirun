#pragma once

#include "Operator.h"
#include "ExpressionHandler.h"

class AssignmentOperator : public Operator
{
public:
	AssignmentOperator();

	virtual std::shared_ptr<IValue> execute(const std::string& left, const std::string& right) const;
};

