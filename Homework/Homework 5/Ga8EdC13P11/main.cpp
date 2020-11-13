#include <iostream>
#include <iomanip>
#include "payroll.h"
using namespace std;

int main()
{
    PayRoll employee[7];
    
    for(int i = 0; i < 7; i++)
    {
        cin.clear();
        int hours;
        float rate;
        
        cout << "Enter the number of hours worked for employee #" << i+1 << endl;
        cin >> hours;
        while(hours > 60)
        {
            cin.clear();
            cout << "Cant have more than 60 hours" << endl;
            cin >> hours;
        }
        employee[i].getHours(hours);
        
        cout << "Enter the pay rate for employee #" << i+1 << endl;
        cin >> rate;
        employee[i].getRate(rate);
        cout << endl;
    }
    
    cout << endl;
    cout << showpoint << fixed << setprecision(2);
    
    for(int i = 0; i < 7; i++)
    {
        cout << "Employee #" << i+1 << " gross pay: $" << employee[i].calcTotal() << endl;
    }
    
    return 0;
}

void PayRoll::getHours(int h)
{
    hours = h;
}

void PayRoll::getRate(float r)
{
    rate = r;
}

float PayRoll::calcTotal()
{
    total = rate*hours;
    return total;
}