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
        return std::make_shared<None>();
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
        return std::make_unique<None>();
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
                        *place = Utilities::toString(op->execute(*(place - 1), *(place + 1)));
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
