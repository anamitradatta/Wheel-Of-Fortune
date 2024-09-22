#include "wheeloutcome.h"

#ifndef PENALTY_H
#define PENALTY_H

class Penalty : public WheelOutcome
{
    public:
        double getOutcomeVal() override;
        void printType() override;
        TypeOutcome getType() override;
        bool canGuess() override;
};
#endif
