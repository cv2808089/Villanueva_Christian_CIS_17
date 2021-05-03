#include <iostream>
#include <cstring>
#include "employee.h"
using namespace std;


int main() 
{
    char n[20];
    char t[20];
    float hr;
    int hw;

    cout << "Enter your name" << endl;
    cin.getline(n, 20);

    cout << "Enter your title" << endl;
    cin.getline(t, 20);

    cout << "Enter your hourly rate" << endl;
    cin >> hr;
    
    cout << "Enter the number of hours worked" << endl;
    cin >> hw;
    try
    {
    Employee e1(n, t, hr);
    e1.CalculatePay(hr, hw);
    e1.toString();
    }
    catch(Employee::badhours)
    {
        cout << "Hours can not be less than zero or greater than 84" << endl;
    }
    catch(Employee::badrate)
    {
        cout << "Rate can not be less than zero or greater than 200" << endl;
    }
    
    return 0;
}

