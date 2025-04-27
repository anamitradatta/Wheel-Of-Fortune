#include <iostream>
#include "user.h"

User::User(std::string newName)
{
	m_canSpin = false;
	m_name = newName;
	m_puzzAmt = 0;
	m_totalAmt = 0;
	m_hasTurn = false;
}

std::string User::getName()
{
	return m_name;
}

double User::getPuzzAmt()
{
	return m_puzzAmt;
}

double User::getTotalAmt()
{
	return m_totalAmt;
}

bool User::getCanSpin()
{
	return m_canSpin;
}

bool User::getHasTurn()
{
	return m_hasTurn;
}

void User::changeCanSpin()
{
	m_canSpin = !m_canSpin;
}

void User::setCanSpan(bool canSpin)
{
	m_canSpin = canSpin;
}

void User::setZeroPuzz()
{
	m_puzzAmt = 0;
}

void User::setZeroTotal()
{
	m_totalAmt = 0;
}

void User::changePuzzAmt(double change)
{
	m_puzzAmt = m_puzzAmt + change;
}

void User::changeTotalAmt(double change)
{
	m_totalAmt = m_totalAmt + change;
}

void User::changeHasTurn()
{
	m_hasTurn = !m_hasTurn;
}

void User::setHasTurn(bool hasTurn)
{
	m_hasTurn = hasTurn;
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