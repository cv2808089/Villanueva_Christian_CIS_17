#include <iostream>
#include "numdays.h"
using namespace std;

int main()
{
    int h1, h2;
    cout << "Enter the number of hours" << endl;
    cin >> h1;
    cout << "Enter more hours" << endl;
    cin >> h2;
    NumDays num1(h1);
    NumDays num2(h2);
    NumDays num3(h1 + h2);
    NumDays num4(h1 - h2);
    cout << "Amount 1 converted into days: " << num1.outDays() << endl;
    cout << "Amount 2 converted into days: " << num2.outDays() << endl;
    cout << "The two amounts added together: " << num3.outDays() << endl;
    cout << "The two amounts subtracted from each other: " << num4.outDays() << endl;
    num1++;
    cout << "Amount 1( + 1 hour) converted into days: " << num1.outDays() << endl;
    num2--;
    cout << "Amount 2( - 1 hour) converted into days: " << num2.outDays() << endl;
    return 0;
}

NumDays::NumDays(int h)
{
    hours = h;
    days = h/8.00;
}

NumDays NumDays::operator ++ (int)
{
    NumDays temp(hours);
    hours++;
    days = hours/8.00;
    return temp;
}

NumDays NumDays::operator ++ ()
{
    ++days;
    days = hours/8.00;
    return *this;
}

NumDays NumDays::operator -- (int)
{
    NumDays temp(hours);
    hours--;
    days = hours/8.00;
    return temp;
}

NumDays NumDays::operator -- ()
{
    --days;
    days = hours/8.00;
    return *this;
}

NumDays NumDays::operator + (const NumDays &n2)
{
    NumDays temp(hours);
    temp.hours = hours + n2.hours;
    temp.days = temp.hours/8.00;
    return temp;
}

NumDays NumDays::operator - (const NumDays &n2)
{
    NumDays temp(hours);
    temp.hours = hours - n2.hours;
    temp.days = temp.hours/8.00;
    return temp;
}