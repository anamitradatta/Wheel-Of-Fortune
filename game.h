#include "puzzle.h"
#include "user.h"

#ifndef GAME_H
#define GAME_H
class Game
{
    public:
        Game();
        Puzzle getPuzzle();
        void printInfo(User u);
        void play(User *u);

    private:
        Puzzle m_puzzle;
};
#endif
