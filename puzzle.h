#include "WordHandler.h"
#include <string>

#ifndef PUZZLE_H
#define PUZZLE_H

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
		void shiftLetter(char l);
		bool isInLetters(char charGuess);
		void guessLetter(char charGuess);
		void solvePuzzle(std::string puzzGuess);
		
	private:
		WordHandler wordHandler;
		bool isSolved;
		char* puzzleString;
		char* boardString;
		char* letters;
		bool isRight;
		int numOfLetters;
		bool isDup;
};
#endif
