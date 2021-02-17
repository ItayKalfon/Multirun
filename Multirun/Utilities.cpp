#include "Utilities.h"

std::vector<std::string> Utilities::spilt(const std::string& data, const std::string& sep, bool isDelim)
{
    std::vector<std::string> tokens;
    std::string token = "";
    char delim = 0;
    for (int i = 0; i < data.size(); i++)
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

bool Utilities::isDigits(const std::string& data)
{
    return data.find_first_not_of("0123456789") == std::string::npos;
}
