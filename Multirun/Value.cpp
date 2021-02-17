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

void Value::getValue(void* result) const
{
    switch (this->_type)
    {
    case ValueType::BOOLEAN:
        *(static_cast<bool*>(result)) = this->_booleanVal;
        break;
    case ValueType::FLOAT:
        *(static_cast<float*>(result)) = this->_booleanVal;
        break;
    case ValueType::INTEGER:
        *(static_cast<int*>(result)) = this->_booleanVal;
        break;
    case ValueType::STRING:
        *(static_cast<std::string*>(result)) = this->_booleanVal;
        break;
    default:
        break;
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
