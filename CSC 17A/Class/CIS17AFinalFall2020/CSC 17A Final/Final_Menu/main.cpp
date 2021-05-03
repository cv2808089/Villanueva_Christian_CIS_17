#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <ctime>
#include "employee.h"
#include "prob1random.h"
#include "prob2sort.h"
#include "prob3table.h"
#include "prob3tableinherited.h"
#include "savingsaccount.h"

using namespace std;

void p1();
void p2();
void p3();
void p4();
void p5();
void p6();

int main() 
{
    char choice;
    do
    {
        cout << "Enter the number of the problem you want to see or type anything else to exit" << endl;
        cin >> choice;
        switch(choice){
            case '1':{p1();break;}
            case '2':{p2();break;}
            case '3':{p3();break;}
            case '4':{p4();break;}
            case '5':{p5();break;}
            case '6':{p6();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }
    while(choice>='1'&&choice<='6');
    
    
    return 0;
}

void p1()
{
    cout << "Note: when ran as an individual program, no issues are present, but here there are issues" << endl;
    srand(time(0));
    char n=5;
    char rndseq[]={19, 34, 57, 79, 126};
    int ntimes=100000;
    
    Prob1Random a(n,rndseq);
    for(int i=1;i<=ntimes;i++)
    {
	a.randFromSet();
    }
    int *x=a.getFreq();
    char *y=a.getSet();
    for(int i=0;i<n;i++)
    {
	cout<<int(y[i])<<" occured "<<x[i]<<" times"<<endl;
    }
    cout<<"The total number of random numbers is "<<a.getNumRand()<<endl;
}

void p2()
{
    cout<<"The start of Problem 2, the sorting problem"<<endl;
	Prob2Sort<char> rc;
	bool ascending=true;
	fstream infile;
	infile.open("Problem2.txt",ios::in);
	char *ch2=new char[10*16];
	char *ch2p=ch2;
	while(infile.get(*ch2)){cout<<*ch2;ch2++;}
	infile.close();
	cout<<endl;
	cout<<"Sorting on which column"<<endl;
	int column;
	cin>>column;
	char *zc=rc.sortArray(ch2p,10,16,column,ascending);
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<16;j++)
		{
			cout<<zc[i*16+j];
		}
	}
	delete []zc;
        cout << endl;
}

void p3()
{
    cout<<"Entering problem number 3"<<endl;
    cout << "Note: this one is broken" << endl;
    /*
    int rows=5;
    int cols=6;
    Prob3TableInherited<int> tab("Problem3.txt",rows,cols);
    const int *naugT=tab.getTable();
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
	{
            cout<<naugT[i*cols+j]<<" ";
	}
        cout<<endl;
    }
    cout<<endl;
    const int *augT=tab.getAugTable();
    for(int i=0;i<=rows;i++)
    {
	for(int j=0;j<=cols;j++)
	{
            cout<<augT[i*(cols+1)+j]<<" ";
	}
	cout<<endl;
    }
    */
}

void p4()
{
    cout << "NOTE: I DID THE EXTRA CREDIT FOR THIS ONE(PROBLEM 4)" << endl;
    cout << "NOTICE THE EXCEPTIONS" << endl;
    
    
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
}

void p5()
{
    cout << "NOTE: I DID THE EXTRA CREDIT FOR THIS ONE(PROBLEM 5)" << endl;
    cout << "NOTICE THE EXCEPTIONS" << endl;
    
    char n[20];
    char t[20];
    float hr;
    int hw;
    cin.ignore();
    cout << "Enter your name" << endl;
    cin.getline(n, 20);

    cout << "Enter your title" << endl;
    cin.getline(t, 20);

    cout << "Enter your hourly rate" << endl;
    cin >> hr;
    
    cout << "Enter the number of hours worked" << endl;
    cin >> hw;
    try
    {
    Employee e1(n, t, hr);
    e1.CalculatePay(hr, hw);
    e1.toString();
    }
    catch(Employee::badhours)
    {
        cout << "Hours can not be less than zero or greater than 84" << endl;
    }
    catch(Employee::badrate)
    {
        cout << "Rate can not be less than zero or greater than 200" << endl;
    }
}

void p6()
{
    cout << "3.75 in decimal is 3.C in hex, 0011.1100 in binary, and 3.6 in octal" << endl;
    cout << ".7 in decimal is .B333 in hex, .101100110011 in binary, and .54631 in octal" << endl;
    cout << "89.9 in decimal is 59.E666 in hex, 1011001.111001100 in binary, and 131.71463 in octal" << endl;
    
    cout << "3.75 in NASA float is 78000002" << endl;
    cout << ".7 in NASA float is 59999900" << endl;
    cout << "89.9 in NASA float is 59E6607" << endl;
    
    cout << "3.75 in scaled integer binary with 1 byte is: 00111100" << endl; //8WD 4BP
    cout << ".7 in scaled integer binary with 2 bytes is: 1011001100110011" << endl; //16WD 16BP
    cout << "89.9 in scaled integer binary with 3 bytes is: 010110011110011001100110" << endl; //24WD 16BP
    
    cout << "00111100 multiplied by 7 and then shifted back to integer is 26" << endl;
    cout << "1011001100110011 multiplied by 7 and then shifted back to integer is 4" << endl;
    cout << "010110011110011001100110 multiplied by 7 and then shifted back to integer is 629" << endl;
    
    cout << "26 in IEEE is 41D00000" << endl;
    cout << "4 in IEEE is 40800000" << endl;
    cout << "629 in IEEE is 441D4000" << endl;
}

