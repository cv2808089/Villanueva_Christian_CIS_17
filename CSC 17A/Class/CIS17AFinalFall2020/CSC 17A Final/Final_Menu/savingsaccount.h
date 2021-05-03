#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

class SavingsAccount
{
private:
    float Withdraw(float);               //Utility Procedure
    float Deposit(float);                //Utility Procedure
    float Balance;                       //Property
    int   FreqWithDraw;                  //Property
    int   FreqDeposit;                   //Property    
public:
    SavingsAccount(float);               //Constructor
    void  Transaction(float);            //Procedure
    float Total(float, int);	         //Savings Procedure
    float TotalRecursive(float,int);
    void  toString();                    //Output Properties
    class balzer
    {};
    class badwith
    {};
};
#endif /* SAVINGSACCOUNT_H */

