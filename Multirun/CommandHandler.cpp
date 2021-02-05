#include "CommandHandler.h"

std::unordered_map <std::string, Variable> CommandHandler::variables;

void CommandHandler::handleCommand(const std::vector<std::string>& args)
{
	switch (CommandHandler::getCommandType(args))
	{
	case Command::ASSIGN:
		if (Variable::getDataType(args[0]) == Type::NONE)
		{
			throw InvalidArgument();
		}

		if (CommandHandler::isVariable(args[0]))
		{
			variables[args[0]].setValue(args[2]);
		}
		else
		{
			variables[args[0]] = Variable(args[2]);
		}
		break;
	case Command::GET_VARIABLE:
		if (CommandHandler::isVariable(args[0]))
		{
			std::cout << variables[args[0]].toString() << std::endl;
		}
		else
		{
			throw InvalidArgument();
		}
		break;
	case Command::ERROR:
		throw InvalidCommand();
	default:
		return;
	}
}

Command CommandHandler::getCommandType(const std::vector<std::string>& args)
{
	if (args.size() == 1 && args[0] == "exit")
	{
		return Command::EXIT;
	}
	else if (args.size() == 3 && args[1] == "=")
	{
		return Command::ASSIGN;
	}
	else if (args.size() == 1)
	{
		return Command::GET_VARIABLE;
	}
	return Command::ERROR;
}

bool CommandHandler::isVariable(const std::string& varName)
{
	return variables.find(varName) != variables.end();
}
