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
    
    Link<int> lnk1;
    lnk1.fillLst(5);

    //Printing all the data elements in the linked list
    lnk1.prntLst();
    cout << endl;
    
    //pop front and back
    lnk1.pshFrnt(rand() % 9 + 1);
    lnk1.pshBack(rand() % 9 + 1);
    lnk1.prntLst();
    cout << endl;
    
    //pop node from front 
    lnk1.popFrnt();
    lnk1.prntLst();
    cout << endl;
    
    //pop node off back
    lnk1.popBack();
    lnk1.prntLst();
    cout << endl;
    
    lnk1.insert_before(10, 3);
    lnk1.prntLst();
    cout << endl;
    
    lnk1.insert_after(12, 3);
    lnk1.prntLst();
    cout << endl;
    
    lnk1.del(3);
    lnk1.prntLst();
    //Exit stage right
    return 0;
}