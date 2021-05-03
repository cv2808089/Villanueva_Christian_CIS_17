#include "savingsaccount.h"
#include <iostream>
#include <cmath>
using namespace std;

float SavingsAccount::Withdraw(float w)
{
    Balance = Balance + w;
    FreqWithDraw++;
    return Balance;
}

float SavingsAccount::Deposit(float d)
{
    Balance = Balance + d;
    FreqDeposit++;
    return Balance;
}

SavingsAccount::SavingsAccount(float s)
{
    if(s < 0)
        throw balzer();
    FreqWithDraw = 0;
    FreqDeposit = 0;
    Balance = s;
    
}

void SavingsAccount::Transaction(float s)
{
    if(s < 0 && (-1*s) > Balance)
        throw badwith();
    if(s > 0)
        Balance = Deposit(s);
    else
        Balance = Withdraw(s);
}

void SavingsAccount::toString()
{
    cout << "The balance is $" << Balance << endl;
    cout << "You made " << FreqDeposit << " deposits and " << FreqWithDraw << " withdrawals" << endl;
}

float SavingsAccount::Total(float ir, int time)
{
    Balance =  Balance*pow((1.0+ir), time);
    return Balance;
}

/*float SavingsAccount::TotalRecursive(float ir,int time)
{
    float hold;
    while(time > 0)
    {
        Balance = TotalRecursive(ir, time);
        time--; 
    }
    hold = Balance*(1.0+ir);
    return hold;
}
 */