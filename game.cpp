#include <thread>
#include "game.h"
#include "wheel.h"
#include "reward.h"
#include "penalty.h"
#include "wheeloutcome.h"
#include <iostream>
#include "WordHandler.h"
#include <algorithm>
	
Game::Game()
{
	/*
	std::cout << "CATEGORY : " << m_puzzle.getWordHandler().getCategory() << std::endl;
	std::cout.put('\n');
	std::cout << "PUZZLE : "  << m_puzzle.getWordHandler().getPuzzle() << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD : "  << m_puzzle.getBoard() << std::endl;
	std::cout.put('\n');
	*/
}

Puzzle Game::getPuzzle()
{
	return m_puzzle;
}

void Game::printInfo(User u)
{
	std::cout << "CATEGORY : " << m_puzzle.getWordHandler().getCategory() << std::endl;
	std::cout.put('\n');

	std::cout << "PUZZLE : "  << m_puzzle.getWordHandler().getPuzzle() << std::endl;
	std::cout.put('\n');
	
	std::cout << "It is " << u.getName() << "'s turn" << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD : " << m_puzzle.getBoard() << std::endl;
	std::cout.put('\n');
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "SCORE : $" << u.getPuzzAmt() << std:: endl;
	std::cout.put('\n');
	std::cout << "TOTAL : $" << u.getTotalAmt() << std::endl;
	std::cout.put('\n');
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m_puzzle.printLetters();
	std::cout.put('\n');
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Game::play(User *u)
{
	u->changeCanSpin(); //should make canSpin true
	char guess;
	while (!m_puzzle.getIsSolved() && u->getCanSpin())
	{
		printInfo(*u);
		std::cout << "What would you like to do? " << std::endl;
		std::cout << "Either type \"w\" to spin the wheel and guess a letter or type \"s\" to solve the puzzle or type \"e\" to exit the game" << std::endl;
		std::cout.put('\n');
		std::cout << ">";
		std::string option;
		getline(std::cin,option);
		std::transform(option.begin(), option.end(), option.begin(), ::tolower);
		if (option == "w")
		{
			Wheel w;
			WheelOutcome* a =  &(w.spin());
		
			if (a->canGuess())
			{
				double val = a->getOutcomeVal();
				std::cout << "The wheel landed at $" << val << " dollars" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::string letterGuess;
				bool isValidLetterInput = false;
				Puzzle::GuessOutcome guessOutcome = Puzzle::GuessOutcome::INVALID;
				do
				{
					isValidLetterInput = false;
					std::cout << "Type in a character to guess : " << std::endl;
					std::cout << ">";
					
					getline(std::cin,option);
					if (option.length() == 1)
					{
						if (isalpha(option.at(0)))
						{
							char letterGuess = toupper(option.at(0));
							guessOutcome = m_puzzle.guessLetter(letterGuess);
							isValidLetterInput = true;
						}
						else
						{
							std::cout << "Please type in one letter" << std::endl;
							isValidLetterInput = false;
						}
					}
					else
					{
						std::cout << "Please type in one letter" << std::endl;
						isValidLetterInput = false;
					}
				} while (!isValidLetterInput || guessOutcome == Puzzle::GuessOutcome::INVALID);

				switch (guessOutcome)
				{
					case Puzzle::GuessOutcome::CORRECT:
					case Puzzle::GuessOutcome::SOLVED:
						std::cout << " You gain $" <<val*m_puzzle.getNumOfLetters() << " dollars" << std::endl;
						u->changePuzzAmt(val*m_puzzle.getNumOfLetters());
						break;
					case Puzzle::GuessOutcome::INCORRECT:
					default:
						std::cout << "Sorry, Your turn is over" << std::endl;
						u->changeCanSpin();
						break;
				}
			}
			else
			{
				std::cout << "You landed on bankrupt" << std::endl;
				std::cout << "Sorry, your turn is over and you lose all your money this round" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				u->setZeroPuzz();
				u->changeCanSpin();
			}
		}
		else if (option == "s")
		{
			std::string puzzleGuess;
			std::cout << "What is your guess for the puzzle? : " << std::endl;
			std::cout << ">";
			getline(std::cin,puzzleGuess);
			m_puzzle.solvePuzzle(puzzleGuess);
			if (!m_puzzle.getIsSolved())
			{
				u->changeCanSpin();
			}
		}
		else if (option == "e")
		{
			std::cout << "You have exited the game" << std::endl;
			exit(0);
		}
		else
		{
			std::cout << "That is not a valid option" << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
/*			std::cout << "CATEGORY : " << m_puzzle.getWordHandler().getCategory() << std::endl;
			std::cout.put('\n');
			std::cout << "BOARD : " << m_puzzle.getBoard() << std::endl;
			std::cout.put('\n');
			std::this_thread::sleep_for(std::chrono::seconds(1));
*/
		}
	}

	if (m_puzzle.getIsSolved())
	{
		std::cout << u->getName() << " has solved the puzzle and earned " << u->getPuzzAmt() << " dollars" << std::endl;
		u->changeTotalAmt(u->getPuzzAmt());
	}
}

//main with only 1 player
/*
int main()
{
	Game g;
	//User a("Gogol");
	User* a = new User("Gogol");
	if (!g.getPuzzle().getIsSolved())
	{
		//g.play(&a);
		g.play(a);
	}
	std::cout << "PUZZLE AMT : " <<  a->getPuzzAmt() << std::endl;
	std::cout << "TOTAL AMT : " << a->getTotalAmt() << std::endl;

	return 0;
}
*/

int main()
{
	std::cout << "Welcome to Wheel of Fortune CLI Game" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	Game g;
	User* a = new User("Gogol");
	User* b = new User("Bapi");
	User* c = new User("Gaton");

	a->changeHasTurn();

	while (!g.getPuzzle().getIsSolved())
	{
		if (a->getHasTurn() && !g.getPuzzle().getIsSolved())
		{
			g.play(a);
			b->changeHasTurn();
			a->changeHasTurn();
		}
		if (b->getHasTurn() && !g.getPuzzle().getIsSolved())
		{
			g.play(b);
			c->changeHasTurn();
			b->changeHasTurn();
		}
		if (c->getHasTurn() && !g.getPuzzle().getIsSolved())
		{
			g.play(c);
			a->changeHasTurn();
			c->changeHasTurn();
		}
	}
	return 0;
}
