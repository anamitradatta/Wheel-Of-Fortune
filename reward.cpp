#include "reward.h"
#include "outcome.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;


Reward :: Reward(double rewVal){

	rewardVal = rewVal;
}

double Reward :: getOutcomeVal(){

	return rewardVal;
}



void Reward :: printType(){
	cout << "reward" <<endl;


}

wheelOutcome :: typeOutcome Reward :: getType(){

	return typeOutcome::reward;

}

bool Reward :: canGuess(){

	return true;

}



