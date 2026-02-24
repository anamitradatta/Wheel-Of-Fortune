#include "wheeloutcome.h"

#ifndef REWARD_H
#define REWARD_H

class Reward : public WheelOutcome
{
    public:
        Reward(double reward_value);
        double GetOutcomeValue() override;
        void PrintType() override;
        TypeOutcome GetType() override;
        bool CanGuess() override;
    private:
        double m_reward_value;
};
#endif

