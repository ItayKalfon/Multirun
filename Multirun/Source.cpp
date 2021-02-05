#include "CommandHandler.h"
#include "Utilities.h"

int main()
{
	std::cout << "Welcome to the Multirun interpreter!" << std::endl;

	std::string command = "";
	std::vector<std::string> args;
	do
	{
		std::cout << "> ";
		std::getline(std::cin, command);

		try
		{
			args = Utilities::spilt(command);
			CommandHandler::handleCommand(args);
		}
		catch (const std::exception& e)
		{
			std::cout << e.what() << std::endl;
		}
	} while (command != "exit");

	return 0;
}