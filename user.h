#include <string>

#ifndef USER_H
#define USER_H

class User
{
    public:
        User();
        User(const std::string& name);
        std::string GetName() const;
        double GetPuzzleAmount() const ;
        double GetTotalAmount() const;
        bool GetCanSpin() const;
        bool GetHasTurn() const;
        void SetName(const std::string& name);
        void ChangeCanSpin();
        void SetCanSpin(bool can_spin);
        void SetZeroPuzzleAmount();
        void SetZeroTotalAmount();
        void ChangePuzzleAmount(double change);
        void ChangeTotalAmount(double change);
        void ChangeHasTurn();
        void SetHasTurn(bool has_turn);
    private:
        std::string m_name;
        double m_puzzle_amount;
        double m_total_amount;
        bool m_can_spin;
        bool m_has_turn;
};
std::ostream& operator<<(std::ostream& str, const User& u);
#endif
