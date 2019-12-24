#include <cstdio>
#include "outcome.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;

void wheelOutcome::printType(){

	cout << "wheeloutcome" << endl;
}
wheelOutcome:: typeOutcome wheelOutcome :: getType(){

	return typeOutcome::nothing;

}
double wheelOutcome :: getOutcomeVal(){
	return -1;

}
