#include <iostream>
#include <limits>
using namespace std;


int calcPop(int, int);

int main()
{
    long tpop; //range: 2 - 9223372036854775807
    float rate; //range: 0 - 3.402823466 E + 38
    int days; //range: 1 - 2147483647

    cout << "What is the starting population? " << endl;
    while(!(cin >> tpop) || tpop < 2)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again " << endl;
    }

    cout << "What is the average percent population increase? " << endl;
    while(!(cin >> rate) || rate < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again " << endl;
    }

    rate = rate * .01;

    cout << "How many days will the population multiply? " << endl;
    while(!(cin >> days) || days < 1)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please try again " << endl;
    }

    cout << "The population on day 1 is " << tpop << endl;

    for(int i = 1; i < days; i++)
    {
        tpop += tpop*rate;
        cout << "The population on day " << i+1 << " is " << tpop << endl;
    }

    return 0;
}

