#include "penalty.h"
#include <iostream>

double Penalty::getOutcomeVal()
{
	return 0;
}

void Penalty::printType()
{
	std::cout << "PENALTY" << std::endl;
}

WheelOutcome::TypeOutcome Penalty::getType()
{
	return TypeOutcome::PENALTY;
}

bool Penalty::canGuess()
{
	return false;
}




