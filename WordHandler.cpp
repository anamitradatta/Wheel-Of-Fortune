#include "WordHandler.h"
#include <iostream>
#include <fstream>

WordHandler::WordHandler()
{
	ReadWord();
}

void WordHandler::ReadWord()
{
	int num_of_lines = 0;
	int count = 0;
	std::ifstream in_file;
	srand(time(NULL));
	int rand_file = rand() % 3;
	std::string file_name;

	switch (rand_file)
	{
		case 0:
			file_name = "./puzzles/phrases.txt";
			m_category = "PHRASES";
			break;
		case 1:
			file_name = "./puzzles/classictv.txt";
			m_category = "CLASSIC TV";
			break;
		case 2:
			file_name = "./puzzles/movietitle.txt";
			m_category = "MOVIE TITLE";
			break;
		default:
			std::cout << "File not selected" << std::endl;
			exit(1);
	}

	in_file.open(file_name);
	if (in_file.fail())
	{
		std::cout << "The file " << file_name << " did not open properly" << std::endl;
		exit(1);
	}
	else
	{
		std::string s;
		while (getline(in_file,s))
		{
			++num_of_lines;
		}
		in_file.clear();
		in_file.seekg(0,std::ios::beg);
		srand(time(NULL));
		int random = rand() % num_of_lines+1;
		while (getline(in_file,s))
		{
			++count;
			if (count == random)
			{
				m_puzzle_string = s;
				break;
			}
		}
		in_file.close();
	}
}

std::string WordHandler::GetCategory()
{
	return m_category;
}

std::string WordHandler::GetPuzzleString()
{
	return m_puzzle_string;
}

/*
int main(){
	WordHandler w;
	std::cout << w.GetCategory() << std::endl;
	std::cout << w.GetPuzzleString() << std::endl;
	return 0;
}
*/
