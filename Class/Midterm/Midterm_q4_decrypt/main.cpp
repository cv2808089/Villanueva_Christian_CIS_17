#include <iostream>
#include <cstring>
using namespace std;


int test(int, char[]);
void dec(char[]);

int main()
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
    
    dec(cinput);

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