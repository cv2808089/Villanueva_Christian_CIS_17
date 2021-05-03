#include <iostream>
#include "dayofyear.h"
using namespace std;

int main()
{
    int day;
    string month;
    int t;
    
    cout << "Enter the day and month" << endl;
    cin >> day >> month;
    DayOfYear d(month, day);
    
    t = d.test();
    if(t == -1)
        return 0;
    
    cout << "The day after" << endl;
    ++d;
    d.print();
    
    cout << "The day before" << endl;
    --d;
    d = d--;
    d.print();
    
    return 0;
}

DayOfYear::DayOfYear(string m, int d)
{
    if(m == "January" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "January" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "February" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "February" && d > 28)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "March" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "March" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "April" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "April" && d >30)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "May" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "May" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "June" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "June" && d > 30)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "July" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "July" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "August" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "August" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "September" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "September" && d > 30)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "October" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "October" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "November" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "November" && d > 30)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else if(m == "December" && d < 1)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    else if(m == "December" && d > 31)
    {
        cout << "day outside range" << endl;
        day = -1;
    }
    
    else
    {
        month = m;
        day = d;
    }
}

void DayOfYear::print()
{
    cout << month << ' ' << day << endl;
}

DayOfYear DayOfYear::operator ++(int)
{
    DayOfYear temp(month, day);
    if(month == "January" && day == 31)
    {
        temp.day = 1;
        temp.month = "February";
    }
    else if(month == "February" && day == 28)
    {
        temp.day = 1;
        temp.month = "March";
    }
    else if(month == "March" && day == 31)
    {
        temp.day = 1;
        temp.month = "April";
    }
    else if(month == "April" && day == 30)
    {
        temp.day = 1;
        temp.month = "May";
    }
    else if(month == "May" && day == 31)
    {
        temp.day = 1;
        temp.month = "June";
    }
    else if(month == "June" && day == 30)
    {
        temp.day = 1;
        temp.month = "July";
    }
    else if(month == "July" && day == 31)
    {
        temp.day = 1;
        temp.month = "August";
    }
    else if(month == "August" && day == 31)
    {
        temp.day = 1;
        temp.month = "September";
    }
    else if(month == "September" && day == 30)
    {
        temp.day = 1;
        temp.month = "October";
    }
    else if(month == "October" && day == 31)
    {
        temp.day = 1;
        temp.month = "November";
    }
    else if(month == "November" && day == 30)
    {
        temp.day = 1;
        temp.month = "December";
    }
    else if(month == "December" && day == 31)
    {
        temp.day = 1;
        temp.month = "January";
    }
    else
        temp.day++;
    return temp;
}

DayOfYear DayOfYear::operator ++()
{
    if(month == "January" && day == 31)
    {
        day = 1;
        month = "February";
    }
    else if(month == "February" && day == 28)
    {
        day = 1;
        month = "March";
    }
    else if(month == "March" && day == 31)
    {
        day = 1;
        month = "April";
    }
    else if(month == "April" && day == 30)
    {
        day = 1;
        month = "May";
    }
    else if(month == "May" && day == 31)
    {
        day = 1;
        month = "June";
    }
    else if(month == "June" && day == 30)
    {
        day = 1;
        month = "July";
    }
    else if(month == "July" && day == 31)
    {
        day = 1;
        month = "August";
    }
    else if(month == "August" && day == 31)
    {
        day = 1;
        month = "September";
    }
    else if(month == "September" && day == 30)
    {
        day = 1;
        month = "October";
    }
    else if(month == "October" && day == 31)
    {
        day = 1;
        month = "November";
    }
    else if(month == "November" && day == 30)
    {
        day = 1;
        month = "December";
    }
    else if(month == "December" && day == 31)
    {
        day = 1;
        month = "January";
    }
    else
        ++day;
    return *this;
}

DayOfYear DayOfYear::operator --(int)
{
    DayOfYear temp(month, day);
    if(month == "January" && day == 1)
    {
        temp.day = 31;
        temp.month = "December";
    }
    else if(month == "February" && day == 1)
    {
        temp.day = 31;
        temp.month = "January";
    }
    else if(month == "March" && day == 1)
    {
        temp.day = 28;
        temp.month = "February";
    }
    else if(month == "April" && day == 1)
    {
        temp.day = 31;
        temp.month = "March";
    }
    else if(month == "May" && day == 1)
    {
        temp.day = 30;
        temp.month = "April";
    }
    else if(month == "June" && day == 1)
    {
        temp.day = 31;
        temp.month = "May";
    }
    else if(month == "July" && day == 1)
    {
        temp.day = 30;
        temp.month = "June";
    }
    else if(month == "August" && day == 1)
    {
        temp.day = 31;
        temp.month = "July";
    }
    else if(month == "September" && day == 1)
    {
        temp.day = 31;
        temp.month = "August";
    }
    else if(month == "October" && day == 1)
    {
        temp.day = 30;
        temp.month = "September";
    }
    else if(month == "November" && day == 1)
    {
        temp.day = 31;
        temp.month = "October";
    }
    else if(month == "December" && day == 1)
    {
        temp.day = 30;
        temp.month = "November";
    }
    else
        temp.day--;
    return temp;
}

DayOfYear DayOfYear::operator --()
{
    if(month == "January" && day == 1)
    {
        day = 31;
        month = "December";
    }
    else if(month == "February" && day == 1)
    {
        day = 31;
        month = "January";
    }
    else if(month == "March" && day == 1)
    {
        day = 28;
        month = "February";
    }
    else if(month == "April" && day == 1)
    {
        day = 31;
        month = "March";
    }
    else if(month == "May" && day == 1)
    {
        day = 30;
        month = "April";
    }
    else if(month == "June" && day == 1)
    {
        day = 31;
        month = "May";
    }
    else if(month == "July" && day == 1)
    {
        day = 30;
        month = "June";
    }
    else if(month == "August" && day == 1)
    {
        day = 31;
        month = "July";
    }
    else if(month == "September" && day == 1)
    {
        day = 31;
        month = "August";
    }
    else if(month == "October" && day == 1)
    {
        day = 30;
        month = "September";
    }
    else if(month == "November" && day == 1)
    {
        day = 31;
        month = "October";
    }
    else if(month == "December" && day == 1)
    {
        day = 30;
        month = "November";
    }
    else
        --day;
    return *this;
}