#include <iostream>
#include <iomanip>
#include "employee.h"
#include "productionworker.h"
using namespace std;


void printRecord(productionWorker);

int main()
{
    string n;
    int num;
    string d;
    int sh;
    float r;
    
    cout << "Enter the employee's name" << endl;
    getline(cin, n);
    cout << "Enter their employee number" << endl;
    cin >> num;
    cout << "Enter their hire date(MM/DD/YYYY)" << endl;
    cin >> d;
    cout << "Enter which shift the employee works" << endl;
    cin >> sh;
    cout << "Enter their pay rate" << endl;
    cin >> r;
    
    productionWorker e1(n, num, d, sh, r);
    printRecord(e1);
    
    return 0;
}

void printRecord(productionWorker e)
{
    cout << "Name:            " << e.getName() << endl;
    cout << "Employee Number: " << e.getNum() << endl;
    cout << "Hire date:       " << e.getDate() << endl;
    if(e.getShift() == 1)
        cout << "Shift:           Day" << endl;
    else
        cout << "Shift:           Night" << endl;
    cout << showpoint << fixed << setprecision(2);
    cout << "Pay Rate:        $" << e.getRate() << endl; 
}

Employee::Employee(string n, int num, string d)
{
    setName(n);
    setNum(num);
    setDate(d);
}

void Employee::setName(string n)
{
    name = n;
}

void Employee::setNum(int n)
{
    number = n;
}

void Employee::setDate(string d)
{
    date = d;
}

void productionWorker::setShift(int s)
{
    shift = s;
}
    
void productionWorker::setRate(float r)
{
    rate = r;
}
