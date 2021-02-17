#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "InvalidArgument.h"
#include "ValueType.h"
#include "IValue.h"

class Utilities
{
public:
	static std::vector<std::string> spilt(const std::string& data, const std::string& sep = " ", bool isDelim = false);
	static std::string toString(float value);
	static std::string toString(ValueType type);
	static std::string toString(const std::shared_ptr<IValue>& value);
};

