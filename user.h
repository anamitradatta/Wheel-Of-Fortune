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
using namespace std;
#ifndef USER_H
#define USER_H

class User{

private:
string name;
double puzzAmt;
double totalAmt;
bool canSpin;
bool hasTurn;

public:
User(string newName);
string getName();
double getPuzzAmt();
double getTotalAmt();
bool getCanSpin();
bool getHasTurn();
void changeCanSpin();
void setZeroPuzz();
void setZeroTotal();
void changePuzzAmt(double change);
void changeTotalAmt(double change);
void changeHasTurn();

};
#endif
