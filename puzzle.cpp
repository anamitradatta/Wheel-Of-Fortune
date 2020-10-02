#include "WordHandler.h"
#include "puzzle.h"
#include <regex>
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <chrono>
#include <thread>
#include <algorithm>

using namespace std;
Puzzle::Puzzle(){
	isSolved = false;
	isDup = false;	
	isRight = false;
	numofletters = 0;
	letters = new char[27]; 
letters[0] = 'A';
letters[1] = 'B';
letters[2] = 'C';
letters[3] = 'D';
letters[4] = 'E';
letters[5] = 'F';
letters[6] = 'G';
letters[7] = 'H';
letters[8] = 'I';
letters[9] = 'J';
letters[10] = 'K';
letters[11] = 'L';
letters[12] = 'M';
letters[13] = 'N';
letters[14] = 'O';
letters[15] = 'P';
letters[16] = 'Q';
letters[17] = 'R';
letters[18] = 'S';
letters[19] = 'T';
letters[20] = 'U';
letters[21] = 'V';
letters[22] = 'W';
letters[23] = 'X';
letters[24] = 'Y';
letters[25] = 'Z';
letters[26] = '\0';
	puzzleString = new char[g.getPuzzle().length()];
	boardString = new char[g.getPuzzle().length()];
	strcpy(puzzleString,g.getPuzzle().c_str());
	strcpy(boardString,getBlankPuzzle());
//	printPuzzInfo();
}
void Puzzle :: printPuzzInfo(){
	cout << "CATEGORY : " << g.getCategory() << endl;
	cout.put('\n');
	cout<<"PUZZLE : " << puzzleString << endl;
	cout.put('\n');
	cout << "BOARD: " << boardString << endl;
	this_thread::sleep_for(1s);
	cout.put('\n');
	printLetters();
}
WordHandler Puzzle::getWordHandler(){
	return g;
}

char* Puzzle :: getBlankPuzzle(){
	char* blankPuzzle = new char[g.getPuzzle().length()];
	int i;
	int j;
	for(i=0;i<g.getPuzzle().length();i++){
		if(g.getPuzzle().at(i)!=' '){ 
			if(i!=g.getPuzzle().length()-1){
				blankPuzzle[i] = '-';
			}
			else{
				blankPuzzle[i] = '-';	
				blankPuzzle[i+1] = '\0';
			}
		}
		else{
			if(i!=g.getPuzzle().length()-1){
				blankPuzzle[i] = ' ';
			}
			else{
				blankPuzzle[i] = ' ';	
				blankPuzzle[i+1] = '\0';
			}
		}
	}
	return blankPuzzle;
}

char* Puzzle :: getBoard(){
	return boardString;
}

int Puzzle :: getNumOfLetters(){
	return numofletters;
}

bool Puzzle :: getIsSolved(){
	return isSolved;
}

bool Puzzle :: getIsRight(){
	return isRight;
}

bool Puzzle :: getIsDup(){
	return isDup;
}

void Puzzle :: printLetters(){
	cout << "Available letters : "  <<endl;
	for(int i =0;i<strlen(letters);i++){
		if(letters[i]!=' '){
			cout << letters[i] << " ";
		}
		else{
			cout << "- ";
		}
	}
	cout.put('\n');
}

void Puzzle :: removeLetter(char l){
	for(int i=0;i<strlen(letters);i++){
		if(letters[i]==l){
			letters[i] =' ';
		}
	}
}

void Puzzle :: shiftLetter(char l){
	bool charFound = false;
	int s = strlen(letters);
	for(int i=0;i<s;i++){
		if(letters[i]==l){
			charFound = true;
		}
		if(charFound){ letters[i] = letters[i+1];}
	}
	if(charFound==true){
		letters[s-1]='\0';
	}
}

bool Puzzle :: isInLetters(char charGuess){
	bool exists = false;
	for(int i=0;i<strlen(letters);i++){
		if(letters[i] == charGuess){ exists = true; }
	}
	return exists;
}

void Puzzle :: guessLetter(char charGuess){
	if(!isInLetters(charGuess)){
		this_thread::sleep_for(1s);
		isDup = true;	
		cout << "You already guessed that letter. Try again. " << endl;
		cout.put('\n');
		this_thread::sleep_for(1s);
		//printPuzzInfo();
		//this_thread::sleep_for(1s);
		return;
	}
	isRight = false;
	removeLetter(charGuess);
	int i;
	numofletters=0;
	for(i=0;i<strlen(puzzleString);i++){
		if(puzzleString[i]==charGuess){
			isRight	= true;
			isDup =false;
			numofletters++;
			boardString[i] = charGuess;
		}
	}
	if(strcmp(boardString,puzzleString)==0){
		isSolved = true;
 		cout << "You have solved the puzzle : " << g.getPuzzle() << endl;
	}
	else{
		if(numofletters==0){
			isDup = false;
			this_thread::sleep_for(1s);
			cout << "Sorry, no " << charGuess << "'s" <<endl;
			cout.put('\n');
			this_thread::sleep_for(1s);
		//	printPuzzInfo();
		//	this_thread::sleep_for(1s);
		}
		else{
			this_thread::sleep_for(1s);
			cout << "There are " << numofletters << " " << charGuess << "'s" <<endl;
			cout.put('\n');
			this_thread::sleep_for(1s);
		//	printPuzzInfo();
		//	this_thread::sleep_for(1s);

		}
	}
}

void Puzzle :: solvePuzzle(string puzzGuess){
	puzzGuess = regex_replace(puzzGuess, regex("^ +| +$|( ) +"), "$1");
	transform(puzzGuess.begin(), puzzGuess.end(), puzzGuess.begin(), ::toupper);
	cout.put('\n');
	if(puzzGuess == g.getPuzzle()){
		strcpy(boardString,puzzleString);
		isSolved = true;
		cout << "You have solved the puzzle : " << boardString << endl;
		cout.put('\n');
	}
	else{
		this_thread::sleep_for(1s);
		cout << "No that is not correct" << endl;
		cout.put('\n');
		this_thread::sleep_for(1s);
		//printPuzzInfo();
		//this_thread::sleep_for(1s);
	}

}
/*
int main(){
Puzzle p;
char guess;
while(!p.getIsSolved()){
	p.printPuzzInfo();
	cout.put('\n');
	cout << "What would you like to do? Either type a letter to guess or type \"solve\" to solve the puzzle or type \"exit\" to exit the game" << endl;
	cout.put('\n');
	cout << ">";
	string option;
	getline(cin,option);
		if(option!="solve"&&option!="exit"&&option.length()==1&&isupper(option.at(0))){
			char guess = option.at(0);
			p.guessLetter(guess);
		}
		else if(option!="solve"&&option!="exit"&&option.length()==1&&islower(option.at(0))){

			char guess = toupper(option.at(0));
			p.guessLetter(guess);

		}
		else if(option=="solve"){
			cout << "What is your guess for the puzzle? " << endl;
			cout << ">";
			string puzzleGuess;
			getline(cin,puzzleGuess);
			p.solvePuzzle(puzzleGuess);
		}
		else if(option=="exit"){
			if(option=="exit"){
				cout << "You have exited the game" << endl;
				exit(0);
			}
		}
		else{
			cout << "That is not a valid option " << endl;
			this_thread::sleep_for(1s);
			p.printPuzzInfo();
			this_thread::sleep_for(1s);

		}

}

return 0;
}*/
