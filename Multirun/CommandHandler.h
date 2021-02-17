#pragma once

#include <unordered_map>
#include <string>
#include <iostream>

#include "ExpressionHandler.h"
#include "InvalidCommand.h"

enum class Command
{
	EXIT,
	ASSIGN,
	GET_VARIABLE,
	ERROR
};

class CommandHandler
{
public:
	static void handleCommand(const std::vector<std::string>& args);

private:
	static Command getCommandType(const std::vector<std::string>& args);
};