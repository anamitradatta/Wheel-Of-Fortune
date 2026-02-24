#include "wheeloutcome.h"
#include <iostream>

void WheelOutcome::PrintType()
{
	std::cout << "NOTHING" << std::endl;
}

WheelOutcome::TypeOutcome WheelOutcome::GetType()
{
	return TypeOutcome::NOTHING;
}

double WheelOutcome::GetOutcomeValue()
{
	return -1;
}
