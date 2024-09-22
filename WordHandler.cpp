#include "WordHandler.h"
#include <iostream>
#include <fstream>

WordHandler::WordHandler()
{
	readWord();
}

void WordHandler::readWord()
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
			category = "PHRASES";
			break;
		case 1:
			infile.open("./puzzles/classictv.txt");
			category = "CLASSIC TV";
			break;
		case 2:
			infile.open("./puzzles/movietitle.txt");
			category = "MOVIE TITLE";
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
			if (count==random)
			{
				puzzle = s;
			}
		}
		infile.close();
	}
}

std::string WordHandler::getCategory()
{
	return category;
}

std::string WordHandler::getPuzzle()
{
	return puzzle;
}

/*
int main(){
	WordHandler w;
	std::cout << w.getCategory() << std::endl;
	std::cout << w.getPuzzle() << std::endl;
	return 0;
}
*/
