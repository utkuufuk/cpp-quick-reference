#ifndef PASSFAILACTIVITY_H
#define PASSFAILACTIVITY_H

#include "GradedActivity.h"

class PassFailActivity : public GradedActivity
{
    protected:
        double minPassingScore;

    public:
        PassFailActivity() : GradedActivity()
        {
            minPassingScore = 0.0; 
        }
    
        PassFailActivity(double mps) : GradedActivity()
        {
            minPassingScore = mps; 
        }
    
        void setMinPassingScore(double mps)
        {
            minPassingScore = mps; 
        }
    
        double getMinPassingScore() const
        {
            return minPassingScore; 
        }

        // 1. virtual keyword is optional because this function has already been declared as virtual in the parent class
        // 2. override keyword is also optional and it means that the function overrides a function in the parent class
        char getLetterGrade() const override;
};

char PassFailActivity::getLetterGrade() const
{
    if (score >= minPassingScore)
    {
        return 'P';
    }
    else
    {
        return 'F';
    }
}

#endif