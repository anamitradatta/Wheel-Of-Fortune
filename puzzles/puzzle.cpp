#include "puzzle.h"
#include <regex>
#include <string.h>
#include <iostream>
#include <thread>

Puzzle::Puzzle()
{
	m_is_solved = false;
	m_num_of_letters = 0;
	InitLetters();
	m_puzzle_string = new char[m_word_handler.GetPuzzleString().length()];
	m_board_string = new char[m_word_handler.GetPuzzleString().length()];
	strcpy(m_puzzle_string, m_word_handler.GetPuzzleString().c_str());
	strcpy(m_board_string, GetBlankPuzzle());
	//PrintPuzzleInfo();
}

void Puzzle::InitLetters()
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
	    m_letters[i] = (i + LETTERS_BASE);
	}
	m_letters[NUM_LETTERS] = '\0';
}

void Puzzle::PrintPuzzleInfo()
{
	std::cout << "CATEGORY : " << m_word_handler.GetCategory() << std::endl;
	std::cout.put('\n');
	std::cout << "PUZZLE : " << m_puzzle_string << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD: " << m_board_string << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout.put('\n');
	PrintLetters();
}

WordHandler Puzzle::GetWordHandler()
{
	return m_word_handler;
}

char* Puzzle::GetBlankPuzzle()
{
	char* blank_puzzle = new char[m_word_handler.GetPuzzleString().length()];
	for (int i = 0; i < m_word_handler.GetPuzzleString().length(); i++)
	{
		if (m_word_handler.GetPuzzleString().at(i) != ' ')
		{ 
			if(i != m_word_handler.GetPuzzleString().length() - 1)
			{
				blank_puzzle[i] = '-';
			}
			else
			{
				blank_puzzle[i] = '-';
				blank_puzzle[i+1] = '\0';
			}
		}
		else
		{
			if(i != m_word_handler.GetPuzzleString().length() - 1)
			{
				blank_puzzle[i] = ' ';
			}
			else
			{
				blank_puzzle[i] = ' ';
				blank_puzzle[i+1] = '\0';
			}
		}
	}
	return blank_puzzle;
}

char* Puzzle::GetBoard()
{
	return m_board_string;
}

int Puzzle::GetNumOfLetters()
{
	return m_num_of_letters;
}

bool Puzzle::GetIsSolved()
{
	return m_is_solved;
}

void Puzzle::PrintLetters()
{
	std::cout << "Available letters : "  << std::endl;
	for (int i = 0 ; i < NUM_LETTERS; i++)
	{
		if (m_letters[i] != ' ')
		{
			std::cout << m_letters[i] << " ";
		}
		else
		{
			std::cout << "- ";
		}
	}
	std::cout.put('\n');
}

void Puzzle::RemoveLetter(char l)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (m_letters[i] == l)
		{
			m_letters[i] =' ';
		}
	}
}

bool Puzzle::IsInLetters(char char_guess)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (m_letters[i] == char_guess)
		{ 
			return true;
		}
	}
	return false;
}

Puzzle::GuessOutcome Puzzle::GuessLetter(char char_guess)
{
	if (!IsInLetters(char_guess))
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "You already guessed that letter. Try again. " << std::endl;
		std::cout.put('\n');
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//PrintPuzzleInfo();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		return GuessOutcome::INVALID;
	}
	RemoveLetter(char_guess);
	int i;
	m_num_of_letters = 0;
	for (i = 0; i < strlen(m_puzzle_string); i++)
	{
		if (m_puzzle_string[i] == char_guess)
		{
			m_num_of_letters++;
			m_board_string[i] = char_guess;
		}
	}
	if (strcmp(m_board_string, m_puzzle_string) == 0)
	{
		m_is_solved = true;
 		std::cout << "You have solved the puzzle : " << m_word_handler.GetPuzzleString() << std::endl;
		return GuessOutcome::SOLVED;
	}
	else
	{
		if(m_num_of_letters == 0)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Sorry, no " << char_guess << "'s" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		    //PrintPuzzleInfo();
		    //std::this_thread::sleep_for(std::chrono::seconds(1));
			return GuessOutcome::INCORRECT;
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "There are " << m_num_of_letters << " " << char_guess << "'s" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		    //PrintPuzzleInfo();
		    //std::this_thread::sleep_for(std::chrono::seconds(1));
			return GuessOutcome::CORRECT;
		}
	}
}

void Puzzle::SolvePuzzle(std::string puzzle_guess)
{
	puzzle_guess = std::regex_replace(puzzle_guess, std::regex("^ +| +$|( ) +"), "$1");
	transform(puzzle_guess.begin(), puzzle_guess.end(), puzzle_guess.begin(), ::toupper);
	std::cout.put('\n');
	if (puzzle_guess == m_word_handler.GetPuzzleString())
	{
		strcpy(m_board_string, m_puzzle_string);
		m_is_solved = true;
		std::cout << "You have solved the puzzle : " << m_board_string << std::endl;
		std::cout.put('\n');
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "No that is not correct" << std::endl;
		std::cout.put('\n');
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//PrintPuzzleInfo();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

/*
int main()
{
	Puzzle p;
	char guess;
	while (!p.GetIsSolved())
	{
		p.PrintPuzzleInfo();
		std::cout.put('\n');
		std::cout << "What would you like to do? Either type a letter to guess or type \"solve\" to solve the puzzle or type \"exit\" to exit the game" << std::endl;
		std::cout.put('\n');
		std::cout << ">";
		std::string option;
		getline(std::cin,option);
		if (option != "solve" && option != "exit" && option.length() == 1 && isupper(option.at(0)))
		{
			char guess = option.at(0);
			p.GuessLetter(guess);
		}
		else if (option != "solve" && option != "exit" && option.length() == 1 && islower(option.at(0)))
		{
			char guess = toupper(option.at(0));
			p.GuessLetter(guess);
		}
		else if (option == "solve")
		{
			std::cout << "What is your guess for the puzzle? " << std::endl;
			std::cout << ">";
			std::string puzzleGuess;
			getline(std::cin,puzzleGuess);
			p.SolvePuzzle(puzzleGuess);
		}
		else if (option == "exit")
		{
			if(option == "exit")
			{
				std::cout << "You have exited the game" << std::endl;
				exit(0);
			}
		}
		else
		{
			std::cout << "That is not a valid option " << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			p.PrintPuzzleInfo();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	return 0;
}*/