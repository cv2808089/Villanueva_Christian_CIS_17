#include <iostream>
#include <iomanip>
#include "inventory.h"
using namespace std;

int main()
{
    int number;
    int quantity;
    float cost;
    
    cout << "Enter the item number" << endl;
    cin >> number;
    while(number < 0)
    {
        cout << "Error, negative value" << endl;
        cin.clear();
        cin >> number;
    }
    
    cout << "Enter the quantity" << endl;
    cin >> quantity;
    while(quantity < 0)
    {
        cout << "Error, negative value" << endl;
        cin.clear();
        cin >> quantity;
    }
    
    cout << "Enter the cost" << endl;
    cin >> cost;
    while(cost < 0)
    {
        cout << "Error, negative value" << endl;
        cin.clear();
        cin >> cost;
    }
    
    Inventory inv(number, quantity, cost);
    cout << endl;
    cout << "Item number: " << inv.getItemNumber() << endl;
    cout << "Quantity: " << inv.getQuantity() << endl;
    cout << showpoint << fixed << setprecision(2);
    cout << "Cost: $" << inv.getCost() << endl;
    cout << "The total cost for inventory $" << inv.getTotalCost() << endl;
    
    return 0;
}

Inventory::Inventory()
{
    itemNumber = 0;
    quantity = 0;
    cost = 0;
    totalCost = 0;
}

Inventory::Inventory(int n, int q, float c)
{
    setItemNumber(n);
    setQuantity(q);
    setCost(c);
    setTotalCost(q, c);
}

void Inventory::setItemNumber(int n)
{
    itemNumber = n;
}

void Inventory::setQuantity(int q)
{
    quantity = q;
}

void Inventory::setCost(float c)
{
    cost = c;
}

void Inventory::setTotalCost(int q, float c)
{
    totalCost = q*c;
}

