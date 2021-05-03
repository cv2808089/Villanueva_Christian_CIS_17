#include <iostream>
#include "day.h"
using namespace std;

int main()
{
    int d;
    
    cout << "Enter the day number" << endl;
    cin >> d;
    while(d <= 0 || d > 365)
    {
        cout << "Invalid date" << endl;
        cin.clear();
        cin >> d;
    }
    
    DayOfYear day(d);
    cout << endl;
    cout << "The day in word form: " << endl;
    day.print();
    
    return 0;
}

DayOfYear::DayOfYear(int d)
{
    nday = d;
}

void DayOfYear::print()
{
    if(nday <= 31)
    {
        day = nday;
        month = "January ";
    }
    
    if(nday <= 59 && nday >= 32)
    {
        day = nday - 31;
        month = "February ";
    }
    
    if(nday <= 90 && nday >= 60)
    {
        day = nday - 59;
        month = "March ";
    }
    
    if(nday <= 120 && nday >= 91)
    {
        day = nday - 90;
        month = "April ";
    }
    
    if(nday <= 151 && nday >= 121)
    {
        day = nday - 120;
        month = "May ";
    }
    
    if(nday <= 181 && nday >= 152)
    {
        day = nday - 151;
        month = "June ";
    }
    
    if(nday <= 212 && nday >= 182)
    {
        day = nday - 181;
        month = "July ";
    }
    
    if(nday <= 243 && nday >= 213)
    {
        day = nday - 212;
        month = "August ";
    }
    
    if(nday <= 273 && nday >= 244)
    {
        day = nday - 243;
        month = "September ";
    }
    
    if(nday <= 304 && nday >= 274)
    {
        day = nday - 273;
        month = "October ";
    }
    
    if(nday <= 334 && nday >= 305)
    {
        day = nday - 304;
        month = "November ";
    }
    
    if(nday <= 365 && nday >= 335)
    {
        day = nday - 334;
        month = "December ";
    }
    
    cout << month << day << endl;
}