#include <iostream>
#include "interpreter.h"


Interpreter::Interpreter() :  currentInputIndex(0), input()
{
}

void Interpreter::reset()
{
	for(int i = 0; i< 30000;i++)
	{
		cells[i] = 0;
	}
	currentCell=0;
	currentInputIndex=0;
}

void Interpreter::interpret(std::string in)
{	
	reset();
	input = in;
	int inputLength = in.length();

	while(currentInputIndex < inputLength)
	{
		switch(input[currentInputIndex])
		{
			case '+':
				incrementCell();
				break;

			case '-':
				decrementCell();
				break;

			case '>':
				movePtrNext();
				break;

			case '<':
				movePtrPrev();
				break;

			case '.':
				printCurrentCell();
				break;

			case ',':
				getInputCurrentCell();
				break;
		
			case '[':
				leftLoop();
				break;
			
			case ']':
				rightLoop();
				break;

			default:
				break;
		}
		currentInputIndex++;
	}
}

// '+' command
void Interpreter::incrementCell()
{
	cells[currentCell]++;
}

// '-' command 
void Interpreter::decrementCell()
{
	if(cells[currentCell] >0)
	{
		cells[currentCell]--;
	}
}

// '>' command
void Interpreter::movePtrNext()
{
	currentCell++;

}
// '<' command
void Interpreter::movePtrPrev()
{
	if(currentCell > 0)
	{
		currentCell--;
	}
}

// '.'command
void Interpreter::printCurrentCell()
{
	std::cout << char(cells[currentCell]);
}

// ',' command
void Interpreter::getInputCurrentCell()
{
	char in;
	in = std::cin.get();
	cells[currentCell] = int(in);
	std::cin.ignore();
}

// '[' command
//	Jumps to corresponding bracket if value of current cell is 0, otherwise enters the loop
void Interpreter::leftLoop()
{
	if(cells[currentCell] == 0)
	{
		while ( input[currentInputIndex] != ']')
		{
			currentInputIndex++;
		}
	}
}

// ']' command
// Moves back to corresponding bracket if value of current cell isnt 0,
// otherwise exits the loop
void Interpreter::rightLoop()
{
	if(cells[currentCell] != 0)
	{
		while(input[currentInputIndex] != '[')
		{
			currentInputIndex--;	
		}
	}
}
