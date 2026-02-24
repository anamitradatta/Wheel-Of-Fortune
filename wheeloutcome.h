#ifndef WHEELOUTCOME_H
#define WHEELOUTCOME_H			

class WheelOutcome
{
public:
    enum class TypeOutcome
    {
        NOTHING,
        REWARD,
        PENALTY
    };

    virtual void PrintType() = 0;
    virtual TypeOutcome GetType() = 0;
    virtual double GetOutcomeValue() = 0;
    virtual bool CanGuess() = 0;
};

#endif

