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
Link *fillLst(int);
void prntLst(Link *);
void destroy(Link *);

//Prototype function you are to consider for Wednesday
Link *create(int);    //Create a Link with Data
void pshFrnt(Link *&); //Push a link to the front
void pshBack(Link *&); //Push a link to the end
Link *popFrnt(Link *);      //Pull/pop a link from the front
Link *popBack(Link *);      //Pull/pop a link from the back

//Execution Begins Here
int main(int argc, char** argv) {
    //Set the Random number seed
    
    //Declare variables
    Link *lnk1=fillLst(5);
    
    //Printing all the data elements in the linked list
    prntLst(lnk1);
    cout << endl;
    
    //pop front and back
    pshFrnt(lnk1);
    pshBack(lnk1);
    
    prntLst(lnk1);
    cout << endl;
    
    //pop node from front 
    lnk1 = popFrnt(lnk1);
    
    prntLst(lnk1);
    cout << endl;
    
    //pop node off back
    lnk1 = popBack(lnk1);
    prntLst(lnk1);
    
    //Delete all the allocated memory
    destroy(lnk1);
    
    //Exit stage right
    return 0;
}

Link *create(int val)
{
    Link *temp = new Link;
    temp->data = val;
    temp->lnkNext = NULL;
    return temp;
}

void pshFrnt(Link *&front)
{
    Link *temp = create(rand() % 9 + 1);
    temp->lnkNext = front;
    front = temp;
}

void pshBack(Link *&front)
{
    Link *temp = create(rand()%9+1);
    Link *last = front;
    while(last->lnkNext != NULL)
    {
        last = last->lnkNext;
    }
    last->lnkNext = temp;
}

Link *popFrnt(Link *front)
{
    Link *temp = front;
    front = front->lnkNext;
    delete temp;
    return front;
}

Link *popBack(Link *front)
{
    Link *slast = front;
    while(slast->lnkNext->lnkNext != NULL)
    {
        slast = slast->lnkNext;
    }
    delete slast->lnkNext;
    slast->lnkNext = NULL;
    
    return front;
}

Link *fillLst(int n){
    //Initially create the front pointer/beginning pointer
    Link *front=new Link;
    front->data=1;
    front->lnkNext=NULL;
    //If n>1 then fill with the data and links to the next
    Link *temp=front;
    for(int i=2;i<=n;i++){
        Link *nxtLink=new Link;
        nxtLink->data=i;
        temp->lnkNext=nxtLink;
        temp=nxtLink;
    }
    temp->lnkNext=NULL;
    //Return the front of the list
    return front;
}

void prntLst(Link *next){
    while(next!=NULL){
        cout<<next->data<<endl;
        next=next->lnkNext;
    }
}

void destroy(Link *front){
    while(front!=NULL){
        Link *temp=front;
        front=front->lnkNext;
        delete temp;
    }
}