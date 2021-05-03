#include <iostream>
#include <iomanip>
using namespace std;

float celsius(int);

int main()
{
    cout << "Fahrenheit" << setw(8) << "Celsius" << endl;
    cout << fixed << showpoint << setprecision(2);
    for(int f = 0; f <=20; f++)
    {
        if(f<=9)
            cout << f << setw(16) << celsius(f) << endl;
        else
           cout << f << setw(15) << celsius(f) << endl;
    }
    return 0;
}

float celsius(int temp)
{
    return (temp-32)*(5.0/9.0);
}
