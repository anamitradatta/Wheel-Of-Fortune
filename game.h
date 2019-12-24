#include "WordHandler.h"
#include "puzzle.h"
#include "wheel.h"
#include "reward.h"
#include "penalty.h"
#include "outcome.h"
#include <cstdio>
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include "user.h"
using namespace std;
#ifndef GAME_H
#define GAME_H
	


class Game{
private:
Puzzle p;

public:
Game();
Puzzle getPuzzle();
void printInfo(User u);
void play(User *u);


};
#endif
