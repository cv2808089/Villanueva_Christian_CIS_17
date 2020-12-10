#ifndef ESSAY_H
#define ESSAY_H

#include "gradedactivity.h"
class Essay : public GradedActivity
{
private:
    float grammar;
    float spelling;
    float length;
    float content;
public:
    Essay(float g, float s, float l, float c) : GradedActivity(g+s+l+c)
    {
        setGrade(g, s, l, c);
    }
    
    void setGrade(float, float, float, float);
    
};

#endif /* ESSAY_H */

