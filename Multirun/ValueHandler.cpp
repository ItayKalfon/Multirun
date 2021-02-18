#include "ValueHandler.h"

std::shared_ptr<IValue> ValueHandler::getValue(const std::string& data)
{
    switch (ValueHandler::getType(data))
    {
    case ValueType::BOOLEAN:
        return ValueHandler::createValue(data == "true");
    case ValueType::FLOAT:
        return ValueHandler::createValue(std::stof(data));
    case ValueType::INTEGER:
        return ValueHandler::createValue(std::stoi(data));
    case ValueType::STRING:
        return ValueHandler::createValue(data.substr(1, data.size() - 2));
    default:
        return ValueHandler::createValue();
    }
}

std::shared_ptr<IValue> ValueHandler::createValue(const float data)
{
    return std::make_shared<Float>(data);
}

std::shared_ptr<IValue> ValueHandler::createValue(const int data)
{
    return std::make_shared<Integer>(data);
}

std::shared_ptr<IValue> ValueHandler::createValue(const std::string& data)
{
    return std::make_shared<String>(data);
}

std::shared_ptr<IValue> ValueHandler::createValue(const bool data)
{
    return std::make_shared<Boolean>(data);
}

std::shared_ptr<IValue> ValueHandler::createValue()
{
    return std::make_shared<None>();
}

ValueType ValueHandler::getType(const std::string& data)
{
    if (data.size() == 0)
    {
        return ValueType::NONE;
    }

    if (data == "true" || data == "false")
    {
        return ValueType::BOOLEAN;
    }
    else if ((data.front() == '"' && data.back() == '"') || (data.front() == '\'' && data.back() == '\''))
    {
        return ValueType::STRING;
    }
    else if (std::count(data.begin(), data.end(), '.') <= 1)
    {
        try
        {
            float num = std::stof(data);
            if (data.find('.') == std::string::npos) // Check if float is int
            {
                return ValueType::INTEGER;
            }
            else
            {
                return ValueType::FLOAT;
            }
        }
        catch (const std::logic_error&)
        {
            return ValueType::NONE;
        }
    }
    else
    {
        return ValueType::NONE;
    }
}

bool ValueHandler::isValue(const std::string& data)
{
    return ValueHandler::getType(data) != ValueType::NONE || data == "none";
}

std::shared_ptr<IValue> ValueHandler::castTo(const std::shared_ptr<IValue>& value, const ValueType type)
{
    switch (value->getType())
    {
    case ValueType::BOOLEAN:
        return ValueHandler::createValue(value->toBoolean());
    case ValueType::FLOAT:
        return ValueHandler::createValue(value->toFloat());
    case ValueType::INTEGER:
        return ValueHandler::createValue(value->toInt());
    case ValueType::STRING:
        return ValueHandler::createValue(value->toString());
    default:
        throw InvalidCast(value->getType(), type);
    }
}
