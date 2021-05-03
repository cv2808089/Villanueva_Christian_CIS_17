#include <iostream>
#include <ctime>
#include "prob1random.h"
using namespace std;

int main() 
{
    srand(time(0));
    char n=5;
    char rndseq[]={19, 34, 57, 79, 126};
    int ntimes=100000;
    
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
	a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
	cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
    
    return 0;
}

