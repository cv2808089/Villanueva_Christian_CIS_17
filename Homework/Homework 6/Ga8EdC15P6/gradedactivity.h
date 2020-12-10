#ifndef GRADEDACTIVITY_H
#define GRADEDACTIVITY_H

class GradedActivity
{
protected:
    float score;
public:
    GradedActivity()
    { score = 0.0; }
    GradedActivity(float s)
    { score = s; }
    void setScore(float s)
    { score = s; }
    float getScore() const
    { return score;}
    
    virtual char getLetterGrade() const;
};


#endif /* GRADEDACTIVITY_H */

