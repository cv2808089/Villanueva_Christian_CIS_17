#include <cstdlib>
#include <iostream>
#include <iomanip>
#include "savingsaccount.h"
using namespace std;


int main() 
{
    int bal;
    float tran;
    float ir;
    int time;
    cout << "Enter the starting balance" << endl;
    cin >> bal;
    
    try
    {
        SavingsAccount acc(bal);
        cout << "Enter the transactions and enter -0 when done" << endl;
        cin >> tran;
        while(tran != -0)
        {
            try
            {
                acc.Transaction(tran);
            }
            catch(SavingsAccount::badwith)
            {
                cout << "Error, balance is less than withdrawal" << endl;
            }
            cin >> tran;
        }
        
        cout << "Enter the interest rate of the savings account" << endl;
        cin >> ir;
        cout << "Enter the amount of time that the money will sit in the account for" << endl;
        cin >> time;
        acc.toString();
        cout << "Total after " << time << " years at " << ir*100 << "% interest rate is $" << fixed << showpoint << setprecision(2) << acc.Total(ir, time) << endl;
    }
    catch(SavingsAccount::balzer)
    {
        cout << "Error, balance is less than zero" << endl;
    }
    
    return 0;
}

