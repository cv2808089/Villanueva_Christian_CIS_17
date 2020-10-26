#include <iostream>
#include <iomanip>
#include "employee.h"
using namespace std;

void getNum(float); //maxed out at 15999, but realistically who makes that much in a week if they are getting payed by the hour?

int main()
{
    int numE;
    float dt;
    float tt;
    float dRemain;
    float tRemain;
    string company;
    string address;
    
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
    
    return 0;
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