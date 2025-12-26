#include "puzzle.h"
#include "user.h"

#ifndef GAME_H
#define GAME_H
class Game
{
    public:
        Game();
        Puzzle getPuzzle();
        void printInfo(const User& u);
        void play(User *u);
        static bool isInteger(const std::string& str);

    private:
        Puzzle m_puzzle;
};
#endif
