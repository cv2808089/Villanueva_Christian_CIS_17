#include <iostream>
#include <cmath>


using namespace std;

void getPrime(int);
/* Driver code */
int main()  
{  
  int num;  
    cout << "Enter the number you want the prime factors of" << endl;
    cin >> num;
    
    getPrime(num);
    
    return 0;
}  


void getPrime(int num)  
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