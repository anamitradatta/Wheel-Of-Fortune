#include "wheel.h"
#include "reward.h"
#include "penalty.h"
#include <iostream>
	
std::unique_ptr<WheelOutcome> Wheel::spin()
{
	srand(time(NULL));
	int res = (rand() % 4);
	std::unique_ptr<WheelOutcome> w;
	switch(res)
	{
		case 0:
			w = std::make_unique<Penalty>();
			break;
		case 1:
			w = std::make_unique<Reward>(100);
			break;
		case 2:
			w = std::make_unique<Reward>(200);
			break;
		case 3:
			w = std::make_unique<Reward>(300);
			break;
		default:
			w = std::make_unique<Reward>(0);
			break;
	}
	return w;
}

/*
WheelOutcome* Wheel::spin()
{
	WheelOutcome* w;
	srand(time(NULL));
	int res = (rand() % 4);
	switch(res)
	{
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
			break;
		default:
		    w = new Reward(0);
			break;
	}
	return w;
}*/
//can be done with 

/*
int main()
{
	Wheel w;
	// use unique_ptr returned by spin
	// auto a = w.spin();
	// a->printType();
	// std::cout << a->getOutcomeVal() << std::endl;
	
	//int num1 = 1;
	//int* pnum = &num1;
	//std::cout << *pnum << std::endl;
	//std::cout << pnum << std::endl;
	//std::cout << *(&num1) << std::endl;
	//int num2 = 2;
	//int &rnum = num2;
	//std::cout << rnum << std::endl;
	//std::cout << &rnum << std::endl;
	//std::cout << &num2 << std::endl;
	
	return 0;
}*/
