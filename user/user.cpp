#include <iostream>
#include "user.h"


User::User()
{
	m_can_spin = false;
	m_name = "";
	m_puzzle_amount = 0;
	m_total_amount = 0;
	m_has_turn = false;
}

User::User(const std::string& name)
{
	m_can_spin = false;
	m_name = name;
	m_puzzle_amount = 0;
	m_total_amount = 0;
	m_has_turn = false;
}

std::ostream& operator<<(std::ostream& str, User const& u) 
{ 
	str << "Name = " << u.GetName()
	    << " puzzAmt=" << u.GetPuzzleAmount()
		<< " totalAmt=" << u.GetTotalAmount()
		<< " canSpin=" << u.GetCanSpin()
		<< " hasTurn=" << u.GetHasTurn()
		<< std::endl;
	return str;
}

std::string User::GetName() const
{
	return m_name;
}

double User::GetPuzzleAmount() const
{
	return m_puzzle_amount;
}

double User::GetTotalAmount() const
{
	return m_total_amount;
}

bool User::GetCanSpin() const
{
	return m_can_spin;
}

bool User::GetHasTurn() const
{
	return m_has_turn;
}

void User::SetName(const std::string& name)
{
	m_name = name;
}

void User::ChangeCanSpin()
{
	m_can_spin = !m_can_spin;
}

void User::SetCanSpin(bool can_spin)
{
	m_can_spin = can_spin;
}

void User::SetZeroPuzzleAmount()
{
	m_puzzle_amount = 0;
}

void User::SetZeroTotalAmount()
{
	m_total_amount = 0;
}

void User::ChangePuzzleAmount(double change)
{
	m_puzzle_amount += change;
}

void User::ChangeTotalAmount(double change)
{
	m_total_amount += change;
}

void User::ChangeHasTurn()
{
	m_has_turn = !m_has_turn;
}

void User::SetHasTurn(bool has_turn)
{
	m_has_turn = has_turn;
}

/*
int main()
{
	User n("Norman");
	std::cout << "name=" << n.GetName() << std::endl;
	std::cout << "puzzAmt=" << n.GetPuzzleAmount() << std::endl;
	std::cout << "totalAmt=" << n.GetTotalAmount() << std::endl;
	std::cout << "Adding 100 to User" << std::endl;
	n.ChangePuzzleAmount(100);
	n.ChangeTotalAmount(n.GetPuzzleAmount());
	std::cout << "puzzAmt=" << n.GetPuzzleAmount() << std::endl;
	std::cout << "totalAmt=" << n.GetTotalAmount() << std::endl;
	n.SetZeroPuzzleAmount();
	n.SetZeroTotalAmount();
	std::cout << "Setting 0 to User" << std::endl;
	std::cout << "puzzAmt=" << n.GetPuzzleAmount() << std::endl;
	std::cout << "totalAmt=" << n.GetTotalAmount() << std::endl;
	return 0;
}*/