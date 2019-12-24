#include "WordHandler.h"
#include "puzzle.h"
#include "outcome.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
using namespace std;

#ifndef WHEEL_H
#define WHEEL_H

class Wheel{
	public:
		enum spinResult {bankrupt=0,one_hundred=100,two_hundred=200,three_hundred=300};
		spinResult vals[4] = {spinResult::one_hundred,spinResult::two_hundred,spinResult::three_hundred,spinResult::bankrupt};





		wheelOutcome& spin();






};
#endif	
