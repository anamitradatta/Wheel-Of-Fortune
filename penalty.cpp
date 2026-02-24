#include "penalty.h"
#include <iostream>

double Penalty::GetOutcomeValue()
{
	return 0;
}

void Penalty::PrintType()
{
	std::cout << "PENALTY" << std::endl;
}

WheelOutcome::TypeOutcome Penalty::GetType()
{
	return TypeOutcome::PENALTY;
}

bool Penalty::CanGuess()
{
	return false;
}




