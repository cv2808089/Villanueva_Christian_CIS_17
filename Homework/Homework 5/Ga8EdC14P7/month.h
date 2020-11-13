#ifndef MONTH_H
#define MONTH_H

#include <iostream>

class Month
{
private: 
    std::string name;
    int monthNumber;
public:
    Month()
    { 
        monthNumber = 1;
        name = "January";
    }
    
    Month(std::string);
    Month(int);
    void setName(std::string);
    void setMonth(int);
    
    std::string getName()
        { return name; }
    int getMonth()
        { return monthNumber; }
    
    Month operator ++ (int);
    Month operator ++ ();
    Month operator -- (int);
    Month operator -- ();
    
    friend std::ostream &operator << (std::ostream &out, Month &temp)
    {
        out << "Month number: " << temp.getMonth() << ", " << temp.getName();
        return out;
    }
    friend std::istream &operator >> (std::istream &, Month &);
};


#endif /* MONTH_H */

