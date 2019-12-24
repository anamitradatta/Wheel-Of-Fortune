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
#include <string.h>
#include "user.h"
using namespace std;

User :: User(string newName){
	canSpin=false;
	name = newName;
	puzzAmt = 0;
	totalAmt = 0;
	hasTurn = false;
}
string User :: getName(){

	return name;
}

double User :: getPuzzAmt(){
return puzzAmt;
}

double User :: getTotalAmt(){
return totalAmt;

}

bool User  :: getCanSpin(){
	return canSpin;

}

bool User :: getHasTurn(){
	return hasTurn;
}

void User :: changeCanSpin(){
	canSpin = !canSpin;
}

void User  :: setZeroPuzz(){

	puzzAmt = 0;
}
void User  :: setZeroTotal(){
totalAmt = 0;
}
void User :: changePuzzAmt(double change){

	puzzAmt = puzzAmt + change;

}
void User :: changeTotalAmt(double change){

	totalAmt = totalAmt + change;
}

void User :: changeHasTurn(){

	hasTurn = !hasTurn;
}
/*
int main(){
User n("Norman");
cout <<n.getName()<<endl;
cout <<n.getPuzzAmt()<<endl;
cout <<n.getTotalAmt()<<endl;
n.changePuzzAmt(100);
n.changeTotalAmt(n.getPuzzAmt());
cout <<n.getPuzzAmt()<<endl;
cout <<n.getTotalAmt()<<endl;
n.setZeroPuzz();
n.setZeroTotal();
cout <<n.getPuzzAmt()<<endl;
cout <<n.getTotalAmt()<<endl;










return 0;

}*/
