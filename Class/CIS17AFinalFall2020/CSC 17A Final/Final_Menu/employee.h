#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
    float Tax(float);      //Utility Procedure
    char   MyName[20];      //Property
    char   JobTitle[20];    //Property
    float  HourlyRate;      //Property
    int    HoursWorked;     //Property
    float  GrossPay;        //Property
    float  NetPay;          //Property
public:
    Employee(char[],char[],float);  //Constructor
    float  CalculatePay(float,int); //Procedure
    float  getGrossPay(float,int);  //Procedure
    float  getNetPay(float);        //Procedure
    void   toString();              //Procedure
    int    setHoursWorked(int);     //Procedure
    float  setHourlyRate(float);    //Procedure
    class badhours
    {};
    class badrate
    {};
};


#endif /* EMPLOYEE_H */

