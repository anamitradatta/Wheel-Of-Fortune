#include "WordHandler.h"
#include <cstdio>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;
	void WordHandler :: readWord(){
		int numoflines =0;
		int count=0;
		ifstream infile;
		srand(time(NULL));
		int randfile = rand() % 3;
		switch (randfile){
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
				cout<<"File not selected"<<endl;
				exit(1);
		}
		if(infile.fail()){
			cout<<"Your file did not work"<<endl;
			exit(1);
		}
		else{
			string s;
			while(getline(infile,s)){
				++numoflines;
			}
			//cout << numoflines << endl;
			infile.clear();
			infile.seekg(0,ios::beg);
			srand(time(NULL));
			int random = rand() % numoflines+1;
			while(getline(infile,s)){
				++count;
				if(count==random){
					puzzle = s;
				}

			}
			infile.close();
		}
	}

	string WordHandler :: getCategory(){
		return category;
	}
	string WordHandler :: getPuzzle(){
		return puzzle;
	}
	WordHandler :: WordHandler(){
		readWord();
	}
/*
int main(){
WordHandler w;
cout<<w.getCategory()<<endl;
cout<<w.getPuzzle()<<endl;
return 0;
}
*/
