#include "puzzle.h"
#include "user.h"

#ifndef GAME_H
#define GAME_H
class Game
{
    public:
        Game();
        Puzzle GetPuzzle();
        void PrintInfo(const User& u);
        void Play(User *u);

    private:
        Puzzle m_puzzle;
};
#endif
