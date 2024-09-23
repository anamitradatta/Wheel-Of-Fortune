#include "WordHandler.h"
#include <string>

#ifndef PUZZLE_H
#define PUZZLE_H

#define NUM_LETTERS 26
#define LETTERS_BASE 65

class Puzzle
{
	public:
        enum GuessOutcome
		{
			CORRECT,
			INCORRECT,
			SOLVED,
			INVALID
		};

		Puzzle();
		void printPuzzInfo();
		WordHandler getWordHandler();
		char* getBlankPuzzle();
		char* getBoard();
		int getNumOfLetters();
		bool getIsSolved();
		void printLetters();
		void removeLetter(char l);
		bool isInLetters(char charGuess);\
	
	    // returns true if letter is in puzzle
		// returns false if letter is not in puzzle or duplicate letter is given
		GuessOutcome guessLetter(char charGuess);
		void solvePuzzle(std::string puzzGuess);
		
	private:
		WordHandler wordHandler;
		bool isSolved;
		char* puzzleString;
		char* boardString;
		char letters[NUM_LETTERS + 1];
		int numOfLetters;

		void initLetters();
};
#endif
