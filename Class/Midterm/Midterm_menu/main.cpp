#include <iostream>
#include <cstring>
#include <iomanip>
#include <cmath>
#include "employee.h"
#include "customer.h"
using namespace std;

int test(int, char[]);
void dec(char[]);
void enc(char[]);
void getNum(float); //maxed out at 15999, but realistically who makes that much in a week if they are getting payed by the hour?
void getPrime(int);
void p1();
void p2();
void p3();
void p4();
void p5();
void p6();
void p7();

int main() 
{
    char choice;
    
    do{
        cout << endl;
        cout << "Enter the number of the problem you want to see or enter exit to exit" << endl;
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{p1();break;}
            case '2':{p2();break;}
            case '3':{p3();break;}
            case '4':{p4();break;}
            case '5':{p5();break;}
            case '6':{p6();break;}
            case '7':{p7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

void p1()
{
    customer c1;
    float check;
    float deposit;
    bool overdraft = false;
    
    cin.ignore();
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
    
}

void p2()
{
    int numE;
    float dt;
    float tt;
    float dRemain;
    float tRemain;
    string company;
    string address;
    
    cin.ignore();
    cout << "Enter the name of the company" << endl;
    getline(cin, company);
    
    cout << "Enter the address of the company" << endl;
    getline(cin, address);
    
    cout << "Enter the number of employees" << endl;
    cin >> numE;
    
    employee e[numE];
    
    for(int i = 0; i < numE; i++)
    {
        cout << "Enter employee " << i+1 << " name" << endl;
        cin.ignore();
        getline(cin, e[i].name);
        
        cout << "Enter the pay rate" << endl;
        cin >> e[i].rate;
        
        dt = 2*e[i].rate;
        tt = 3*e[i].rate;
        
        cout << "Enter the number of hours worked" << endl;
        cin >> e[i].hours;
        
        if(e[i].hours > 40 && e[i].hours <= 50)
        {
            dRemain = e[i].hours - 40;
            e[i].gross = dRemain*dt + 40*e[i].rate;
        }
        
        if(e[i].hours >= 50)
        {
            tRemain = e[i].hours - 50;
            dRemain = e[i].hours - tRemain - 40;
            e[i].gross = tRemain*tt + dRemain*dt + 40*e[i].rate;
        }
        else 
            e[i].gross = e[i].hours*e[i].rate;
        
        cout << endl;
        cout << company << endl;
        cout << address << endl;
        cout << "Name:" << e[i].name << setw(20) << "Amount: $" << e[i].gross << endl;
        cout << "Amount: ";
        if(e[i].gross > 15999)
            cout << "Too much for one week or work";
        getNum(e[i].gross);
        cout << endl;
        cout << "Signature Line: ______________________________" << endl; 
    }
    
}

void getNum(float num) //for the record, I could have just added more switch statements for ten thousands, hundred thousands, or millions
//but I was being semi-realistic while making this
{
    int g = static_cast<int>(num);
    int th;
    int h;
    int t;
    int o;
    bool teen = false;
    
    th = g/1000;
    h = g%1000/100;
    t = g%100/10;
    o = g%10;
    
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
        case 10:cout << "Ten Thousand ";
        break;
        case 11:cout << "Eleven Thousand ";
        break;
        case 12:cout << "Twelve Thousand ";
        break;
        case 13:cout << "Thirteen Thousand ";
        break;
        case 14:cout << "Fourteen Thousand ";
        break;
        case 15:cout << "Fifteen Thousand ";
        break;
    }
    switch(h)
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
    switch(t)
    {
        case 1:
            teen = true;
            switch(o)
            {
                case 0:cout << "Ten";
                break;
                case 1:cout << "Eleven";
                break;
                case 2:cout << "Twelve";
                break;
                case 3:cout << "Thirteen";
                break;
                case 4:cout << "Fourteen";
                break;
                case 5:cout << "Fifteen";
                break;
                case 6:cout << "Sixteen";
                break;
                case 7:cout << "Seventeen";
                break;
                case 8:cout << "Eighteen";
                break;
                case 9:cout << "Nineteen";
                break;
            }
        break;
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
    if(teen == false)
        switch(o)
        {
            case 1:cout << "One ";
            break;
            case 2:cout << "Two ";
            break;
            case 3:cout << "Three ";
            break;
            case 4:cout << "Four ";
            break;
            case 5:cout << "Five ";
            break;
            case 6:cout << "Six ";
            break;
            case 7:cout << "Seven ";
            break;
            case 8:cout << "Eight ";
            break;
            case 9:cout << "Nine ";
            break;
        }
}

void p3()
{
    cout << "See the Midterm_q4 project for the solution to this problem" << endl;
}

void p4()
{
    char cinput[4];
    int input;
    int tresults;
    int testr = 12%8;
    cout << "Enter the four-digit integer" << endl;
    cin >> input;
    tresults = test(input, cinput);
    while(tresults == -1)
    {
        cout << "Invalid input, only accepts numbers 0-7 for each digit and must be four digits long" << endl;
        cin.clear();
        cin >> input;
        tresults = test(input, cinput);
    }
    
    string enchoice;
    cout << "Would you like to encrypt or decrypt?" << endl;
    cin >> enchoice;
    if(enchoice == "encrypt")
    {
        enc(cinput);
    }
    else
        dec(cinput); 
}   

int test(int num, char numc[])
{
    int res = 1;
    int th = num/1000;
    int h = num%1000/100;
    int t = num%100/10;
    int o = num%10;
    
    if(th > 7)
        res = -1;
    if(h > 7)
        res = -1;
    if(t > 7)
        res = -1;
    if(o > 7)
        res = -1;
    numc[0] = '0' + th;
    numc[1] = '0' + h;
    numc[2] = '0' + t;
    numc[3] = '0' + o;
    
    return res;
}

void dec(char num[])
{
    int numh[4];
    char hold;
    int original;
    int ohold;
    
    for(int i = 0; i < 4; i++)
    {
        numh[i] = num[i];
        numh[i] -= 48;
    }
    for(int i = 0; i < 4; i++)
    {
        for(int c = 0; c < 8; c++)
        {
            original = (c+5)%8;
            if(original == numh[i])
            {
                ohold = c;
                c+=8;
            }
        }  
        num[i] = '0' + ohold;
    }
    
    hold = num[0];
    num[0] = num[2];
    num[2] = hold;
    
    hold = num[1];
    num[1] = num[3];
    num[3] = hold; 
    
    cout << "The decrypted number is ";
    for(int i = 0; i < 4; i++)
        cout << num[i];
}       

void enc(char num[])
{
    int numh[4];
    char hold;
    
    for(int i = 0; i < 4; i++)
        num[i] = (num[i]+5);
    for(int i = 0; i < 4; i++)
        numh[i] = static_cast<int>(num[i]);
    for(int i = 0; i < 4; i++)
        numh[i] = numh[i]%8;
    for(int i = 0; i < 4; i++)
        num[i] = '0' + numh[i];
    
    hold = num[0];
    num[0] = num[2];
    num[2] = hold;
    
    hold = num[1];
    num[1] = num[3];
    num[3] = hold;
    
    cout << "The encrypted number is: ";
    for(int i = 0; i < 4; i++)
        cout << num[i];
}

void p5()
{
    cout << "An unsigned char can hold 5!" << endl;
    cout << "A signed char can hold 5!" << endl;
    cout << "An unsigned int can hold 17!" << endl;
    cout << "A signed int can hold 12!" << endl;
    cout << "An unsigned short can hold 8!" << endl;
    cout << "A signed short can hold 7!" << endl;
    cout << "An unsigned long can hold 20!" << endl;
    cout << "A signed long can hold 20!" << endl;
    cout << "A float can hold 34!" << endl;
    cout << "A double can hold 170!" << endl;
}

void p6()
{
    cout << "2.875 is 2.E in base 16, 0010.1110 in base 2, and 2.7 in base 8" << endl;
    cout << "2.875 in 8 digit hex is 5C000002" << endl;
    cout << ".1796875 is .2E in base 16, .00101110 in base 2, and .134 in base 8" << endl;
    cout << ".1796875 in 8 digit hex is 170000FE" << endl;
    cout << "-2.875 is D.2 in base 16, 101.000 in base 2, and 5.1 in base 8" << endl;
    cout << "-2.875 in 8 digit hex is A3FFFFFE" << endl;
    cout << "-.1796875 is .D2 in base 16, .11010001 in base 2, and .644 in base 8" << endl;
    cout << "-.1796875 in 8 digit hex is E8FFFF02" << endl;
    cout << "59999901 in decimal is 1.0347" << endl;
    cout << "59999902 in decimal is 2.7999" << endl;
    cout << "A66667FE in decimal is -2.7999" << endl;
}

void p7()
{
    int num;  
    cout << "Enter the number you want the prime factors of" << endl;
    cin >> num;
    
    getPrime(num);
  
}

void getPrime(int num)//I had some help with this one
{  
    int tcounter = 0;
    int icounter = 0;
    
    cout << "The prime factors are " << endl;
    while (num % 2 == 0)  
    {  
        tcounter++; 
        num = num/2;  
    }  
    if(tcounter != 0)
        cout << 2 << "^" << tcounter << ' ';
  
    for(int i = 3; i <= sqrt(num); i = i + 2)  
    {  
        while (num % i == 0)  
        {  
            num = num/i; 
            icounter++;
        }
        if(icounter > 1)
            cout << i << "^" << icounter << ' ';
        if(icounter == 1)
            cout << i << ' ';
        icounter = 0;    
    }  

    if (num > 2)  
        cout << num << " ";  
}  