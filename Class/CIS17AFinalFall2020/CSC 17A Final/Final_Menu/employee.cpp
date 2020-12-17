#include <iostream>
#include "employee.h"
#include <cstring>
using namespace std;

Employee::Employee(char n[],char j[],float r)
{
    strcpy(MyName, n);
    strcpy(JobTitle, j);
    HourlyRate = r;
    HoursWorked = 0;
    GrossPay = 0;
    NetPay = 0;
}

float Employee::Tax(float g)
{
    if(g < 500)
        return g*(.1);
    if(g > 500 && g < 1000)
        return g*(.2);
    else
        return g*(.3);
}

int Employee::setHoursWorked(int h)
{
    if(h < 0 || h > 84)
        throw badhours();
    HoursWorked = h;
    return HoursWorked;
}

float Employee::setHourlyRate(float r)
{
    if(r < 0 || r > 200)
        throw badrate();
    HourlyRate = r;
    return HourlyRate;
}

void Employee::toString()
{
    cout << "Name: " << MyName << endl;
    cout << "Job Title: " << JobTitle << endl;
    cout << "Hourly Rate: $" << HourlyRate << endl;
    cout << "Hours Worked: " << HoursWorked << endl;
    cout << "Gross Pay: " << GrossPay << endl;
    cout << "Net Pay: " << NetPay << endl;
}

float Employee::getGrossPay(float rate,int hours)
{
    if(hours <= 40)
        GrossPay = rate*hours;
    if(hours > 40 && hours < 50)
        GrossPay = rate*1.5*hours;
    if(hours >= 50)
        GrossPay = rate*2*hours;
    return GrossPay;
}
    
float Employee::getNetPay(float g)
{
    NetPay = g-Tax(g);
    return NetPay;
}

float Employee::CalculatePay(float r,int h)
{
    return getNetPay(getGrossPay(setHourlyRate(r), setHoursWorked(h)));
}
