#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
using namespace std;

string gen_random(const int);
int phoneHash(string);

int main() 
{
    srand(time(0));
    list<string> aol[512];
    int col[512];
    string hold;
    int hsh, c0 = 0, c1 = 0, c2 = 0, c3 = 0, c4 = 0, c5 = 0, c6 = 0, c7 = 0, c8 = 0, c9 = 0;
    for(int i = 0; i < 512; i++)
    {
        hold = gen_random(3);
        hsh = phoneHash(hold);
        aol[hsh].push_back(hold);
    }
    for(int i = 0; i < 512; i++)
    {
        col[i] = aol[i].size();
        switch(col[i])
        {
            case 0: c0++; break;
            case 1: c1++; break;
            case 2: c2++; break;
            case 3: c3++; break;
            case 4: c4++; break;
            case 5: c5++; break;
            case 6: c6++; break;
            case 7: c7++; break;
            case 8: c8++; break;
            case 9: c9++; break;
        }
    }
    cout << "Max collisions: " << *max_element(col, col+512) << endl;
    cout << "No collisions: " << c0 << endl; 
    cout << "One collision: " << c1 << endl;
    cout << "Two collisions: " << c2 << endl;
    cout << "Three collisions: " << c3 << endl;
    cout << "Four collisions: " << c4 << endl;
    cout << "Five collisions: " << c5 << endl;
    cout << "Six collisions: " << c6 << endl;
    cout << "Seven collisions: " << c7 << endl;
    cout << "Eight collisions: " << c8 << endl;
    cout << "Nine collisions: " << c9 << endl;
    return 0;
}

string gen_random(const int len) 
{
    string tmp_s;
    static const char alphanum[] =
        "abcdefghijklmnopqrstuvwxyz";
    
    tmp_s.reserve(len);

    for (int i = 0; i < len; ++i) 
        tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
    
    return tmp_s;
    
}

int phoneHash(string val)
{
    char hold[3];
    for(int i = 0; i < 3; i++)
    {
        switch(val[i])
        {
            case 'a': hold[i] = '2'; break;
            case 'b': hold[i] = '2'; break;
            case 'c': hold[i] = '2'; break;
            case 'd': hold[i] = '3'; break;
            case 'e': hold[i] = '3'; break;
            case 'f': hold[i] = '3'; break;
            case 'g': hold[i] = '4'; break;
            case 'h': hold[i] = '4'; break;
            case 'i': hold[i] = '4'; break;
            case 'j': hold[i] = '5'; break;
            case 'k': hold[i] = '5'; break;
            case 'l': hold[i] = '5'; break;
            case 'm': hold[i] = '6'; break;
            case 'n': hold[i] = '6'; break;
            case 'o': hold[i] = '6'; break;
            case 'p': hold[i] = '7'; break;
            case 'q': hold[i] = '7'; break;
            case 'r': hold[i] = '7'; break;
            case 's': hold[i] = '7'; break;
            case 't': hold[i] = '8'; break;
            case 'u': hold[i] = '8'; break;
            case 'v': hold[i] = '8'; break;
            case 'w': hold[i] = '9'; break;
            case 'x': hold[i] = '9'; break;
            case 'y': hold[i] = '9'; break;
            case 'z': hold[i] = '9'; break;
        }
    }
    int hsh = atoi(hold);
    return hsh % 512;
}