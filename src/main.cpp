#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/interpreter.h"

enum InputMode {Interactive, FileInput, Uninitialized};
InputMode currentMode = Uninitialized;

std::string input = "";

void interactiveMode(Interpreter i)
{
	std::cout << "Starting interactive mode, enter q to exit:";

	while(input.compare("q"))
	{
		std::cout << "\n### ";
		std::getline(std::cin, input);
		i.interpret(input);
	}
}

// Reads a text file with its contents to be used as input
// Returns true on success, false if file could not be found
bool readFromFile(std::string filePath)
{
	std::ifstream file(filePath);

	if(!file.is_open())
	{
		std::cout << "Error: could not find file at \"" << filePath << "\"\n\n";
		return false;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();

	input = buffer.str();

	return true;
}

// If a filepath is given as an argument, use its contents as input
// Otherwise enter interactive mode
bool parseArgs(int argc, char* argv[])
{
	bool parsed = true;

	if(argc == 1)
	{
		currentMode = Interactive;
	}
	else if(argc == 2)
	{
		if(!readFromFile(argv[1]))
		{
			parsed = false;
		}
		currentMode = FileInput;
	}
	else
	{
		 std::cout << "Error: too many arguments\n";
		 parsed = false;
	}

	return parsed;
}

int main(int argc, char * argv[])
{
	Interpreter intp;

	if(parseArgs(argc, argv))
	{
		switch(currentMode)
		{
			case Interactive:
				interactiveMode(intp);
				break;
			case FileInput:
				intp.interpret(input);
				break;
			case Uninitialized:
				break;
			default:
				std::cout << "This shouldn't happen.\n";
				break;
		}
	}
	return 0;
}
