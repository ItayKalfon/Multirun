#include "CommandHandler.h"

void CommandHandler::handleCommand(const std::vector<std::string>& args)
{
	//AssignmentOperator op = AssignmentOperator();
	Value res = ExpressionHandler::compute(args);
	if (res.getType() != ValueType::NONE)
	{
		std::cout << res.toString() << std::endl;
	}
	/*
	switch (CommandHandler::getCommandType(args))
	{
	case Command::ASSIGN:
		op.execute(args[0], args[2]);
		break;
	case Command::GET_VARIABLE:
		std::cout << VariableHandler::getVariable(args[0]).getValue().toString() << std::endl;
		break;
	case Command::ERROR:
		throw InvalidCommand();
	default:
		return;
	}
	*/
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
