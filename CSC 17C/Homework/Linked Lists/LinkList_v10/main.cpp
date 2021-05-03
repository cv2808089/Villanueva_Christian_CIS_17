/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Create the 5 functions for Version 4 of this code.
 */

//System Libraries
#include <iostream>    //Input/Output Library
#include <cstdlib>     //NULL pointer
using namespace std;   //Library Name-space

//User Libraries
#include "Link.h"

//Global/Universal Constants -- No Global Variables
//Science, Math, Conversions, Higher Dimensioned constants only

//Function Prototypes

//Execution Begins Here
int main() 
{
    srand(time(0));
    //Declare variables
    
    Link<int> lnk1;
    lnk1.fillLst(5);

    //Printing all the data elements in the linked list
    lnk1.prntLst();
    cout << endl;
    
    int val;
    do
    {
        cin >> val;
        lnk1.find(val);
        lnk1.prntLst();
        cout << endl;
    }
    while(val != -1);
    //Exit stage right
    return 0;
}