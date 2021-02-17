#pragma once

#include "Operator.h"
#include "ExpressionHandler.h"

class AssignmentOperator : public Operator
{
public:
	AssignmentOperator();

	virtual Value execute(const std::string& left, const std::string& right) const;
};

