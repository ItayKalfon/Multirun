#pragma once

#include <exception>
#include <string>

struct InvalidCommand : std::exception
{
	virtual const char* what() const noexcept
	{
		return "Invalid command!"; 
	}
};