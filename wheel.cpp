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
	
wheelOutcome& Wheel :: spin(){
	wheelOutcome* w;
	srand(time(NULL));
	int res = (rand()%4);
	switch(res){
	case 0:
	w = new Penalty();
	break;
	case 1:
	w = new Reward(100);
	break;
	case 2:
	w = new Reward(200);
	break;
	case 3:
	w = new Reward(300);
	

	}
	return *w;
}
/*wheelOutcome* Wheel :: spin(){
	wheelOutcome* w;
	srand(time(NULL));
	int res = (rand()%4);
	switch(res){
	case 0:
	w = new Penalty();
	break;
	case 1:
	w = new Reward(100);
	break;
	case 2:
	w = new Reward(200);
	break;
	case 3:
	w = new Reward(300);
	

	}
	return w;
}
*/ //can be done with *

/*

int main(){
	Wheel w;
	wheelOutcome* a =  &(w.spin());
	a->printType();
	cout << a->getOutcomeVal()<<endl;
	int num1 = 1;
	int* pnum = &num1;
	cout <<*pnum<<endl;
	cout <<pnum<<endl;
	cout <<*(&num1) <<endl;
	int num2 = 2;
	int &rnum = num2;
	cout <<rnum<<endl;
	cout <<&rnum<<endl;
	cout <<&num2<<endl;
	return 0;

}
*/
