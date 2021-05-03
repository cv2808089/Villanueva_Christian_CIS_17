#include <iostream>
using namespace std;

template <class T>
T total(T numval)
{
     T rtotal = 0;
     T value;
     cout << "\nEnter the values:" << endl;
    for(int i = 0; i < numval; i++)
    {
        cin >> value;
        rtotal += value;
        cin.clear();
    }
     
     return rtotal;
}

int main()
{
    int num;
    cout << "Enter the number of values to be input" << endl;
    cin >> num;
    cout << "Enter the values to recieve the total: " << total(num) << " is the total" << endl;
    
    return 0;
}
