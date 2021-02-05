#pragma once

#include "Variable.h"
#include "InvalidCommand.h"
#include "InvalidArgument.h"

#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>

enum class Command
{
	ERROR,
	EXIT,
	ASSIGN,
	GET_VARIABLE
};

class CommandHandler
{
public:
	static void handleCommand(const std::vector<std::string>& args);

private:
	static std::unordered_map <std::string, Variable> variables;

	static Command getCommandType(const std::vector<std::string>& args);
	static bool isVariable(const std::string& varName);
};

