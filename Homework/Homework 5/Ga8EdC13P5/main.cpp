#include <iostream>
#include "item.h"
using namespace std;

int main()
{
    string desc;
    int units;
    float price;
    
    
    //item 1
    cout << "Enter the description for item #1" << endl;
    getline(cin, desc);
    
    cout << "Enter the number of units on hand" << endl;
    cin >> units;
    
    cout << "Enter the price of the item" << endl;
    cin >> price;
    
    RetailItem item1(desc, units, price);
    
    
    //item 2
    cout << "Enter the description for item #2" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, desc);
    
    cout << "Enter the number of units on hand" << endl;
    cin >> units;
    
    cout << "Enter the price of the item" << endl;
    cin >> price;
    
    RetailItem item2(desc, units, price);
    
    
    //item 3
    cout << "Enter the description for item #3" << endl;
    cin.clear();
    cin.ignore();
    getline(cin, desc);
    
    cout << "Enter the number of units on hand" << endl;
    cin >> units;
    
    cout << "Enter the price of the item" << endl;
    cin >> price;
    
    RetailItem item3(desc, units, price);
    cout << "Item #1: " << item1.outDesc() << ' ' << item1.outUnits() << " on hand at $" << item1.outPrice() << endl;
    cout << "Item #2: " << item2.outDesc() << ' ' << item2.outUnits() << " on hand at $" << item2.outPrice() << endl;
    cout << "Item #3: " << item3.outDesc() << ' ' << item3.outUnits() << " on hand at $" << item3.outPrice() << endl;
    
    
    return 0;
}

RetailItem::RetailItem(std::string d, int u, float p) //constructor
{
    setInfo(d, u, p);
}

void RetailItem::setInfo(std::string d, int u, float p)//mutator
{
    description = d;
    unitsOnHand = u;
    price = p;
}