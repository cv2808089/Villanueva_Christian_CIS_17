#include <iostream>
#include "month.h"
using namespace std;

int main()
{
    Month m1;
    cout << "Enter a month number to be incremented" << endl;
    cin >> m1;
    m1++;
    cout << m1;
    cout << endl;
    
    Month m2;
    cout << "Enter a month number to be decremented" << endl;
    cin >> m2;
    m2--;
    cout << m2;
    cout << endl;
    
    int mn;
    cout << "Enter a month number to display the name" << endl;
    cin >> mn;
    Month m3(mn);
    cout << m3;
    
    return 0;
}

Month::Month(string n)
{
    int m;
    setName(n);
    if(n == "January")
        m = 1;
    if(n == "February")
        m = 2;
    if(n == "March")
        m = 3;
    if(n == "April")
        m = 4;
    if(n == "May")
        m = 5;
    if(n == "June")
        m = 6;
    if(n == "July")
        m = 7;
    if(n == "August")
        m = 8;
    if(n == "September")
        m = 9;
    if(n == "October")
        m = 10;
    if(n == "November")
        m = 11;
    if(n == "December")
        m = 12;
    setMonth(m);
}

Month::Month(int m)
{
    string n;
    setMonth(m);
    switch(m)
    {
        case 1: n = "January";
        break;
        case 2: n = "February";
        break;
        case 3: n = "March";
        break;
        case 4: n = "April";
        break;
        case 5: n = "May";
        break;
        case 6: n = "June";
        break;
        case 7: n = "July";
        break;
        case 8: n = "August";
        break;
        case 9: n = "September";
        break;
        case 10: n = "October";
        break;
        case 11: n = "November";
        break;
        case 12: n = "December";
        break;
    }
    setName(n);
}

void Month::setName(string n)
{
    name = n;
}

void Month::setMonth(int m)
{
    monthNumber = m;
}

Month Month::operator ++(int)
{
    Month temp(name);
    monthNumber++;
    switch(monthNumber)
    {
        case 1: name = "January";
        break;
        case 2: name = "February";
        break;
        case 3: name = "March";
        break;
        case 4: name = "April";
        break;
        case 5: name = "May";
        break;
        case 6: name = "June";
        break;
        case 7: name = "July";
        break;
        case 8: name = "August";
        break;
        case 9: name = "September";
        break;
        case 10: name = "October";
        break;
        case 11: name = "November";
        break;
        case 12: name = "December";
        break;
        case 13: name = "January";
                 monthNumber = 1;
        break;
    }
    return temp;
}

Month Month::operator ++()
{
    Month temp(name);
    ++monthNumber;
    switch(monthNumber)
    {
        case 1: name = "January";
        break;
        case 2: name = "February";
        break;
        case 3: name = "March";
        break;
        case 4: name = "April";
        break;
        case 5: name = "May";
        break;
        case 6: name = "June";
        break;
        case 7: name = "July";
        break;
        case 8: name = "August";
        break;
        case 9: name = "September";
        break;
        case 10: name = "October";
        break;
        case 11: name = "November";
        break;
        case 12: name = "December";
        break;
        case 13: name = "January";
                 monthNumber = 1;
        break;
    }
    return temp;
}

Month Month::operator --(int)
{
    Month temp(name);
    monthNumber--;
    switch(monthNumber)
    {
        case 0: name = "December";
                monthNumber = 12;
        break;
        case 1: name = "January";
        break;
        case 2: name = "February";
        break;
        case 3: name = "March";
        break;
        case 4: name = "April";
        break;
        case 5: name = "May";
        break;
        case 6: name = "June";
        break;
        case 7: name = "July";
        break;
        case 8: name = "August";
        break;
        case 9: name = "September";
        break;
        case 10: name = "October";
        break;
        case 11: name = "November";
        break;
    }
    return temp;
}

Month Month::operator --()
{
    Month temp(name);
    --monthNumber;
    switch(monthNumber)
    {
        case 0: name = "December";
                monthNumber = 12;
        break;
        case 1: name = "January";
        break;
        case 2: name = "February";
        break;
        case 3: name = "March";
        break;
        case 4: name = "April";
        break;
        case 5: name = "May";
        break;
        case 6: name = "June";
        break;
        case 7: name = "July";
        break;
        case 8: name = "August";
        break;
        case 9: name = "September";
        break;
        case 10: name = "October";
        break;
        case 11: name = "November";
        break;
    }
    return temp;
}

istream &operator >> (istream &in, Month &temp)
{
    in >> temp.monthNumber;
    switch(temp.monthNumber)
    {
            case 1: temp.name = "January";
            break;
            case 2: temp.name = "February";
            break;
            case 3: temp.name = "March";
            break;
            case 4: temp.name = "April";
            break;
            case 5: temp.name = "May";
            break;
            case 6: temp.name = "June";
            break;
            case 7: temp.name = "July";
            break;
            case 8: temp.name = "August";
            break;
            case 9: temp.name = "September";
            break;
            case 10: temp.name = "October";
            break;
            case 11: temp.name = "November";
            break;
            case 12: temp.name = "December";
            break;
    }
    return in;
}

