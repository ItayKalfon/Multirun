#include "Utilities.h"

std::vector<std::string> Utilities::spilt(const std::string& data, const std::string& sep, bool isDelim)
{
    std::vector<std::string> tokens;
    std::string token = "";
    char delim = 0;
    for (size_t i = 0; i < data.size(); i++)
    {
        if (delim == 0 && data.size() - i > sep.size() && data.substr(i, sep.size()) == sep)
        {
            if (token != "")
            {
                tokens.push_back(token);
                token = "";
            }
            i += sep.size() - 1;
        }
        else
        {
            if (isDelim && delim == 0 && (data[i] == '\'' || data[i] == '"'))
            {
                delim = data[i];
            }
            else if (isDelim && delim != 0 && data[i] == delim)
            {
                delim = 0;
            }
            token += data[i];
        }
    }
    tokens.push_back(token);

    if (delim != 0) // didnt close the string
    {
        throw InvalidArgument();
    }

    return tokens;
}

std::string Utilities::toString(float value)
{
    std::string str = std::to_string(value);
    str.erase(str.find_last_not_of('0') + 1, std::string::npos);
    if (*(str.rbegin()) == '.')
    {
        str += "0";
    }
    return str;
}

std::string Utilities::toString(ValueType type)
{
    switch (type)
    {
    case ValueType::BOOLEAN:
        return "boolean";
    case ValueType::FLOAT:
        return "float";
    case ValueType::INTEGER:
        return "integer";
    case ValueType::STRING:
        return "string";
    default:
        return "none";
    }
}

std::string Utilities::toString(const std::shared_ptr<IValue>& value)
{
    if (value->getType() == ValueType::STRING)
    {
        return "'" + value->toString() + "'";
    }
    else if (value->getType() == ValueType::NONE)
    {
        return "none";
    }
    else
    {
        return value->toString();
    }
}
