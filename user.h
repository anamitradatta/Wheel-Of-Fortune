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
        void setCanSpan(bool canSpin);
        void setZeroPuzz();
        void setZeroTotal();
        void changePuzzAmt(double change);
        void changeTotalAmt(double change);
        void changeHasTurn();
        void setHasTurn(bool hasTurn);
    private:
        std::string m_name;
        double m_puzzAmt;
        double m_totalAmt;
        bool m_canSpin;
        bool m_hasTurn;
};
#endif
