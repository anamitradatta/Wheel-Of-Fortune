#include <iostream>
#include "user.h"


User::User()
{
	m_canSpin = false;
	m_name = "";
	m_puzzAmt = 0;
	m_totalAmt = 0;
	m_hasTurn = false;
}

User::User(const std::string& name)
{
	m_canSpin = false;
	m_name = name;
	m_puzzAmt = 0;
	m_totalAmt = 0;
	m_hasTurn = false;
}

std::ostream& operator<<(std::ostream& str, User const& u) 
{ 
	str << "Name = " << u.getName()
	    << " puzzAmt=" << u.getPuzzAmt()
		<< " totalAmt=" << u.getTotalAmt()
		<< " canSpin=" << u.getCanSpin()
		<< " hasTurn=" << u.getHasTurn()
		<< std::endl;
	return str;
}

std::string User::getName() const
{
	return m_name;
}

double User::getPuzzAmt() const
{
	return m_puzzAmt;
}

double User::getTotalAmt() const
{
	return m_totalAmt;
}

bool User::getCanSpin() const
{
	return m_canSpin;
}

bool User::getHasTurn() const
{
	return m_hasTurn;
}

void User::setName(const std::string& name)
{
	m_name = name;
}

void User::changeCanSpin()
{
	m_canSpin = !m_canSpin;
}

void User::setCanSpin(bool canSpin)
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