#include "ExpressionHandler.h"

ExpressionType ExpressionHandler::getType(const std::string& data)
{
    if (Value::isValue(data))
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

Value ExpressionHandler::compute(std::vector<std::string> args)
{
    std::string res = executeOperators(args);
    switch (getType(res))
    {
    case ExpressionType::VALUE:
        return Value(res);
    case ExpressionType::VARIABLE:
        return VariableHandler::getVariable(res).getValue();
    default:
        return Value();
    }
}

std::string ExpressionHandler::executeOperators(std::vector<std::string> args)
{
    std::vector<std::string>::iterator place;
    bool isNotFound;
    for (std::shared_ptr<Operator> op : OperatorHandler::getOperators())
    {
        do
        {
            place = std::find(args.begin(), args.end(), op->getSymbol());
            if (isNotFound = place != args.end())
            {
                switch (op->getShape())
                {
                case Shape::BOTH:
                    if (place != args.begin() && place != args.end() - 1)
                    {
                        *place = op->execute(*(place - 1), *(place + 1)).toString();
                        place -= 1;
                        args.erase(place + 2);
                        args.erase(place);
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
        } while (isNotFound);
    }
    if (args.size() != 1)
    {
        throw InvalidArgument();
    }
    return args[0];
}
