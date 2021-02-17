#pragma once

#include <exception>
#include <string>

#include "Utilities.h"

struct InvalidCast : std::exception
{
	InvalidCast(const std::string& src, const std::string& dst) : _msg("Invalid cast. Cannot convert from " + src + " to " + dst + ".") {}
	InvalidCast(const ValueType src, const ValueType dst) : _msg("Invalid cast. Cannot convert from " + Utilities::toString(src) + " to " + Utilities::toString(dst) + ".") {}
	virtual const char* what() const noexcept
	{
		return this->_msg.c_str();
	}
	const std::string _msg;
};
