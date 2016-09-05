#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

class Interpreter
{
	public:
	Interpreter();

	void interpret(std::string input);

	private:
	void reset();

	//Commands
	void incrementCell();
	void decrementCell();
	void movePtrNext();
	void movePtrPrev();
	void printCurrentCell();
	void getInputCurrentCell();
	void leftLoop();
	void rightLoop();
	
	int cells[30000];

	std::string input;

	//Points to where we currently are at in our program
	int currentInputIndex;

	// Points to the current cell
	int currentCell = 0;
};

#endif
