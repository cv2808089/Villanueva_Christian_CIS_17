#include <iostream>
#include <string>
using namespace std;

const int NUM_NAMES = 20;
typedef string aoN[NUM_NAMES];
void sort(aoN);
int binarySearch(aoN, string);


int main()
{
    aoN names = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill",
        "Allison, Jeff", "Looney, Joe", "Wolfe, Bill",
        "James, Jean", "Weaver, Jim", "Pore, Bob",
        "Rutherford, Greg", "Javens, Renee",
        "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth" };
        
    string sname;
    int pos;
    cout << "Enter a name " << endl;
    getline(cin, sname);
    sort(names);
    pos = binarySearch(names, sname);

    if(pos == -1)
        cout << sname << " was not found";
    else
        cout << sname << " was found in the " << pos << " position";
    
    return 0;
}



void sort(string array[]) 
{
    for(int i = 0; i < NUM_NAMES - 1; i++) 
    {
        for(int b = i+1; b < NUM_NAMES; b++) 
        {
            if(array[i]>array[b]) 
            {
                string temp = array[i];
                array[i]= array[b];
                array[b] = temp;
            }
        }
    }
}

int binarySearch(aoN array, string value)
{
    int first = 0; // First array element
    int last = NUM_NAMES - 1; // Last array element
    int middle; // Midpoint of search
    int position  = -1; // Position of search value
    bool found = false; // Flag

    while (!found && first <= last)
    {
        middle = (first + last) / 2; // Calculate midpoint
        if (array[middle] == value) // If value is found at mid
            {
                found = true;
                position = middle;
            }
        else if (array[middle] > value) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }

    return position;
}