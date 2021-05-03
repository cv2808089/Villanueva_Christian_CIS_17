#include <iostream>
#include "numbers.h"
using namespace std;

int main()
{
    int n;
    cout << "Enter the non-negative number" << endl;
    cin >> n;
    while(n < 0)
    {
        cout << "Error, negative number" << endl;
        cin.clear();
        cin >> n;
    }
    
    Numbers num(n);
    num.print();
    
    return 0;
}

Numbers::Numbers(int n)
{
    number = n;
}

void Numbers::print()
{
    int th = number/1000;
    int hu = number%1000/100;
    int to = number - th*1000 - hu*100;
    int te = to/10;
    string lessThan20[20] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", 
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}; 
    
    switch(th)
    {
        case 1:cout << "One Thousand ";
        break;
        case 2:cout << "Two Thousand ";
        break;
        case 3:cout << "Three Thousand ";
        break;
        case 4:cout << "Four Thousand ";
        break;
        case 5:cout << "Five Thousand ";
        break;
        case 6:cout << "Six Thousand ";
        break;
        case 7:cout << "Seven Thousand ";
        break;
        case 8:cout << "Eight Thousand ";
        break;
        case 9:cout << "Nine Thousand ";
        break;
    }
    
    switch(hu)
    {
        case 1:cout << "One Hundred ";
        break;
        case 2:cout << "Two Hundred ";
        break;
        case 3:cout << "Three Hundred ";
        break;
        case 4:cout << "Four Hundred ";
        break;
        case 5:cout << "Five Hundred ";
        break;
        case 6:cout << "Six Hundred ";
        break;
        case 7:cout << "Seven Hundred ";
        break;
        case 8:cout << "Eight Hundred ";
        break;
        case 9:cout << "Nine Hundred ";
        break;
    }
    
    switch(te)
    {
        case 2:cout << "Twenty ";
        break;
        case 3:cout << "Thirty ";
        break;
        case 4:cout << "Fourty ";
        break;
        case 5:cout << "Fifty ";
        break;
        case 6:cout << "Sixty ";
        break;
        case 7:cout << "Seventy ";
        break;
        case 8:cout << "Eighty ";
        break;
        case 9:cout << "Ninety ";
        break;
    }
    
    to = to - te*10;
    if(number != 0 && to != 0 && to < 20)
        cout << lessThan20[to];
    else if(number == 0 && to == 0)
        cout << lessThan20[0];
}