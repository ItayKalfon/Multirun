#include "Utilities.h"

std::vector<std::string> Utilities::spilt(const std::string& data)
{
    // Split data using spaces
    std::istringstream iss(data);
    std::vector<std::string> tokens{ std::istream_iterator<std::string>{iss}, std::istream_iterator<std::string>{} };
    int startIndex = 0;
    char delim = NULL;

    // Unite split strings which had spaces
    for (int i = 0; i < tokens.size() && (data.find('\'') != std::string::npos || data.find('\"') != std::string::npos); i++)
    {
        if (startIndex == 0 && (tokens[i].front() == '"' || tokens[i].front() == '\''))
        {
            startIndex = i;
            delim = tokens[i].front();
        }
        
        if (startIndex != 0 && tokens[i].back() == delim)
        {
            if (startIndex != i)
            {
                for (auto token = tokens.begin() + startIndex + 1; token <= tokens.begin() + i; token++)
                {
                    tokens[startIndex] += " " + *token;
                }
                tokens.erase(tokens.begin() + startIndex + 1, tokens.begin() + i + 1);
                i = startIndex + 1;
                startIndex = 0;
            }
            else
            {
                startIndex = 0;
            }
        }
    }

    if (startIndex != 0)
    {
        throw InvalidArgument();
    }
    return tokens;
}
