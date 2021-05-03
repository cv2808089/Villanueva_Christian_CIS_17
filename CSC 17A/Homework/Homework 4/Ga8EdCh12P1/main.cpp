#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main()
{
    string file;
    string s;
    fstream in;

    cout << "Enter the file name" << endl;
    cin >> file;
    
    in.open(file, ios::in);
    
    cin.ignore();
    for(int i = 0; i < 10; i++)
    {
        if(in.eof())
        {
            cout << "EoF" << endl;
            break;
        }
        getline(in, s);
        cout << s << endl;
    }

    in.close();

    return 0;
}