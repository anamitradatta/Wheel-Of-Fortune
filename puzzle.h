#include "WordHandler.h"
#include <string>

#ifndef PUZZLE_H
#define PUZZLE_H

#define NUM_LETTERS 26
#define LETTERS_BASE 65

class Puzzle
{
	public:
		Puzzle();
		void printPuzzInfo();
		WordHandler getWordHandler();
		char* getBlankPuzzle();
		char* getBoard();
		int getNumOfLetters();
		bool getIsSolved();
		bool getIsRight();
		bool getIsDup();
		void printLetters();
		void removeLetter(char l);
		bool isInLetters(char charGuess);
		void guessLetter(char charGuess);
		void solvePuzzle(std::string puzzGuess);
		
	private:
		WordHandler wordHandler;
		bool isSolved;
		char* puzzleString;
		char* boardString;
		char letters[NUM_LETTERS + 1];
		bool isRight;
		int numOfLetters;
		bool isDup;

		void initLetters();
};
#endif
