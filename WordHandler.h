#include <string>

#ifndef WORDHANDLER_H
#define WORDHANDLER_H

class WordHandler
{
	public:
		WordHandler();
		std::string getCategory();	
		std::string getPuzzle();

	private:
		std::string m_category;
		std::string m_puzzle;
		void readWord();
};
#endif
