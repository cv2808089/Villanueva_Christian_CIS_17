/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Purpose:  Common searching and sorting algorithms
 */

//System Libraries Here
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries Here

//Global Constants Only, No Global Variables
//Like PI, e, Gravity, or conversions
int op1, op2;
int opeq = 0, opcomp = 0, opas = 0, opmd = 0, opind = 0;
//Function Prototypes Here
void prntAry(const int [],int,int);
void fillAry(int [],int,int,int);
void swap(int &,int &);
void smlLst(int [],int,int);
void mrkSort(int [],int);
int  linSrch(int [],int, int);
int  binSrch(int [],int, int);
void bublSrt(int [],int);
void selSort(int [],int);
void copyAry(int [],int [],int);

//Program Execution Begins Here
int main(int argc, char** argv) {
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare all Variables Here
    const int SIZE=3000;
    int array[SIZE],brray[SIZE];
    int lowRng=100,highRng=200;
    int perLine=10;
        
    //Finish initializing the rest of the array
    fillAry(array,SIZE,highRng,lowRng);
    copyAry(brray,array,SIZE);
    
    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);
    
    //Sort the array the for all positions
    //mrkSort(array,SIZE);
    bublSrt(array,SIZE);
    op1 = opeq + opas + opmd + opcomp + opind;
    selSort(brray,SIZE);
    op2 = opeq + opas + opmd + opcomp + opind;
    
    //Test the linear search by randomly choosing a value and
    //determine if found;
    //int value=rand()%(highRng-lowRng+1)+lowRng;
    
    //cout<<"Using the Linear Search"<<endl;
    //cout<<"The value "<<value<<" was found at position "
    //        <<linSrch(array,SIZE,value)<<endl;
    //op1 = opeq + opas + opmd + opcomp + opind;

    //cout<<"Using the Binary Search"<<endl;
    //cout<<"The value "<<value<<" was found at position "
    //        <<binSrch(brray,SIZE,value)<<endl;
    //op2 = opeq + opas + opmd + opcomp + opind;

    
    //Print the values in the array
    //prntAry(array,SIZE,perLine);
    //prntAry(brray,SIZE,perLine);
    cout << "Bubble:" << "selection" << endl;
    cout << op1 << ' ' << op2;
    //Exit
    return 0;
}

void copyAry(int copyIt[],int source[],int n){
    for(int i=0;i<n;i++){
        copyIt[i]=source[i];
    }
}

void selSort(int a[],int n){
    opeq = 0; opcomp = 0; opas = 0; opmd = 0; opind = 0;
    //Loop and declare variables
    int indx,min;
    opeq++;
    for(int pos=0;pos<n-1;pos++){
        //Find the smallest in the list, swap after finding
        opcomp++; opas+=2;
        min=a[pos];indx=pos;
        opeq+=2; opind++;
        opeq++;opas++;
        for(int i=pos+1;i<n;i++){
            opcomp++;opas++;
            opind++; opcomp++;
            if(a[i]<min){
                opeq+=2; opind++;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        a[indx]=a[pos];
        a[pos]=min;
        opind+=3; opeq+=2;
    }
}

void bublSrt(int a[],int n){
    opeq = 0; opcomp = 0; opas = 0; opmd = 0; opind = 0;
    //Keep looping and comparing until no swaps are left
    bool swap;
    do{
        opeq++;
        swap=false;
        //Check the list and Swap when necessary
        opeq++;
        for(int i=0;i<n-1;i++){
            opcomp++; opas+=2;
            opcomp++; opind+=2; opas++;
            if(a[i]>a[i+1]){
                opeq+=4; opind+=4;
                opas+=2; 
                int temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                swap=true;
            }
        }
        opcomp++;
    }while(swap);
}

int  binSrch(int a[],int n, int val){
    opeq = 0; opcomp = 0; opas = 0; opmd = 0; opind = 0;
    //Initialize end points which are indexes
    int lowEnd=0; opeq++;
    int highEnd=n-1; opeq++; opas++;
    
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        opeq++; opas++; opmd++;opcomp++;opind++;
        if(val==a[middle])
        {return middle;
        }
        else if(val>a[middle])
        {lowEnd=middle+1;
        opcomp++; opeq++; opas++;opind++;
        }
        else 
        {highEnd=middle-1;
        opeq++; opas++;
        }
        opcomp++;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}


int  linSrch(int a[],int n, int val){
    opeq = 0; opcomp = 0; opas = 0; opmd = 0; opind = 0;
    opeq++;
    for(int indx=0;indx<n;indx++){
        opcomp+=2;opas++;opcomp++;opind++;
        if(val==a[indx])return indx;
    }
    return -1;
}

void fillAry(int a[],int n,int hr,int lr){
    for(int indx=0;indx<n;indx++){
        a[indx]=rand()%(hr-lr+1)+lr;
    }
}

void prntAry(const int a[],int n,int perLine){
    //Print the values in the array
    cout<<endl<<"The Array Values"<<endl;
    for(int indx=0;indx<n;indx++){
        cout<<a[indx]<<" ";
        if(indx%perLine==(perLine-1))cout<<endl;
    }
    cout<<endl;
}

void mrkSort(int a[],int n){
    for(int pos=0;pos<n-1;pos++){
        smlLst(a,n,pos);
    }
}

void smlLst(int a[],int n,int pos){
    for(int i=pos+1;i<n;i++){
        if(a[pos]>a[i]){
            swap(a[pos],a[i]);
        }
    }
}

void swap(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}