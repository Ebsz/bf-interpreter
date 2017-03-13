#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <string>

class Interpreter
{
	public:
		Interpreter();

		void interpret(std::string input);

	private:
		//Commands
		inline void incrementCell();
		inline void decrementCell();
		inline void movePtrNext();
		inline void movePtrPrev();
		inline void printCurrentCell();
		inline void getInputCurrentCell();
		inline void loopStart();
		inline void loopEnd();

		int cells[30000] = {0};

		std::string input;

		//Points to where we currently are at in our program
		int currentInputIndex;

		// Points to the current cell
		int currentCell;

		int bracketCount;
};
#endif
