#include <iostream>
#include <limits>
using namespace std;

int main()
{
    float temp = 0;
    float converted;
    cout << "Please enter a temperature in celsius " << endl; 
    while(!(cin >> temp))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(),'\n');
        cout << "Temperature must input as a number \n";
    }
    converted = temp*9/5 + 32;
    cout << temp << " celcius = " << converted << " fahrenheit " << endl;
    return 0;
}