#include <iostream>
#include "date.h"
using namespace std;

int main()
{
    Date date1;
    int month;
    int day; 
    int year;
    
    cout << "Enter the month" << endl;
    cin >> month;
    
    cout << "Enter the day" << endl;
    cin >> day;
    
    cout << "Enter the year" << endl;
    cin >> year;
    
    try
    {
        date1.setValues(month, day, year);
        date1.form1();
        date1.form2();
        date1.form3();
    }
    catch(Date::invalidDay)
    {
        cout << "Error, invalid day" << endl;
    }
    catch(Date::invalidMonth)
    {
        cout << "Error, invalid month" << endl;
    }
    
   return 0; 
}

void Date::setValues(int m, int d, int y)
{
    if(m < 0 || m > 12)
        throw invalidMonth();
    else
        month = m;
    if(d < 0 || d > 31)
        throw invalidDay();
    else
        day = d;
    
    year = y;
    
}

void Date::form1()
{
    cout << month << "/" << day << "/" << year << endl;
}

void Date::form2()
{
    string nMonth;
    
    switch(month)
    {
        case 1:
            nMonth = "January"; break;
        case 2: 
            nMonth = "February"; break;
        case 3:
            nMonth = "March"; break;
        case 4: 
            nMonth = "April"; break;
        case 5:
            nMonth = "May"; break;
        case 6:
            nMonth = "June"; break;
        case 7: 
            nMonth = "July"; break;
        case 8:
            nMonth = "August"; break;
        case 9: 
            nMonth = "September"; break;
        case 10:
            nMonth = "October"; break;
        case 11: 
            nMonth = "November"; break;
        case 12:
            nMonth = "December"; break;
        
    }
    
    cout << nMonth << " " << day << ", " << year << endl;
}


void Date::form3()
{
    string nMonth;
    
    switch(month)
    {
        case 1:
            nMonth = "January"; break;
        case 2: 
            nMonth = "February"; break;
        case 3:
            nMonth = "March"; break;
        case 4: 
            nMonth = "April"; break;
        case 5:
            nMonth = "May"; break;
        case 6:
            nMonth = "June"; break;
        case 7: 
            nMonth = "July"; break;
        case 8:
            nMonth = "August"; break;
        case 9: 
            nMonth = "September"; break;
        case 10:
            nMonth = "October"; break;
        case 11: 
            nMonth = "November"; break;
        case 12:
            nMonth = "December"; break;
        
    }
    
    cout << day << " " << nMonth <<  " " << year << endl;
}