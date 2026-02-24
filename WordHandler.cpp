#include "WordHandler.h"
#include <iostream>
#include <fstream>

WordHandler::WordHandler()
{
	ReadWord();
}

void WordHandler::ReadWord()
{
	int numoflines = 0;
	int count = 0;
	std::ifstream infile;
	srand(time(NULL));
	int randfile = rand() % 3;

	switch (randfile)
	{
		case 0:
			infile.open("./puzzles/phrases.txt");
			m_category = "PHRASES";
			break;
		case 1:
			infile.open("./puzzles/classictv.txt");
			m_category = "CLASSIC TV";
			break;
		case 2:
			infile.open("./puzzles/movietitle.txt");
			m_category = "MOVIE TITLE";
			break;
		default:
			std::cout << "File not selected" << std::endl;
			exit(1);
	}

	if (infile.fail())
	{
		std::cout << "Your file did not work" << std::endl;
		exit(1);
	}
	else
	{
		std::string s;
		while (getline(infile,s))
		{
			++numoflines;
		}
		infile.clear();
		infile.seekg(0,std::ios::beg);
		srand(time(NULL));
		int random = rand() % numoflines+1;
		while (getline(infile,s))
		{
			++count;
			if (count == random)
			{
				m_puzzle = s;
			}
		}
		infile.close();
	}
}

std::string WordHandler::GetCategory()
{
	return m_category;
}

std::string WordHandler::GetPuzzle()
{
	return m_puzzle;
}

/*
int main(){
	WordHandler w;
	std::cout << w.GetCategory() << std::endl;
	std::cout << w.GetPuzzle() << std::endl;
	return 0;
}
*/
