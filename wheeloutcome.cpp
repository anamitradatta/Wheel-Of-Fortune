#include "wheeloutcome.h"
#include <iostream>

void WheelOutcome::printType()
{
	std::cout << "NOTHING" << std::endl;
}

WheelOutcome::TypeOutcome WheelOutcome::getType()
{
	return TypeOutcome::NOTHING;
}

double WheelOutcome::getOutcomeVal()
{
	return -1;
}
