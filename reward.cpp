#include "reward.h"
#include <iostream>

Reward::Reward(double rewVal)
{
	m_rewardVal = rewVal;
}

double Reward::getOutcomeVal()
{
	return m_rewardVal;
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



