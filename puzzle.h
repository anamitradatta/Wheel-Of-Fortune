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
		std::string getBlankPuzzle() const;   // returns a string with dashes/spaces
		const std::string& getBoard() const;
		int getNumOfLetters();
		bool getIsSolved();
		void printLetters();
		void removeLetter(char l);
		bool isInLetters(char charGuess);
	
	    // returns true if letter is in puzzle
		// returns false if letter is not in puzzle or duplicate letter is given
		GuessOutcome guessLetter(char charGuess);
		void solvePuzzle(std::string puzzGuess);
		
	private:
		WordHandler m_wordHandler;
		bool m_isSolved;
		std::string m_puzzleString;
		std::string m_boardString;
		char m_letters[NUM_LETTERS + 1];
		int m_numOfLetters;

		void initLetters();
};
#endif
