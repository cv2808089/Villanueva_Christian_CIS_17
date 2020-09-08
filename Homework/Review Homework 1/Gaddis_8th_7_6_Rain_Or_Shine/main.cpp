#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char array[3][30];
    ifstream infile {"RainOrShine.txt"};
    int r[3];
    int s[3];
    int c[3];
    int maxs = 0;
    int maxc = 0;
    int maxr = 0;
    int mms;
    int mmc;
    int mmr;
    int ts = 0;
    int tc = 0;
    int tr = 0;

    for(int i = 0; i < 3; i++)
    {
        
        int sunny = 0;
        int cloudy = 0;
        int rainy = 0;
        
        for(int b = 0; b < 30;b++)
        {
            infile >> array[i][b];
            switch(array[i][b])
            {
                case 'S': sunny++; break;
                case 'C': cloudy++; break;
                case 'R': rainy++; break;
            }
        }

        s[i] = sunny;
        c[i] = cloudy;
        r[i] = rainy;
        
        cout << "There were " << s[i] << " sunny days in month " << i+6 << endl;
        cout << "There were " << c[i] << " cloudy days in month " << i+6 << endl;
        cout << "There were " << r[i] << " rainy days in month " << i+6 << endl;


        if(maxs < s[i])
        {
            maxs = s[i];
            mms = i+6;
        }
        if(maxc < c[i])
        {
            maxc = c[i];
            mmc = i+6;
        }
        if(maxr < r[i])
        {
            maxr = r[i];
            mmr = i+6;
        }
    
        ts+=s[i];
        tc+=c[i];
        tr+=r[i];
    }
    cout << "In total there were " << ts << " sunny days" << endl;
    cout << "In total there were " << tc << " cloudy days" << endl;
    cout << "In total there were " << tr << " rainy days" << endl;
    cout << "Month " << mms << " has the most sunny days at: " << maxs << endl;
    cout << "Month " << mmc << " has the most cloudy days at: " << maxc << endl;
    cout << "Month " << mmr << " has the most rainy days at: " << maxr;
    
    return 0;
}