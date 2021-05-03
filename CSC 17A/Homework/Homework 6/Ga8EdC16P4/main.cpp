#include <iostream>
using namespace std;


template <class T>
T abs(T val)
{
    if(val < 0)
        return val*-1;
    else 
        return val;
}
int main()
{
    float value;
    cout << "Enter a number" << endl;
    cin >> value;
    cout << "The absolute value is " << abs(value) << endl;
    return 0;
}