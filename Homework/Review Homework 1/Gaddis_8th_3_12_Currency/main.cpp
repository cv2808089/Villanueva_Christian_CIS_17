#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

const float YEN_PER_DOLLAR = 105.65;
const float EUROS_PER_DOLLAR = .83;

int main()
{
    float usd;
    float yen;
    float euro;
    cout << "Enter the amount you want to convert(USD) " << endl;
    while(!(cin >> usd))
    {
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Amount must be input as digits " << endl;
        }
    }
    yen = usd*YEN_PER_DOLLAR;
    euro = usd*EUROS_PER_DOLLAR;

    cout << fixed << showpoint << setprecision(2);
    cout << usd << " USD = " << yen << " Yen and " << euro << " Euros " << endl;
    
    return 0;
}