#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
using namespace std;

unsigned int JSHash(const std::string& str);
unsigned int DJBHash(const std::string& str);
int hSearch1(vector<bool> arr[], string val);
int hSearch2(vector<bool> arr[], string val);


const int elem = 5;


int main()
{
    vector<bool> aol[3*elem];
    string hold;
    int h1, h2;
    for(int i = 0; i < elem; i++)
    {
        cin >> hold;
        h1 = JSHash(hold);
        h2 = DJBHash(hold);
        aol[h1].push_back(1);
        aol[h2].push_back(1);
        cout << h1 << ' ' << h2 << endl;
    }
    
    cout << "Search for names or type end to exit" << endl;
    while(hold != "end")
    {
        cin >> hold;
        
        if(hSearch1(aol, hold) != -1)
            cout << hSearch1(aol, hold) << ' ';
        else
            cout << "nothing" << ' ';
        
        if(hSearch2(aol, hold) != -1)
            cout << hSearch2(aol, hold) << endl;
        else
            cout << "nothing" << endl;
    }
    return 0;
}

int hSearch1(vector<bool> arr[], string val)
{
    int h = JSHash(val);
    vector<bool>::iterator it = arr[h].begin();
    while(it != arr[h].end())
    {
        if(*it == 1)
            return h;
        else 
            it++;
    }
    return -1;
}

int hSearch2(vector<bool> arr[], string val)
{
    int h = DJBHash(val);
    vector<bool>::iterator it = arr[h].begin();
    while(it != arr[h].end())
    {
        if(*it == 1)
            return h;
        else 
            it++;
    }
    return -1;
}

unsigned int JSHash(const std::string& str)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash % (elem*3);
}

unsigned int DJBHash(const std::string& str)
{
   unsigned int hash = 5381;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash = ((hash << 5) + hash) + str[i];
   }

   return hash % (elem*3);
}