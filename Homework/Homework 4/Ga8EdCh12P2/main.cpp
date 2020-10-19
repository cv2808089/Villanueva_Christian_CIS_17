#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    string name;
    string r;
    ifstream in;

    cout << "Enter the name of the file " << endl;
    cin >> name;

    in.open(name);

    cin.ignore();
    for(int i = 1; !in.eof(); i++)
    {
        if(i % 25 == 0)
        {
            system("Pause");
        }

        getline(in, r);
        cout << r << endl;
    }
    
    in.close();

    return 0;
}
