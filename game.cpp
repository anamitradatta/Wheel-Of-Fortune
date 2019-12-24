#include "WordHandler.h"
#include "puzzle.h"
#include "wheel.h"
#include "reward.h"
#include "penalty.h"
#include "outcome.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <thread>
#include <chrono>
#include "user.h"
#include "game.h"
using namespace std;
	
Game :: Game(){
/*	cout << "CATEGORY : " << p.getWordHandler().getCategory() << endl;
	cout.put('\n');
	cout << "PUZZLE : "  << p.getWordHandler().getPuzzle() << endl;
	cout.put('\n');
	cout << "BOARD : "  << p.getBoard() << endl;
	cout.put('\n');*/
}

Puzzle Game :: getPuzzle(){


	return p;

}
void Game :: printInfo(User u){
	cout << "CATEGORY : " << p.getWordHandler().getCategory() << endl;
	cout.put('\n');

	cout << "PUZZLE : "  << p.getWordHandler().getPuzzle() << endl;
	cout.put('\n');
	
	cout << "It is " << u.getName() << "'s turn" << endl;
	cout.put('\n');
	cout << "BOARD : " << p.getBoard() << endl;
	cout.put('\n');
	this_thread::sleep_for(1s);
	cout << "SCORE : $" << u.getPuzzAmt() << endl;
	cout.put('\n');
	cout << "TOTAL : $" << u.getTotalAmt() <<endl;
	cout.put('\n');
	this_thread::sleep_for(1s);
	p.printLetters();
	cout.put('\n');
	this_thread::sleep_for(1s);
	

}

void Game :: play(User *u){

u->changeCanSpin(); //should make canSpin true
char guess;
while(!p.getIsSolved()&&u->getCanSpin()){
	printInfo(*u);
	cout << "What would you like to do? " <<endl;
	cout<< "Either type \"w\" to spin the wheel and guess a letter or type \"s\" to solve the puzzle or type \"e\" to exit the game" << endl;
	cout.put('\n');
	cout << ">";
	string option;
	getline(cin,option);
		if(option=="w"){
			
		Wheel w;
		wheelOutcome* a =  &(w.spin());
		
		if(a->canGuess()){
			double val = a->getOutcomeVal();
			cout << "The wheel landed at $" << val << endl;
			//char letterGuess;
			string letterGuess;
			bool isOneL = false;
			bool isLetter = false;
				do{
					
					cout << "Type in a character to guess : " << endl;
					cout << ">";
					getline(cin,option);
					if(option.length()==1){
						if(isalpha(option.at(0))){
							char letterGuess = toupper(option.at(0));
							//scanf(" %1c",&letterGuess);
							//char propGuess = toupper(letterGuess);
							p.guessLetter(letterGuess);
							isOneL = true;
							isLetter = true;
						}
						else{
							cout << "Please type in one letter" << endl;
						}

					}
					else{	
						cout << "Please type in one letter" << endl;

					}
				}while(p.getIsDup()&&!isOneL&&!isLetter);

			if(p.getIsRight()){
				cout << "You gain $" <<val*p.getNumOfLetters() << " dollars" <<endl;
				u->changePuzzAmt(val*p.getNumOfLetters());
			}
			else{
				cout <<"Your turn is over"<< endl;
				u->changeCanSpin();	
			}
	
		}else{

		cout << "You landed on bankrupt" <<endl;
		cout << "Sorry, your turn is over and you lose all your money this round" << endl;
		u->setZeroPuzz();
		u->changeCanSpin();
		}

		}
		else if(option=="s"){
			string puzzleGuess;
			cout << "What is your guess for the puzzle? : " <<endl;
			cout << ">";
			getline(cin,puzzleGuess);
			p.solvePuzzle(puzzleGuess);
		}
		else if(option=="e"){
			cout << "You have exited the game" << endl;
			exit(0);
		}
		else{
			cout << "That is not a valid option" << endl;
			cout.put('\n');
			this_thread::sleep_for(1s);
/*			cout << "CATEGORY : " << p.getWordHandler().getCategory() << endl;
			cout.put('\n');
			cout << "BOARD : " << p.getBoard() << endl;
			cout.put('\n');
			this_thread::sleep_for(1s);
*/
		}
			
	}		
	if(p.getIsSolved()){
		u->changeTotalAmt(u->getPuzzAmt());
	}


}

//main with only 1 player
/*
int main(){

Game g;
//User a("Gogol");
User* a = new User("Gogol");
if(!g.getPuzzle().getIsSolved()){
//g.play(&a);
g.play(a);
}
cout << "PUZZLE AMT : " <<  a->getPuzzAmt() << endl;
cout << "TOTAL AMT : " << a->getTotalAmt() << endl;

return 0;


}
*/

int main(){
Game g;
User* a = new User("Gogol");
User* b = new User("Bapi");
User* c = new User("Gaton");

a->changeHasTurn();

while(!g.getPuzzle().getIsSolved()){
	if(a->getHasTurn()){
		g.play(a);
		b->changeHasTurn();
		a->changeHasTurn();
	}
	if(b->getHasTurn()){
		g.play(b);
		c->changeHasTurn();
		b->changeHasTurn();
	}
	if(c->getHasTurn()){
		g.play(c);
		a->changeHasTurn();
		c->changeHasTurn();
	}
}
return 0;

}

