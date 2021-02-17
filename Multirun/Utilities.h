#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "InvalidArgument.h"

class Utilities
{
public:
	static std::vector<std::string> spilt(const std::string& data, const std::string& sep = " ", bool isDelim = false);
	static bool isDigits(const std::string& data);
};

