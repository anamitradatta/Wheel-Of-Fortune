#include <string>

#ifndef WORDHANDLER_H
#define WORDHANDLER_H

class WordHandler
{
	public:
		WordHandler();
		std::string getCategory() const;	
		std::string getPuzzle() const;

	private:
		std::string m_category;
		std::string m_puzzle;
		void readWord();
};
#endif
