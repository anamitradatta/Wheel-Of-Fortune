#include "WordHandler.h"
#include <string>

#ifndef PUZZLE_H
#define PUZZLE_H

#define NUM_LETTERS 26
#define LETTERS_BASE 65

class Puzzle
{
	public:
        enum class GuessOutcome
		{
			CORRECT,
			INCORRECT,
			SOLVED,
			INVALID
		};

		Puzzle();
		void PrintPuzzleInfo();
		WordHandler GetWordHandler();
		char* GetBlankPuzzle();
		char* GetBoard();
		int GetNumOfLetters();
		bool GetIsSolved();
		void PrintLetters();
		void RemoveLetter(char l);
		bool IsInLetters(char char_guess);
	
	    // returns true if letter is in puzzle
		// returns false if letter is not in puzzle or duplicate letter is given
		GuessOutcome GuessLetter(char char_guess);
		void SolvePuzzle(std::string puzzle_guess);
		
	private:
		WordHandler m_word_handler;
		bool m_is_solved;
		char* m_puzzle_string;
		char* m_board_string;
		char m_letters[NUM_LETTERS + 1];
		int m_num_of_letters;

		void InitLetters();
};
#endif
