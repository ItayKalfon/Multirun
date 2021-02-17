#include "Value.h"

Value::Value()
{
    setValue("");
}

Value::Value(const std::string& data)
{
    setValue(data);
}

void Value::setValue(const std::string& data)
{
    this->_booleanVal = false;
    this->_floatVal = 0.0f;
    this->_intVal = 0;
    this->_stringVal = "";
    this->_type = this->getDataType(data);

    switch (this->_type)
    {
    case ValueType::BOOLEAN:
        this->_booleanVal = data == "true";
        break;
    case ValueType::FLOAT:
        this->_floatVal = std::stof(data);
        break;
    case ValueType::INTEGER:
        this->_intVal = std::stoi(data);
        break;
    case ValueType::STRING:
        this->_stringVal = data.substr(1, data.size() - 2);
        break;
    default:
        break;
    }
}

void Value::getValue(int& result) const
{
    if (this->_type == ValueType::INTEGER)
    {
        result = this->_intVal;
    }
    else
    {
        throw InvalidCast();
    }
}

void Value::getValue(bool& result) const
{
    if (this->_type == ValueType::BOOLEAN)
    {
        result = this->_booleanVal;
    }
    else
    {
        throw InvalidCast();
    }
}

void Value::getValue(float& result) const
{
    if (this->_type == ValueType::FLOAT)
    {
        result = this->_floatVal;
    }
    else
    {
        throw InvalidCast();
    }
}

void Value::getValue(std::string& result) const
{
    if (this->_type == ValueType::STRING)
    {
        result = this->_stringVal;
    }
    else
    {
        throw InvalidCast();
    }
}

ValueType Value::getType() const
{
    return Value::_type;
}

ValueType Value::getDataType(const std::string& data)
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
    else if (std::count(data.begin(), data.end(), '.') == 1 && *data.begin() != '.' && *data.rbegin() != '.' && data.substr(0, 2) != "-.")
    {
        if (((data[0] == '-' && Utilities::isDigits(data.substr(1, data.find('.') - 1))) || Utilities::isDigits(data.substr(0, data.find('.')))) && Utilities::isDigits(data.substr(data.find(".") + 1)))
        {
            return ValueType::FLOAT;
        }
        else
        {
            return ValueType::NONE;
        }
    }
    else if ((data[0] == '-' && Utilities::isDigits(data.substr(1))) || Utilities::isDigits(data))
    {
        return ValueType::INTEGER;
    }
    else
    {
        return ValueType::NONE;
    }
}

bool Value::isValue(const std::string& data)
{
    return getDataType(data) != ValueType::NONE || data == "none";
}

std::string Value::toString() const
{
    switch (this->_type)
    {
    case ValueType::BOOLEAN:
        return this->_booleanVal ? "true" : "false";
    case ValueType::FLOAT:
        return std::to_string(this->_floatVal);
        case ValueType::INTEGER:
        return std::to_string(this->_intVal);
    case ValueType::STRING:
        return '\'' + this->_stringVal + '\'';
    default:
        return "none";
    }
}

void Value::castTo(const ValueType& type)
{
    switch (this->_type)
    {
    case ValueType::BOOLEAN:
        switch (type)
        {
        case ValueType::FLOAT:
            this->setValue(this->_booleanVal ? "1.0" : "0.0");
            break;
        case ValueType::INTEGER:
            this->setValue(this->_booleanVal ? "1" : "0");
            break;
        case ValueType::STRING:
            this->setValue("'" + this->toString() + "'");
            break;
        case ValueType::NONE:
            this->setValue("");
            break;
        }
        break;
    case ValueType::FLOAT:
        switch (type)
        {
        case ValueType::BOOLEAN:
            this->setValue(this->_floatVal != 0.0f ? "true" : "false");
            break;
        case ValueType::INTEGER:
            this->setValue(std::to_string(static_cast<int>(this->_floatVal)));
            break;
        case ValueType::STRING:
            this->setValue("'" + this->toString() + "'");
            break;
        case ValueType::NONE:
            this->setValue("");
            break;
        }
        break;
    case ValueType::INTEGER:
        switch (type)
        {
        case ValueType::BOOLEAN:
            this->setValue(this->_intVal != 0 ? "true" : "false");
            break;
        case ValueType::FLOAT:
            this->setValue(std::to_string(static_cast<float>(this->_intVal)));
            break;
        case ValueType::STRING:
            this->setValue("'" + this->toString() + "'");
            break;
        case ValueType::NONE:
            this->setValue("");
            break;
        }
        break;
    case ValueType::STRING:
        if (type != ValueType::STRING)
        {
            this->setValue(this->toString());
        }
        break;
    }
}
