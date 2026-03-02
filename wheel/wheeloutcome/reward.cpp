#include "reward.h"
#include <iostream>

Reward::Reward(double reward_value)
{
	m_reward_value = reward_value;
}

double Reward::GetOutcomeValue()
{
	return m_reward_value;
}

void Reward::PrintType()
{
	std::cout << "REWARD" << std::endl;
}

WheelOutcome::TypeOutcome Reward::GetType()
{
	return TypeOutcome::REWARD;
}

bool Reward::CanGuess()
{
	return true;
}



