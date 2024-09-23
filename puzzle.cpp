#include "puzzle.h"
#include <regex>
#include <string.h>
#include <iostream>
#include <thread>

Puzzle::Puzzle()
{
	isSolved = false;
	isDup = false;	
	isRight = false;
	numOfLetters = 0;
	initLetters();
	puzzleString = new char[wordHandler.getPuzzle().length()];
	boardString = new char[wordHandler.getPuzzle().length()];
	strcpy(puzzleString, wordHandler.getPuzzle().c_str());
	strcpy(boardString, getBlankPuzzle());
	//printPuzzInfo();
}

void Puzzle::initLetters()
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
	    letters[i] = (i + LETTERS_BASE);
	}
	letters[NUM_LETTERS] = '\0';
}

void Puzzle::printPuzzInfo()
{
	std::cout << "CATEGORY : " << wordHandler.getCategory() << std::endl;
	std::cout.put('\n');
	std::cout << "PUZZLE : " << puzzleString << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD: " << boardString << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout.put('\n');
	printLetters();
}

WordHandler Puzzle::getWordHandler()
{
	return wordHandler;
}

char* Puzzle::getBlankPuzzle()
{
	char* blankPuzzle = new char[wordHandler.getPuzzle().length()];
	for (int i = 0; i < wordHandler.getPuzzle().length(); i++)
	{
		if (wordHandler.getPuzzle().at(i) != ' ')
		{ 
			if(i != wordHandler.getPuzzle().length() - 1)
			{
				blankPuzzle[i] = '-';
			}
			else
			{
				blankPuzzle[i] = '-';	
				blankPuzzle[i+1] = '\0';
			}
		}
		else
		{
			if(i != wordHandler.getPuzzle().length() - 1)
			{
				blankPuzzle[i] = ' ';
			}
			else
			{
				blankPuzzle[i] = ' ';	
				blankPuzzle[i+1] = '\0';
			}
		}
	}
	return blankPuzzle;
}

char* Puzzle::getBoard()
{
	return boardString;
}

int Puzzle::getNumOfLetters()
{
	return numOfLetters;
}

bool Puzzle::getIsSolved()
{
	return isSolved;
}

bool Puzzle::getIsRight()
{
	return isRight;
}

bool Puzzle::getIsDup()
{
	return isDup;
}

void Puzzle::printLetters()
{
	std::cout << "Available letters : "  << std::endl;
	for (int i = 0 ; i < NUM_LETTERS; i++)
	{
		if (letters[i] != ' ')
		{
			std::cout << letters[i] << " ";
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
		if (letters[i] == l)
		{
			letters[i] =' ';
		}
	}
}

bool Puzzle::isInLetters(char charGuess)
{
	for (int i = 0; i < NUM_LETTERS; i++)
	{
		if (letters[i] == charGuess)
		{ 
			return true;
		}
	}
	return false;
}

void Puzzle::guessLetter(char charGuess)
{
	if (!isInLetters(charGuess))
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		isDup = true;	
		std::cout << "You already guessed that letter. Try again. " << std::endl;
		std::cout.put('\n');
		std::this_thread::sleep_for(std::chrono::seconds(1));
		//printPuzzInfo();
		//std::this_thread::sleep_for(std::chrono::seconds(1));
		return;
	}
	isRight = false;
	removeLetter(charGuess);
	int i;
	numOfLetters = 0;
	for (i = 0; i < strlen(puzzleString); i++)
	{
		if (puzzleString[i] == charGuess)
		{
			isRight	= true;
			isDup =false;
			numOfLetters++;
			boardString[i] = charGuess;
		}
	}
	if (strcmp(boardString, puzzleString) == 0)
	{
		isSolved = true;
 		std::cout << "You have solved the puzzle : " << wordHandler.getPuzzle() << std::endl;
	}
	else
	{
		if(numOfLetters == 0)
		{
			isDup = false;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "Sorry, no " << charGuess << "'s" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		    //printPuzzInfo();
		    //std::this_thread::sleep_for(std::chrono::seconds(1));
		}
		else
		{
			std::this_thread::sleep_for(std::chrono::seconds(1));
			std::cout << "There are " << numOfLetters << " " << charGuess << "'s" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
		    //printPuzzInfo();
		    //std::this_thread::sleep_for(std::chrono::seconds(1));

		}
	}
}

void Puzzle::solvePuzzle(std::string puzzGuess)
{
	puzzGuess = std::regex_replace(puzzGuess, std::regex("^ +| +$|( ) +"), "$1");
	transform(puzzGuess.begin(), puzzGuess.end(), puzzGuess.begin(), ::toupper);
	std::cout.put('\n');
	if (puzzGuess == wordHandler.getPuzzle())
	{
		strcpy(boardString,puzzleString);
		isSolved = true;
		std::cout << "You have solved the puzzle : " << boardString << std::endl;
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
		else if (option != "solve" && option !="exit" && option.length()==1 && islower(option.at(0)))
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