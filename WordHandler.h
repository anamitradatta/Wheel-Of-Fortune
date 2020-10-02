#include <string>

#ifndef WORDHANDLER_H
#define WORDHANDLER_H

using namespace std;

class WordHandler{
	private:
	string category;
	string puzzle;
	void readWord();
	public:
	WordHandler();
	string getCategory();	
	string getPuzzle();
};
#endif
