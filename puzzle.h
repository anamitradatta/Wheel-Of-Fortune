#include "WordHandler.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>

#ifndef PUZZLE_H
#define PUZZLE_H

using namespace std;

class Puzzle{
	private:
		WordHandler g;
		bool isSolved;
		char* puzzleString;
		char* boardString;
		char* letters;
		bool isRight;
		int numofletters;
		bool isDup;
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
		void solvePuzzle(string puzzGuess);
};
#endif
