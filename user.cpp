#include <iostream>
#include "user.h"

User::User(std::string newName)
{
	canSpin = false;
	name = newName;
	puzzAmt = 0;
	totalAmt = 0;
	hasTurn = false;
}

std::string User::getName()
{
	return name;
}

double User::getPuzzAmt()
{
	return puzzAmt;
}

double User::getTotalAmt()
{
	return totalAmt;
}

bool User::getCanSpin()
{
	return canSpin;
}

bool User::getHasTurn()
{
	return hasTurn;
}

void User::changeCanSpin()
{
	canSpin = !canSpin;
}

void User ::setZeroPuzz()
{
	puzzAmt = 0;
}

void User::setZeroTotal()
{
	totalAmt = 0;
}

void User::changePuzzAmt(double change)
{
	puzzAmt = puzzAmt + change;
}

void User::changeTotalAmt(double change)
{
	totalAmt = totalAmt + change;
}

void User::changeHasTurn()
{
	hasTurn = !hasTurn;
}

/*
int main()
{
	User n("Norman");
	std::cout << "name=" << n.getName() << std::endl;
	std::cout << "puzzAmt=" << n.getPuzzAmt() << std::endl;
	std::cout << "totalAmt=" << n.getTotalAmt() << std::endl;
	std::cout << "Adding 100 to User" << std::endl;
	n.changePuzzAmt(100);
	n.changeTotalAmt(n.getPuzzAmt());
	std::cout << "puzzAmt=" << n.getPuzzAmt() << std::endl;
	std::cout << "totalAmt=" << n.getTotalAmt() << std::endl;
	n.setZeroPuzz();
	n.setZeroTotal();
	std::cout << "Setting 0 to User" << std::endl;
	std::cout << "puzzAmt=" << n.getPuzzAmt() << std::endl;
	std::cout << "totalAmt=" << n.getTotalAmt() << std::endl;
	return 0;
}*/