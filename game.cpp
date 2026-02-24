#include <thread>
#include <iostream>
#include <algorithm>
#include <array>

#include "game.h"
#include "wheel.h"
#include "reward.h"
#include "penalty.h"
#include "wheeloutcome.h"
#include "WordHandler.h"
	
Game::Game()
{
	/*
	std::cout << "CATEGORY : " << m_puzzle.GetWordHandler().GetCategory() << std::endl;
	std::cout.put('\n');
	std::cout << "PUZZLE : "  << m_puzzle.GetWordHandler().GetPuzzle() << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD : "  << m_puzzle.GetBoard() << std::endl;
	std::cout.put('\n');
	*/
}

Puzzle Game::GetPuzzle()
{
	return m_puzzle;
}

void Game::PrintInfo(const User& u)
{
	std::cout << "CATEGORY : " << m_puzzle.GetWordHandler().GetCategory() << std::endl;
	std::cout.put('\n');

	std::cout << "PUZZLE : "  << m_puzzle.GetWordHandler().GetPuzzle() << std::endl;
	std::cout.put('\n');
	
	std::cout << "It is " << u.GetName() << "'s turn" << std::endl;
	std::cout.put('\n');
	std::cout << "BOARD : " << m_puzzle.GetBoard() << std::endl;
	std::cout.put('\n');
	std::this_thread::sleep_for(std::chrono::seconds(1));
	std::cout << "SCORE : $" << u.GetPuzzleAmount() << std:: endl;
	std::cout.put('\n');
	std::cout << "TOTAL : $" << u.GetTotalAmount() << std::endl;
	std::cout.put('\n');
	std::this_thread::sleep_for(std::chrono::seconds(1));
	m_puzzle.PrintLetters();
	std::cout.put('\n');
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void Game::Play(User *u)
{
	u->ChangeCanSpin(); //should make canSpin true
	char guess;
	while (!m_puzzle.GetIsSolved() && u->GetCanSpin())
	{
		PrintInfo(*u);
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
			WheelOutcome* a =  &(w.Spin());
		
			if (a->CanGuess())
			{
				double val = a->GetOutcomeValue();
				std::cout << "The wheel landed at $" << val << " dollars" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				std::string letter_guess;
				bool is_valid_letter_input = false;
				Puzzle::GuessOutcome guess_outcome = Puzzle::GuessOutcome::INVALID;
				do
				{
					is_valid_letter_input = false;
					std::cout << "Type in a character to guess : " << std::endl;
					std::cout << ">";
					
					getline(std::cin,option);
					if (option.length() == 1)
					{
						if (std::isalpha(option.at(0)))
						{
							char letterGuess = std::toupper(option.at(0));
							guess_outcome = m_puzzle.GuessLetter(letterGuess);
							is_valid_letter_input = true;
						}
						else
						{
							std::cout << "Please type in one letter" << std::endl;
							is_valid_letter_input = false;
						}
					}
					else
					{
						std::cout << "Please type in one letter" << std::endl;
						is_valid_letter_input = false;
					}
				} while (!is_valid_letter_input || guess_outcome == Puzzle::GuessOutcome::INVALID);

				switch (guess_outcome)
				{
					case Puzzle::GuessOutcome::CORRECT:
					case Puzzle::GuessOutcome::SOLVED:
						{
							double amount_earned = val * m_puzzle.GetNumOfLetters();
							std::cout << " You gain $" << amount_earned << " dollars" << std::endl;
							u->ChangePuzzleAmount(amount_earned);
						}
						break;
					case Puzzle::GuessOutcome::INCORRECT:
					default:
						std::cout << "Sorry, Your turn is over" << std::endl;
						u->ChangeCanSpin();
						break;
				}
			}
			else
			{
				std::cout << "You landed on bankrupt" << std::endl;
				std::cout << "Sorry, your turn is over and you lose all your money this round" << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1));
				u->SetZeroPuzzleAmount();
				u->ChangeCanSpin();
			}
		}
		else if (option == "s")
		{
			std::string puzzle_guess;
			std::cout << "What is your guess for the puzzle? : " << std::endl;
			std::cout << ">";
			getline(std::cin,puzzle_guess);
			m_puzzle.SolvePuzzle(puzzle_guess);
			if (!m_puzzle.GetIsSolved())
			{
				u->ChangeCanSpin();
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

	if (m_puzzle.GetIsSolved())
	{
		std::cout << u->GetName() << " has solved the puzzle and earned " << u->GetPuzzleAmount() << " dollars" << std::endl;
		u->ChangeTotalAmount(u->GetPuzzleAmount());
	}
}

//main with only 1 player
/*
int main()
{
	Game g;
	//User a("Gogol");
	User* a = new User("Gogol");
	if (!g.GetPuzzle().GetIsSolved())
	{
		//g.Play(&a);
		g.Play(a);
	}
	std::cout << "PUZZLE AMT : " <<  a->GetPuzzleAmount() << std::endl;
	std::cout << "TOTAL AMT : " << a->GetTotalAmount() << std::endl;

	return 0;
}
*/

int main()
{
	std::cout << "Welcome to Wheel of Fortune CLI Game!" << std::endl;
	std::this_thread::sleep_for(std::chrono::seconds(1));

	Game g;
	const int num_of_players = 3;
	std::array<User, num_of_players> user_order_list{{{"Gogol"}, {"Bapi"}, {"Gaton"}}};

	int current_player_index = 0;
	User* current_player = &user_order_list.at(current_player_index);
	current_player->ChangeHasTurn();

	while (!g.GetPuzzle().GetIsSolved())
	{
		current_player = &user_order_list.at(current_player_index);
		int next_player_index = (current_player_index + 1) % num_of_players;
		User* next_player = &user_order_list.at(next_player_index);
		if (current_player->GetHasTurn())
		{
			g.Play(current_player);
			next_player->ChangeHasTurn();
			current_player->ChangeHasTurn();
			current_player_index = next_player_index;
		}
	}

	return 0;
}
