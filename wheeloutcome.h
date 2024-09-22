#ifndef WHEELOUTCOME_H
#define WHEELOUTCOME_H			

class WheelOutcome
{
public:
    enum TypeOutcome 
    {
        NOTHING,
        REWARD,
        PENALTY
    };

    virtual void printType() = 0;
    virtual TypeOutcome getType() = 0;
    virtual double getOutcomeVal() = 0;
    virtual bool canGuess() = 0;
};

#endif

