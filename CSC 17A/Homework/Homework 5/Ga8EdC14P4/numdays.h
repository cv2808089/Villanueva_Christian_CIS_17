#ifndef NUMDAYS_H
#define NUMDAYS_H

class NumDays
{
private:
    int hours;
    float days;
public:
    NumDays(int);
    float outDays()
        { return days; }
    
    NumDays operator ++ (int);
    NumDays operator ++ ();
    NumDays operator -- (int);
    NumDays operator -- ();
    NumDays operator + (const NumDays &);
    NumDays operator - (const NumDays &);
};
#endif /* NUMDAYS_H */

