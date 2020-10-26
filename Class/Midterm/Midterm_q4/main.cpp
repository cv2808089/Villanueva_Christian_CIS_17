#include <iostream>
#include <cstring>
using namespace std;


int test(int, char[]);
void enc(char[]);

int main()
{
    char cinput[4];
    int input;
    int tresults;

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
    
    enc(cinput);

    return 0;
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
    numc[0] =  th;
    numc[1] = h;
    numc[2] = t;
    numc[3] = o;
    
    return res;
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