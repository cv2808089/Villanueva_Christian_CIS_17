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
    //Declare variables
    int size = 200;
    int npush;
    
    Link<int> lnk1;
    lnk1.fillLst(size);

    //Printing all the data elements in the linked list
    lnk1.prntLst();
    cout << endl;
    
    cout << "How many values do you want pushed on the front?" << endl;
    cin >> npush;
    for(int i = 0; i < npush; i++)
        lnk1.pshFrnt(rand() % 90 + 10);
    lnk1.prntLst();
    cout << endl;
    
    
    cout << "How many values do you want pushed on the back?" << endl;
    cin >> npush;
    for(int i = 0; i < npush; i++)
        lnk1.pshBack(rand() % 90 + 10);
    lnk1.prntLst();
    cout << endl;
    
    
    cout << "How many values do you want popped off the front?" << endl;
    cin >> npush;
    for(int i = 0; i < npush; i++)
        lnk1.popFrnt();
    lnk1.prntLst();
    cout << endl;
    
    
    cout << "How many values do you want popped off the back?" << endl;
    cin >> npush;
    for(int i = 0; i < npush; i++)
        lnk1.popBack();
    lnk1.prntLst();
    cout << endl;
    
    //Exit stage right
    return 0;
}