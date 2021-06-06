/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Test out push values onto simple vector
 *           with a very complex object
 *           Note:  This simple vector only works with objects
 *           Also overloading the == operator in this version of Object
 *           Simple Vector using Linked List
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <sstream>
using namespace std;

//User Libraries
#include "Object.h"       //2D Object
#include "SimpleVector.h" //Simple Vector only works with Classes

//Global Constants

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    //Test an object
    Object a(3),b(4);
    SimpleVector<Object> svp(a);
    
    //Fill the simple vector with 10 randomly size 2D Array Objects and
    //print the last one
    for(int i=0;i<500;i++){
        int rSize=rand()%10;
        Object c(rSize);
        svp.push(c);
    }
    cout << svp.op;
    //Exit*/
    return 0;
}