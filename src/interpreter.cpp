#include <iostream>
#include "../include/interpreter.h"

Interpreter::Interpreter() :  currentInputIndex(0), currentCell(0), bracketCount(1), input()
{
}

void Interpreter::interpret(std::string in)
{
	int inputLength = in.length();
	currentInputIndex=0;
	currentCell=0;
	input = in;

	// Will run until EOF
	while(currentInputIndex < inputLength)
	{
		switch(input[currentInputIndex])
		{
			case '+':
				incrementCell();
				currentInputIndex++;
				break;

			case '-':
				decrementCell();
				currentInputIndex++;
				break;

			case '>':
				movePtrNext();
				currentInputIndex++;
				break;

			case '<':
				movePtrPrev();
				currentInputIndex++;
				break;

			case '.':
				printCurrentCell();
				currentInputIndex++;
				break;

			case ',':
				getInputCurrentCell();
				currentInputIndex++;
				break;

			case '[':
				loopStart();
				break;

			case ']':
				loopEnd();
				break;

			default:
				currentInputIndex++;
				break;
		}
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
	cells[currentCell]--;
}

// '>' command
void Interpreter::movePtrNext()
{
	currentCell++;

}
// '<' command
void Interpreter::movePtrPrev()
{
	currentCell--;
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
	cells[currentCell] = (int)in;
	std::cin.ignore();
}

// '[' command
//	Jumps after corresponding bracket if value of current cell is 0, otherwise enters the loop
void Interpreter::loopStart()
{
	bracketCount = 1;

	if(cells[currentCell] == 0)
	{
		do {
			currentInputIndex++;

			if(input[currentInputIndex] == '[') {
				bracketCount++;
			}
			else if(input[currentInputIndex] == ']')
			{
				bracketCount--;
			}

		} while (input[currentInputIndex] != ']' || bracketCount > 0);
	}
		currentInputIndex++;
}

// ']' command
// Moves back to corresponding bracket if value of current cell isnt 0,
// otherwise exits the loop
void Interpreter::loopEnd()
{
	bracketCount = 1;

	if(cells[currentCell] != 0)
	{
		do {
			currentInputIndex--;

			if(input[currentInputIndex] == ']') {
				bracketCount++;
			} else if(input[currentInputIndex] == '[') {
				bracketCount--;
			}

		} while(input[currentInputIndex] != '[' || bracketCount > 0);
	}
		currentInputIndex++;
}
