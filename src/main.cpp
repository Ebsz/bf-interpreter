#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/interpreter.h"
// TODO:
// 			* Make a struct to contain cells

enum inputMode {Interactive, FileInput, Uninitialized};
inputMode currentMode = Uninitialized;

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
// Returns true on success, otherwise false if something went wrong
bool readFromFile(std::string filePath)
{
	std::ifstream file(filePath);

	if(!file.is_open())
	{
		std::cout << "Error: could not find file at \"" << filePath << "\"\n";
		return false;
	}
	std::stringstream buffer;
	buffer << file.rdbuf();

	input = buffer.str();

	return true;
}

// If a filepath is given as an argument, use its contents as input,
// otherwise we enter interactive mode
void parseArgs(int argc, char* argv[])
{
	if(argc == 1)
	{
		currentMode = Interactive;
		return;
	}
	else if(argc == 2)
	{
		readFromFile(argv[1]);	
		currentMode = FileInput;
	}
	else
	{
		 std::cout << "Error: too many arguments\n";
		 return;
	}
}

int main(int argc, char * argv[])
{
	Interpreter intp;
	parseArgs(argc, argv);
	
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
	}

	return 0;
}
