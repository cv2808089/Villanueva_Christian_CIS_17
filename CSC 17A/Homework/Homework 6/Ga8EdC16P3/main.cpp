#include <iostream>
using namespace std;

template<class T>
T maximum(T n1, T n2)
{
    if(n1 > n2)
        return n1;
    else 
        return n2;
}

template<class T>
T minimum(T n1, T n2)
{
    if(n1 < n2)
        return n1;
    else 
        return n2;
}

int main()
{
    int n1, n2;
    cout << "Enter two values" << endl;
    cin >> n1 >> n2;
    cout  << "The bigger one is " << maximum(n1, n2) << endl;
    cout  << "The smaller one is " << minimum(n1, n2);
    
    return 0;
}

