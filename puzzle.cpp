#include "puzzle.h"
#include <regex>
#include <string.h>
#include <iostream>
#include <thread>

Puzzle::Puzzle()
{
	m_isSolved = false;
	m_numOfLetters = 0;
	initLetters();
	// use std::string to hold the puzzle and board
	m_puzzleString = m_wordHandler.getPuzzle();
	m_boardString = getBlankPuzzle();
	//printPuzzInfo();
}

void Puzzle::initLetters()
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
	    m_letters[i] = (i + LETTERS_BASE);
	}
	m_letters[NUM_LETTERS] = '\0';
}

void Puzzle::printPuzzInfo()
{
	std::cout << "CATEGORY : " << m_wordHandler.getCategory() << std::endl;
	std::cout.put('\n');
	std::cout << "PUZZLE : " << m_puzzleString << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD: " << m_boardString << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout.put('\n');
	printLetters();
}

WordHandler Puzzle::getWordHandler()
{
	return m_wordHandler;
}

std::string Puzzle::getBlankPuzzle() const
{
	// build a string of the same length as the puzzle with '-' or ' '
	std::string blank;
	blank.reserve(m_wordHandler.getPuzzle().length());
	for (char ch : m_wordHandler.getPuzzle())
	{
		if (ch != ' ')
			blank.push_back('-');
		else
			blank.push_back(' ');
	}
	return blank;
}

const std::string& Puzzle::getBoard() const
{
	return m_boardString;
}

int Puzzle::getNumOfLetters()
{
	return m_numOfLetters;
}

bool Puzzle::getIsSolved()
{
	return m_isSolved;
}

void Puzzle::printLetters()
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

void Puzzle::removeLetter(char l)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (m_letters[i] == l)
		{
			m_letters[i] =' ';
		}
	}
}

bool Puzzle::isInLetters(char charGuess)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (m_letters[i] == charGuess)
		{ 
			return true;
		}
	}
	return false;
}

Puzzle::GuessOutcome Puzzle::guessLetter(char charGuess)
{
	if (!isInLetters(charGuess))
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "You already guessed that letter. Try again. " << std::endl;
		std::cout.put('\n');
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//printPuzzInfo();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		return GuessOutcome::INVALID;
	}
	removeLetter(charGuess);
	int i;
	m_numOfLetters = 0;
	for (size_t i = 0; i < m_puzzleString.size(); i++)
	{
		if (m_puzzleString[i] == charGuess)
		{
			m_numOfLetters++;
			m_boardString[i] = charGuess;
		}
	}
	if (m_boardString == m_puzzleString)
	{
		m_isSolved = true;
 		std::cout << "You have solved the puzzle : " << m_wordHandler.getPuzzle() << std::endl;
		return GuessOutcome::SOLVED;
	}
	else
	{
		if(m_numOfLetters == 0)
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Sorry, no " << charGuess << "'s" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		    //printPuzzInfo();
		    //std::this_thread::sleep_for(std::chrono::seconds(1));
			return GuessOutcome::INCORRECT;
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "There are " << m_numOfLetters << " " << charGuess << "'s" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		    //printPuzzInfo();
		    //std::this_thread::sleep_for(std::chrono::seconds(1));
			return GuessOutcome::CORRECT;
		}
	}
}

void Puzzle::solvePuzzle(std::string puzzGuess)
{
	puzzGuess = std::regex_replace(puzzGuess, std::regex("^ +| +$|( ) +"), "$1");
	transform(puzzGuess.begin(), puzzGuess.end(), puzzGuess.begin(), ::toupper);
	std::cout.put('\n');
	if (puzzGuess == m_wordHandler.getPuzzle())
	{
		m_boardString = m_puzzleString;
		m_isSolved = true;
		std::cout << "You have solved the puzzle : " << m_boardString << std::endl;
		std::cout.put('\n');
	}
	else
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "No that is not correct" << std::endl;
		std::cout.put('\n');
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//printPuzzInfo();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}

/*
int main()
{
	Puzzle p;
	char guess;
	while (!p.getIsSolved())
	{
		p.printPuzzInfo();
		std::cout.put('\n');
		std::cout << "What would you like to do? Either type a letter to guess or type \"solve\" to solve the puzzle or type \"exit\" to exit the game" << std::endl;
		std::cout.put('\n');
		std::cout << ">";
		std::string option;
		getline(std::cin,option);
		if (option != "solve" && option != "exit" && option.length() == 1 && isupper(option.at(0)))
		{
			char guess = option.at(0);
			p.guessLetter(guess);
		}
		else if (option != "solve" && option != "exit" && option.length() == 1 && islower(option.at(0)))
		{
			char guess = toupper(option.at(0));
			p.guessLetter(guess);
		}
		else if (option == "solve")
		{
			std::cout << "What is your guess for the puzzle? " << std::endl;
			std::cout << ">";
			std::string puzzleGuess;
			getline(std::cin,puzzleGuess);
			p.solvePuzzle(puzzleGuess);
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
			p.printPuzzInfo();
			std::this_thread::sleep_for(std::chrono::seconds(1));
		}
	}
	return 0;
}*/