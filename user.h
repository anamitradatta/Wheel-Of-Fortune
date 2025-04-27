#include <string>

#ifndef USER_H
#define USER_H

class User
{
    public:
        User();
        User(const std::string& name);
        void toString();
        std::string getName() const;
        double getPuzzAmt() const ;
        double getTotalAmt() const;
        bool getCanSpin() const;
        bool getHasTurn() const;
        void setName(const std::string& name);
        void changeCanSpin();
        void setCanSpin(bool canSpin);
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
std::ostream& operator<<(std::ostream& str, const User& u);
#endif
