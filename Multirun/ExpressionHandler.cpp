#include "ExpressionHandler.h"

ExpressionType ExpressionHandler::getType(const std::string& data)
{
    if (ValueHandler::isValue(data))
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

std::shared_ptr<IValue> ExpressionHandler::getValue(const std::string& data)
{
    if (ExpressionHandler::getType(data) == ExpressionType::VALUE)
    {
        return ValueHandler::getValue(data);
    }
    else if (ExpressionHandler::getType(data) == ExpressionType::VARIABLE)
    {
        return VariableHandler::getVariable(data).getValue();
    }
    else
    {
        return ValueHandler::createValue();
    }
}

std::shared_ptr<IValue> ExpressionHandler::compute(std::vector<std::string> args)
{
    std::string res = executeOperators(args);
    switch (getType(res))
    {
    case ExpressionType::VALUE:
        return ValueHandler::getValue(res);
    case ExpressionType::VARIABLE:
        return VariableHandler::getVariable(res).getValue();
    default:
        return ValueHandler::createValue();
    }
}

std::string ExpressionHandler::executeOperators(std::vector<std::string> args)
{
    for (Priority priority = Priority::HIGH; priority != Priority::NO_PRIORITY; priority = static_cast<Priority>(static_cast<int>(priority) - 1))
    {
        for (int i = 0; i < args.size(); i++)
        {
            if (ExpressionHandler::getType(args[i]) == ExpressionType::OPERATOR && OperatorHandler::getOperator(args[i])->getPriority() == priority)
            {
                switch (OperatorHandler::getOperator(args[i])->getShape())
                {
                case Shape::BOTH:
                    if (i != 0 && i != args.size() - 1)
                    {
                        args[i] = Utilities::toString(OperatorHandler::getOperator(args[i])->execute(args[i - 1], args[i + 1]));
                        i -= 1;
                        args.erase(args.begin() + i + 2);
                        args.erase(args.begin() + i);
                    }
                    else
                    {
                        throw InvalidArgument();
                    }
                    break;
                default:
                    break;
                }
            }
        }
    }
    if (args.size() != 1)
    {
        throw InvalidArgument();
    }
    return args[0];
}
