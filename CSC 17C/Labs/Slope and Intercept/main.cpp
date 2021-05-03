#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() 
{
    ifstream in;
    ifstream in2;
    int i = 0;
    int n = 37;
    float Sx = 0;
    float Sy = 0;
    float Sxx = 0;
    float Sxy = 0;
    float m;
    float b;
    float hold;
    float sarr[37];
    float carr[37];
    
    
    in.open("fahrenheit.txt");
    while(in)
    {
        in >> sarr[i];
        i++;
    }
    in.close();
    
    
    i = 0;
    in2.open("celsius.txt");
    while(in2)
    {
        in2 >> carr[i];
        i++;
    }
    in2.close();
    
    
    for(int i = 0; i < 37; i++)
    {
        Sx += sarr[i];
        Sy += carr[i];
        Sxx += sarr[i]*sarr[i];
        Sxy += carr[i]*sarr[i];
    }
    
    m = (Sx*Sy - n*Sxy)/(Sx*Sx-n*Sxx);
    b = (Sy - m*Sx)/n;
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Slope = " << m << ' ' << "Intercept = " << b;
    return 0;
}

