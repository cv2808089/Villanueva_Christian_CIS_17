#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main() 
{
    string file1;
    string file2;
    string line;
    char uch;
    char lch;
    
    fstream in;
    fstream out;
    
    cout << "Enter the name of the read file" << endl;
    cin >> file1;
    cout << "Enter the name of the write file" << endl;
    cin >> file2;

    in.open(file1, ios::in);
    out.open(file2, ios::out);

    cin.ignore();

    while (getline(in, line, '.')) 
    {
        bool c = false;
        for (int i = 0; i < line.length(); i++) 
        {
            if (!isalpha(line[i]))
                out << line[i];

            if (!c && isalpha(line[i])) 
            {
                uch = line[i];
                uch = toupper(uch);
                out << uch;
                c = true;
            }
            
            else if (c)
            {
                lch = line[i];
                lch = tolower(lch);
                out << lch;
            }
        }
        out << ".";
    }

    in.close();
    out.close();

    return 0;
}