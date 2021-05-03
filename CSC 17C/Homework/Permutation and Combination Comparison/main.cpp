#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

float fact(float);

int main() 
{
    float PR[25][27];
    int k = 0;
    
    for(int n = 2; n <= 26; n++)
    {
        for(int m = 0; m <= n; m++)
        {
            PR[k][m] = pow(n, m);
        }
        k++;
    }

    float P[25][27];
    k = 0;
    float f1, f2, f3;
    for(int n = 2; n <= 26; n++)
    {
        f1 = fact(n);
        for(int m = 0; m <= n; m++)
        {
            f2 = fact(n-m);
            P[k][m] = f1/f2;
        }
        k++;
    }
    
    float CR[25][27];
    k = 0;
    for(int n = 2; n <= 26; n++)
    {
        for(int m = 0; m <= n; m++)
        {
            f1 = fact(n+m-1);
            f2 = fact(n-1);
            f3 = fact(m);
            CR[k][m] = f1/f2/f3;
        }
        k++;
    }

    float C[25][27];
    k = 0;
    for(int n = 2; n <= 26; n++)
    {
        for(int m = 0; m <= n; m++)
        {
            f1 = fact(n);
            f2 = fact(n-m);
            f3 = fact(m);
            C[k][m] = f1/f2/f3;
        }
        k++;
    }
    
    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    cout<<"N -> Number of total elements"<<endl;
    cout<<"M -> Number of elements to take from the total"<<endl<<endl;
    cout<<" N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl<<endl;
    
    cout << left << setw(20) << 'n' << setw(20) << 'm' << setw(20) << "P rep" 
                    << setw(20) << "P no Rep" << setw(20) << "C Rep" << "C no Rep" << endl;
    cout << left << setw(20) << ' ' << setw(20) << ' ' << setw(20) << "n^m" 
                    << setw(20) << "n/(n-m)!" << setw(20) << "(n+m-1)!/(n-1)!/m!" << "n!/(n-m)!/m!" << endl << endl;
    for(int i = 0; i <= 24; i++)
    {
        for(int j = 0; j <= i+2; j++)
            cout << left << setw(20) << i+2 << setw(20) << j << setw(20) << PR[i][j] << setw(20) << P[i][j] 
                    << setw(20) << CR[i][j] << C[i][j] << endl;
        
        cout << endl;
    }
    
    
    return 0;
}

float fact(float n)
{
    if(n == 0)
        return 1;
    return n * fact(n-1);
}

