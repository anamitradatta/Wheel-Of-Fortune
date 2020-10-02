#include "outcome.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;


#ifndef PENALTY_H
#define PENALTY_H



class Penalty: public wheelOutcome{

public:
double getOutcomeVal();
void printType();
typeOutcome getType();
bool canGuess();
};

#endif
