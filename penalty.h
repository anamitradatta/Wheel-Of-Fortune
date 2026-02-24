#include "wheeloutcome.h"

#ifndef PENALTY_H
#define PENALTY_H

class Penalty : public WheelOutcome
{
    public:
        double GetOutcomeValue() override;
        void PrintType() override;
        TypeOutcome GetType() override;
        bool CanGuess() override;
};
#endif
