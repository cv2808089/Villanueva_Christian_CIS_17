#include <iostream>
using namespace std;


float Rec(float x){
    float n = x/2;
    if(x < .000001)
        return 1.000001;
    return 2*(n-(n*n*n/6))/(1+((n*n*n/6)*(n*n*n/6)));
}


int main()
{
    
    cout << Rec(.99);
    return 0;
}