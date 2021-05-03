/* 
 * File: Ga9EdC11P5.cpp
 * Author: Christian Villanueva
 * Created on 10/9/20 at 8:56pm
 * Purpose: weather stats
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct div
{
    float rf;
    float high;
    float low;
};

enum month{Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

//Function Prototypes
void getDat(struct div&, float&); //Gets info and outputs reults

//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare Variable Data Types and Constants
    struct div mon[Dec];
    float totalr = 0;
    float totalt = 0;
    float averaget;
    float averager;
    float max = 0;
    float min = 999;
    
    //Initialize Variables
    for(int i = Jan; i < Jul; i++)
    {
        getDat(mon[i], totalt);
        if(mon[i].low < min)
            min = mon[i].low;
        if(mon[i].high > max)
            max = mon[i].high;
        totalr += mon[i].rf;
    }
    
    averaget = totalt/12;
    averager = totalr/6;
    cout << showpoint << fixed << setprecision(2);
    cout << "Average monthly rainfall:" << averager << endl;
    cout << "High Temp:" << static_cast<int>(max) << endl;
    cout << "Low Temp:" << static_cast<int>(min) << endl;
    cout << showpoint << fixed << setprecision(1);
    cout << "Average Temp:" << averaget;

    //Exit stage right!
    return 0;
}

//Promts input and calculates/outputs results
void getDat(struct div &d, float &total)
{
    cout << "Enter the total rainfall for the month:" << endl;
    cin >> d.rf;
    cout << "Enter the high temp:" << endl;
    cin >> d.high;
    total += d.high;
    cout << "Enter the low temp:" << endl;
    cin >> d.low;
    total += d.low;
}