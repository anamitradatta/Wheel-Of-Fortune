#include "wheeloutcome.h"

#ifndef REWARD_H
#define REWARD_H

class Reward : public WheelOutcome
{
    public:
        Reward(double rewVal);
        double getOutcomeVal() override;
        void printType() override;
        TypeOutcome getType() override;
        bool canGuess() override;
    private:
        double rewardVal;
};
#endif

