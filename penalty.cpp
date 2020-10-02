#include "outcome.h"
#include "penalty.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;


double Penalty :: getOutcomeVal(){

	return 0;

}



void Penalty:: printType(){
	cout << "penalty" <<endl;


}



wheelOutcome :: typeOutcome Penalty :: getType(){

	return typeOutcome::penalty;

}

bool Penalty :: canGuess(){

	return false;
}




