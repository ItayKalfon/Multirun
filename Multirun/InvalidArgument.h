#pragma once

#include <exception>
#include <string>

struct InvalidArgument : std::exception
{
	virtual const char* what() const noexcept
	{
		return "Invalid argument!";
	}
};