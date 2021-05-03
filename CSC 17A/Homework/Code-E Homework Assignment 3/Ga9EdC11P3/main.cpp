/* 
 * File: Ga9EdC11P3.cpp
 * Author: Christian Villanueva
 * Created on 10/7/20 at 1:17pm
 * Purpose: store company division data
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct div
{
    string name;
    float first;
    float second;
    float third;
    float fourth;
    float total;
    float average;
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getDat(struct div&); //Gets info and outputs reults

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare Variable Data Types and Constants
    struct div n;
    struct div e;
    struct div s;
    struct div w;
    
    
    //Initialize Variables
    n.name = "North";
    e.name = "East";
    s.name = "South";
    w.name = "West";

    //Initialize variables and output results
    getDat(n);
    cout << endl;
    getDat(w);
    cout << endl;
    getDat(e);
    cout << endl;
    getDat(s);

    //Exit stage right!
    return 0;
}

//Promts input and calculates/outputs results
void getDat(struct div &d)
{
    cout << d.name << endl;
    cout << "Enter first-quarter sales:" << endl;
    cin >> d.first;
    cout << "Enter second-quarter sales:" << endl;
    cin >> d.second;
    cout << "Enter third-quarter sales:" << endl;
    cin >> d.third;
    cout << "Enter fourth-quarter sales:" << endl;
    cin >> d.fourth;
    
    d.total = d.first + d.second + d.third + d.fourth;
    d.average = d.total / 4;
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Total Annual sales:$" << d.total << endl;
    cout << "Average Quarterly Sales:$" << d.average;
    
}
