#include <string>

#ifndef WORDHANDLER_H
#define WORDHANDLER_H

class WordHandler
{
	public:
		WordHandler();
		std::string GetCategory();
		std::string GetPuzzle();

	private:
		std::string m_category;
		std::string m_puzzle;
		void ReadWord();
};
#endif
