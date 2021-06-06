#include <iostream>
#include <unistd.h>
#include <list>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <cstring>
#include <time.h>

using namespace std;

string gen_random(const int);
unsigned int JSHash(const std::string& str);
int  linSrch(string a[],int n, string val);
int  binSrch(vector<string> a,int n, string val);
int hSearch(list<string> arr[], string val);


const int elem = 100000;


int main() 
{
    srand(time(0));
    list<string> aol[elem];
    vector<string> arr1;
    string arr2[elem];
    string val;
    string hold;
    int hsh;
    clock_t start1, start2, start3, end1, end2, end3;
    float t1, t2, t3;
    
    
    for(int i = 0; i < elem; i++)
    {
        hold = gen_random(20);
        hsh = JSHash(hold);
        aol[hsh].push_back(hold);
        arr1.push_back(hold);
        arr2[i] = hold;
    }
    
    val = hold;

    
    start1 = clock();
    if(linSrch(arr2, elem, val) != -1)
        cout << linSrch(arr2, elem, val) << endl;
    else
        cout << "error" << endl;
    end1 = clock();
    t1 = float(end1-start1)/CLOCKS_PER_SEC;
    
    sort(arr1.begin(), arr1.end());
    
    
    start2 = clock();
    if(binSrch(arr1, elem, val) != -1)
        cout << binSrch(arr1, elem, val) << endl;
    else
        cout << "error" << endl;
    end2 = clock();
    t2 = float(end2-start2)/CLOCKS_PER_SEC;
    
    start3 = clock();
    if(hSearch(aol, val) != -1)
            cout << hSearch(aol, val) << endl;
    else
        cout << "error" << endl;
    end3 = clock();
    t3 = float(end3-start3)/CLOCKS_PER_SEC;
    
    cout << t1 << endl;
    cout << t2 << endl;
    cout << t3 << endl;
    
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

int hSearch(list<string> arr[], string val)
{
    int h = JSHash(val);
    list<string>::iterator it = arr[h].begin();
    while(it != arr[h].end())
    {
        if(*it == val)
            return h;
        else 
            it++;
    }
    return -1;
}

int  linSrch(string a[],int n, string val)
{
    for(int indx=0;indx<n;indx++){
        if(val==a[indx])return indx;
    }
    return -1;
}

int  binSrch(vector<string> a,int n, string val)
{
    //Initialize end points which are indexes
    int lowEnd=0;
    int highEnd=n-1;
    
    //Loop until value found not indexes
    do{
        int middle=(highEnd+lowEnd)/2;
        if(val==a[middle])return middle;
        else if(val>a[middle])lowEnd=middle+1;
        else highEnd=middle-1;
    }while(lowEnd<=highEnd);
    
    //Not found
    return -1;
}

unsigned int JSHash(const std::string& str)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < str.length(); i++)
   {
      hash ^= ((hash << 5) + str[i] + (hash >> 2));
   }

   return hash % elem;
}