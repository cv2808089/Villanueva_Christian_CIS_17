#include <iostream>
#include "info.h"

using namespace std;

int main()
{
    info myInfo;
    info buddyInfo;
    info famInfo;
    string name;
    string address;
    int age;
    string pnumber;
    
    
    //your info
    cout << "Enter your name" << endl;
    getline(cin, name);
    
    cout << "Enter your address" << endl;
    getline(cin, address);
    
    cout << "Enter your age" << endl;
    cin >> age;
    
    cout << "Enter your phone number" << endl;
    cin.ignore();
    getline(cin, pnumber);
    
    myInfo.getInfo(name, address, age, pnumber);
    
    cin.clear();
    
    //friend info
    cout << "Enter your friend's name" << endl;
    getline(cin, name);
    
    cout << "Enter your friend's address" << endl;
    getline(cin, address);
    
    cout << "Enter your friend's age" << endl;
    cin >> age;
    
    cout << "Enter your friend's phone number" << endl;
    cin.ignore();
    getline(cin, pnumber);
    
    buddyInfo.getInfo(name, address, age, pnumber);
    
    cin.clear();
    
    //family member info
    cout << "Enter a family member's name" << endl;
    getline(cin, name);
    
    cout << "Enter their address" << endl;
    getline(cin, address);
    
    cout << "Enter their age" << endl;
    cin >> age;
    
    cout << "Enter their phone number" << endl;
    cin.ignore();
    getline(cin, pnumber);
    
    famInfo.getInfo(name, address, age, pnumber);
    
    
    //output
    cout << endl;
    myInfo.output();
    cout << endl;
    buddyInfo.output();
    cout << endl;
    famInfo.output();
    
    
    return 0;
}

void info::getInfo(string n, string ad, int ag, string p)
{
    name = n;
    address = ad;
    age = ag;
    pnumber = p;
    
}


void info::output()
{
    cout << "Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Age: " << age << endl;
    cout << "Phone Number: " << pnumber << endl; 
}