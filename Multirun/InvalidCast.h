#pragma once

#include <exception>
#include <string>

struct InvalidCast : std::exception
{
	virtual const char* what() const noexcept
	{
		return "Invalid cast!";
	}
};
