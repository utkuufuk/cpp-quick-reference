#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
    protected:
        double score;

    public:
        GradedActivity()
        {   
            score = 0.0; 
        }
       
        GradedActivity(double s)
        { 
            score = s; 
        }
       
        // final keyword ensures that the function does not get overridden in a child class
        virtual void setScore(double s) final
        {
            score = s; 
        }
       
        double getScore() const
        {
            return score; 
        }
        
        // virtual functions may be overriden by the child class. 
        // they also make any function that overrides it virtual.
        virtual char getLetterGrade() const;

        // virtual destructor allows the child class destructor to execute
        virtual ~GradedActivity()
        {
            // clean up     
        }
};

char GradedActivity::getLetterGrade() const
{
    char letterGrade;

    if (score > 89)
    {
        letterGrade = 'A';
    }
    else if (score > 79)
    {
        letterGrade = 'B';
    }
    else if (score > 69)
    {
        letterGrade = 'C';
    }
    else if (score > 59)
    {
        letterGrade = 'D';
    }
    else
    {
        letterGrade = 'F';
    }
    return letterGrade;
}
#endif
