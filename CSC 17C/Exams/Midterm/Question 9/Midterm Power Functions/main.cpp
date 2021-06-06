#include <iostream>
using namespace std;

float pow1(float base, int exp);
float pow2(float base, int exp);

int main() 
{
    cout << pow1(2.5, 3) << endl;
    cout << pow2(4, -2);
    return 0;
}

float pow1(float base, int exp)
{
    if (exp == 0)
        return 1;
    
    if (exp > 0)
        return base*pow1(base, exp-1);
    
    else
        return pow1(base, exp +1) / base;
}

float pow2(float base, int exp)
{
    float hold;
    if(exp == 0)
        return 1;
    
    hold = pow2(base, exp / 2);
    
    if (exp % 2 == 0)
        return hold * hold;
    
    else
    {
        if(exp > 0)
            return base * hold * hold;
        else
            return (hold * hold) / base;
    }
}