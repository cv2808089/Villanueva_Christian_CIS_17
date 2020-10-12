/* 
 * File: Ga9EdC11P11.cpp
 * Author: Christian Villaueva
 * Created on 10/9/2020 at 8:55pm
 * Purpose: budget
 */

//System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries
struct mb
{
    float h;
    float u;
    float he;
    float t;
    float f;
    float m;
    float in;
    float e;
    float c;
    float misc;
    
};
//Global Constants - No Global Variables
//Only Universal Constants, Math, Physics, Conversions, Higher Dimensions

float btotal = 1420.00;
//Function Prototypes
void getDat(struct mb&);
void compare(struct mb, float);
//Execution Begins Here
int main(int argc, char** argv) 
{
    //Declare Variable Data Types and Constants
    struct mb a;
    
    //Initialize Variables
    getDat(a);
    
    //Exit stage right!
    return 0;
}

void getDat(struct mb &a)
{
    float total = 0;
    cout << "Enter housing cost for the month:$" << endl;
    cin >> a.h;
    total += a.h;
    cout << "Enter utilities cost for the month:$" <<endl;
    cin >> a.u;
    total += a.u;
    cout << "Enter household expenses cost for the month:$" << endl;
    cin >> a.he;
    total += a.he;
    cout << "Enter transportation cost for the month:$" << endl;
    cin >> a.t;
    total += a.t;
    cout << "Enter food cost for the month:$" << endl;
    cin >> a.f;
    total += a.f;
    cout << "Enter medical cost for the month:$" << endl;
    cin >> a.m;
    total += a.m;
    cout << "Enter insurance cost for the month:$" << endl;
    cin >> a.in;
    total += a.in;
    cout << "Enter entertainment cost for the month:$" << endl;
    cin >> a.e;
    total += a.e;
    cout << "Enter clothing cost for the month:$" << endl;
    cin >> a.c;
    total += a.c;
    cout << "Enter miscellaneous cost for the month:$" << endl;
    cin >> a.misc;
    total += a.misc;
    compare(a, total);
    
}

void compare(struct mb a, float total)
{
    if(a.h < 500.00)
        cout << "Housing Under" << endl;
    else if(a.h == 500.00)
        cout << "Housing Even" << endl;
    else
        cout << "Housing Over" << endl;
        
    if(a.u < 150.00)
        cout << "Utilities Under" << endl;
    else if(a.u == 150.00)
        cout << "Utilities Even" << endl;
    else
        cout << "Utilities Over" << endl;
        
    if(a.he < 65.00)
        cout << "Household Expenses Under" << endl;
    else if(a.he == 65.00)
        cout << "Household Expenses Even" << endl;
    else
        cout << "Household Expenses Over" << endl;
    
    if(a.t < 50.00)
        cout << "Transportation Under" << endl;
    else if(a.t == 50.00)
        cout << "Transportation Even" << endl;
    else
        cout << "Transportation Over" << endl;
    
    if(a.f < 250.00)
        cout << "Food Under" << endl;
    else if(a.f == 250.00)
        cout << "Food Even" << endl;
    else
        cout << "Food Over" << endl;
        
    if(a.m < 30.00)
        cout << "Medical Under" << endl;
    else if(a.m == 30.00)
        cout << "Medical Even" << endl;
    else
        cout << "Medical Over" << endl;
        
    if(a.in < 100.00)
        cout << "Insurance Under" << endl;
    else if(a.in == 100.00)
        cout << "Insurance Even" << endl;
    else
        cout << "Insurance Over" << endl;
    
    if(a.e < 150.00)
        cout << "Entertainment Under" << endl;
    else if(a.e == 150.00)
        cout << "Entertainment Even" << endl;
    else
        cout << "Entertainment Over" << endl;
        
    if(a.c < 75.00)
        cout << "Clothing Under" << endl;
    else if(a.c == 75.00)
        cout << "Clothing Even" << endl;
    else
        cout << "Clothing Over" << endl;
    
    if(a.misc < 50.00)
        cout << "Miscellaneous Under" << endl;
    else if(a.misc == 50.00)
        cout << "Miscellaneous Even" << endl;
    else
        cout << "Miscellaneous Over" << endl;
        
    float diff;
    diff = btotal-total;
    
    cout << showpoint << fixed << setprecision(2);
    if(diff > 0)
        cout << "You were $" << diff << " under budget";
    if(diff < 0)
        cout << "You were $" << diff*-1 << " over budget";
}