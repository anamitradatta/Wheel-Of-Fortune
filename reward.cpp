#include "reward.h"
#include <iostream>

Reward::Reward(double rewVal)
{
	rewardVal = rewVal;
}

double Reward::getOutcomeVal()
{
	return rewardVal;
}

void Reward::printType()
{
	std::cout << "REWARD" << std::endl;
}

WheelOutcome::TypeOutcome Reward::getType()
{
	return TypeOutcome::REWARD;
}

bool Reward::canGuess()
{
	return true;
}



