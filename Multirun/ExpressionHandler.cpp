#include "ExpressionHandler.h"

ExpressionType ExpressionHandler::getType(const std::string& data)
{
    if (Value::getDataType(data) != ValueType::NONE)
    {
        return ExpressionType::VALUE;
    }
    else if (VariableHandler::isValidVariableName(data))
    {
        return ExpressionType::VARIABLE;
    }
    else if (OperatorHandler::isOperator(data))
    {
        return ExpressionType::OPERATOR;
    }
    else
    {
        return ExpressionType::EXPRESSION;
    }
}

Value ExpressionHandler::compute(const std::vector<std::string>& args)
{
    for (int i = 0; i < args.size(); i++)
    {
        if (ExpressionHandler::getType(args[i]) == ExpressionType::VALUE)
        {
            return Value(args[i]);
        }
        else if (ExpressionHandler::getType(args[i]) == ExpressionType::VARIABLE)
        {
            return VariableHandler::getVariable(args[i]).getValue();
        }
        else if (ExpressionHandler::getType(args[i]) == ExpressionType::OPERATOR)
        {
            // TODO: Add operator handling
        }
    }
    return Value();
}
