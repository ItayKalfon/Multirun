#include "ValueHandler.h"

std::shared_ptr<IValue> ValueHandler::getValue(const std::string& data)
{
    switch (ValueHandler::getType(data))
    {
    case ValueType::BOOLEAN:
        return std::make_shared<Boolean>(data == "true");
    case ValueType::FLOAT:
        return std::make_shared<Float>(std::stof(data));
    case ValueType::INTEGER:
        return std::make_shared<Integer>(std::stoi(data));
    case ValueType::STRING:
        return std::make_shared<String>(data.substr(1, data.size() - 2));
    default:
        return std::make_shared<None>();
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
    try
    {
        float num = std::stof(data);
        if (static_cast<float>(static_cast<int>(num)) == num) // Check if float is int
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
        return std::make_unique<None>();
    }
}
