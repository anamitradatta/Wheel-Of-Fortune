#include "wheeloutcome.h"
#include <memory>

#ifndef WHEEL_H
#define WHEEL_H

class Wheel
{
	public:
		std::unique_ptr<WheelOutcome> spin();
};
#endif	
