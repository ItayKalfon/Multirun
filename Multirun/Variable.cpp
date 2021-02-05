#include "Variable.h"

Variable::Variable(const std::string& data)
{
    this->setValue(data);
}

Variable::Variable()
{
    this->setValue("");
}

void Variable::getValue(void* result) const
{
    switch (this->_type)
    {
    case Type::BOOLEAN:
        *(static_cast<bool*>(result)) = this->_booleanVal;
        break;
    case Type::FLOAT:
        *(static_cast<float*>(result)) = this->_booleanVal;
        break;
    case Type::INTEGER:
        *(static_cast<int*>(result)) = this->_booleanVal;
        break;
    case Type::STRING:
        *(static_cast<std::string*>(result)) = this->_booleanVal;
        break;
    default:
        break;
    }
}

void Variable::setValue(const std::string& data)
{
    this->_booleanVal = false;
    this->_floatVal = 0.0f;
    this->_intVal = 0;
    this->_stringVal = "";
    this->_type = this->getDataType(data);

    switch (this->_type)
    {
    case Type::BOOLEAN:
        this->_booleanVal = data == "true";
        break;
    case Type::FLOAT:
        this->_floatVal = std::stof(data);
        break;
    case Type::INTEGER:
        this->_intVal = std::stoi(data);
        break;
    case Type::STRING:
        this->_stringVal = data.substr(1, data.size() - 2);
        break;
    default:
        break;
    }
}

std::string Variable::toString() const
{
    switch (this->_type)
    {
    case Type::BOOLEAN:
        return this->_booleanVal ? "true" : "false";
    case Type::FLOAT:
        return std::to_string(this->_floatVal);
    case Type::INTEGER:
        return std::to_string(this->_intVal);
    case Type::STRING:
        return '\'' + this->_stringVal + '\'';
    default:
        return "none";
    }
}

Type Variable::getDataType(const std::string& data)
{
    if (data.size() == 0)
    {
        return Type::NONE;
    }

    if (data == "true" || data == "false")
    {
        return Type::BOOLEAN;
    }
    else if ((data.front() == '"' && data.back() == '"') || (data.front() == '\'' && data.back() == '\''))
    {
        return Type::STRING;
    }
    else if (std::count(data.begin(), data.end(), '.') == 1)
    {
        Type leftType = Variable::getDataType(data.substr(0, data.find(".")));
        Type rightType = Variable::getDataType(data.substr(data.find(".") + 1));
        if (leftType == Type::INTEGER && rightType == Type::INTEGER)
        {
            return Type::FLOAT;
        }
        else
        {
            return Type::NONE;
        }
    }
    else if (data.find_first_not_of("0123456789") == std::string::npos)
    {
        return Type::INTEGER;
    }
    else
    {
        return Type::NONE;
    }
}
