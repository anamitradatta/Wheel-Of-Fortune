#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;

#ifndef OUTCOME_H
#define OUTCOME_H			


class wheelOutcome{

public:
enum typeOutcome {nothing,reward,penalty};
virtual void printType()=0;
virtual typeOutcome getType()=0;
virtual double getOutcomeVal()=0;
virtual bool canGuess()=0;



};

#endif

