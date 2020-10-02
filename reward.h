
#include "outcome.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;


#ifndef REWARD_H
#define REWARD_H

class Reward: public wheelOutcome{
private:
double rewardVal;
public:
Reward(double rewVal);
double getOutcomeVal();
void printType();
typeOutcome getType();
bool canGuess();


};
#endif

