#include <iostream>
#include <limits>
using namespace std;

int checkLeap(int);
int checkDays(int, int);

int main()
{
    int month;
    int year;
    int leap;
    int days;

    
    cout << "Enter a month as a number (1 - 12) " << endl;
    while(!(cin >> month) || (month < 1) || (month > 12))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        cout << "Invalid input, please try again " << endl;
    }
    
    
    cout << "Enter a year for that month " << endl;
     while(!(cin >> year) || year <= 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>:: max(), '\n');
        cout << "Invalid input, please try again " << endl;
    }
    
    
    days = checkDays(month, year);

    cout << "There are " << days << " days in that month " << endl;

    return 0;
}

int checkLeap(int year)
{
    int check;
    check = (year % 4 == 0) ? 1 : 0;
    return check;
}

int checkDays( int month, int year)
{
    int days;
    int leap;
    leap = checkLeap(year);
    
      switch(month)
    {
        case 1: days = 31;
        break;
        case 2: days = (leap == 1) ? 29 : 28;
        break;
        case 3: days = 31;
        break;
        case 4: days = 30;
        break;
        case 5: days = 31;
        break;
        case 6: days = 30;
        break;
        case 7: days = 31;
        break;
        case 8: days = 31;
        break;
        case 9: days = 30;
        break;
        case 10: days = 31;
        break;
        case 11: days = 30;
        break;
        case 12: days = 31;
    }
      return days;
}