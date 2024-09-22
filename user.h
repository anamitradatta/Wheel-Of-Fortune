#include <string>

#ifndef USER_H
#define USER_H

class User
{
    public:
        User(std::string newName);
        std::string getName();
        double getPuzzAmt();
        double getTotalAmt();
        bool getCanSpin();
        bool getHasTurn();
        void changeCanSpin();
        void setZeroPuzz();
        void setZeroTotal();
        void changePuzzAmt(double change);
        void changeTotalAmt(double change);
        void changeHasTurn();
    private:
        std::string name;
        double puzzAmt;
        double totalAmt;
        bool canSpin;
        bool hasTurn;
};
#endif
