#include <iostream>
#include <cstring>
#include "customer.h"
using namespace std;

int main()
{
    customer c1;
    float check;
    float deposit;
    bool overdraft = false;
    
    
    cout << "Enter the account holder's name" << endl;
    getline(cin, c1.name);
    
    cout << "Enter the address associated with the account" << endl;
    getline(cin, c1.address);
    
    cout << "Enter the account number (5 digits)" << endl;
    cin >> c1.account;
    
    while(strlen(c1.account) != 5)
    {
        cout << "account number must be 5 digits long" << endl;
        cin.clear();
        cin.ignore();
        cin >> c1.account;
    }
    
    cout << "Enter the starting balance for the month" << endl;
    cin >> c1.stotal;
    
    c1.balance = c1.stotal;
    
    cout << "Enter each check written this month one at at time" << endl;
    cout << "When done, enter -1" << endl;
    cin >> check;
    while(check != -1)
    {
        if(check != -1)
        {
            c1.wtotal += check;
            c1.balance -= check;
        }
        
        cout << "Current balance: $" << c1.balance;
        
        if(c1.balance < 0)
            overdraft = true;
        
        cout << "Enter the next check" << endl;
        cin >> check;
    }
    
    cout << "Enter each deposit made this month one at a time" << endl;
    cout << "When done enter -1" << endl;
    cin >> deposit;
    while(deposit != -1)
    {
        if(deposit != -1)
        {
            c1.dtotal += deposit;
            c1.balance += deposit;
        }
        
        cout << "Current balance: $" << c1.balance;
        
        cout << "Enter the next deposit" << endl;
        cin >> deposit;
    }
    
    if(overdraft == true)
    {
        cout << "You overdrafted this month, so you were charged a $20 fee" << endl;
        c1.balance -= 20;
        cout << "Your balance after the overdraft charge: $" << c1.balance << endl;
    }
    
    cout << "Account info for account number: " << c1.account << endl;
    cout << "Name: " << c1.name << endl;
    cout << "Address: " << c1.address << endl;
    cout << "Starting monthly balance: $" << c1.stotal << endl;
    cout << "Total for checks written this month: $" << c1.wtotal << endl;
    cout << "Total deposited to account this month: $" << c1.dtotal << endl;
    cout << "Balance at the end of the month: $" <<  c1.balance << endl;
    
    return 0;
}
    