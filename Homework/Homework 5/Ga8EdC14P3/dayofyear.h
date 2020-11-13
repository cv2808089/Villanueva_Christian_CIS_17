#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

class DayOfYear
{
private:
    int day;
    std::string month;
public:
    DayOfYear(int);
    DayOfYear(std::string, int);
    void print();
    int test()
    { return day; }
    
    DayOfYear operator ++ (int);
    DayOfYear operator ++ ();
    DayOfYear operator -- (int);
    DayOfYear operator -- ();
};


#endif /* DAYOFYEAR_H */

