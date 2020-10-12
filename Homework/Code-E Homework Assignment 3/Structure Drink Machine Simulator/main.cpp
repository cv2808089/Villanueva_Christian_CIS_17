#include <iostream>
#include <iomanip>

using namespace std;

struct vm
{
    string name;
    float cost;
    int num = 20;
};

void display(struct vm);

int main()
{
	struct vm vend[5];
	string choice;
	float money;
	float total = 0;
	float diff;
	
	vend[0].name = "Cola";
	vend[0].cost = 75;
	
	vend[1].name = "Root Beer";
	vend[1].cost = 75;
	
	vend[2].name = "Lemon-Lime";
	vend[2].cost = 75;
	
	vend[3].name = "Grape Soda";
	vend[3].cost = 80;
	
	vend[4].name = "Cream Soda";
	vend[4].cost = 80;
	
	for(int i = 0; i < 5; i++)
	    display(vend[i]);
	cout << "Quit" << endl;
	

	while(getline(cin, choice))
	{   
	    if(choice == "Quit")
	        break;
	   
	    cin >> money;
	    total += money;
	    while(money < 0 || money > 100)
	    {
	        cin >> money;
	    }
	    cin.ignore();
	    
	    if(choice == "Cola")
	    {
	        diff = money - vend[0].cost;
	        cout << diff << endl;
	        vend[0].num -= 1;
	        if(vend[0].num == 0)
	            cout << "Sold out" << endl;
	       total -=diff;
	    }
	    if(choice == "Root Beer")
	    {
	        diff = money - vend[1].cost;
	        cout << diff << endl;
	        vend[1].num -= 1;
	        if(vend[1].num == 0)
	            cout << "Sold out" << endl;
	        total -= diff;
	    }
	    if(choice == "Lemon-Lime")
	    {
	        diff = money - vend[2].cost;
	        cout << diff << endl;
	        vend[2].num -= 1;
	        if(vend[2].num == 0)
	            cout << "Sold out" << endl;
	        total -= diff;
	    }
	    if(choice == "Grape Soda")
	    {
	        diff = money - vend[3].cost;
	        cout << diff << endl;
	        vend[3].num -= 1;
	        if(vend[3].num == 0)
	            cout << "Sold out" << endl;
	        total -= diff;
	    }
	    if(choice == "Cream Soda")
	    {
	        diff = money - vend[4].cost;
	        cout << diff << endl;
	        vend[4].num -= 1;
	        if(vend[4].num == 0)
	            cout << "Sold out" << endl;
	        total -= diff;
	    }
	    
	    for(int i = 0; i < 5; i++)
	        display(vend[i]);
	    cout << "Quit" << endl;
	}
	
	    cout << total << endl;
	
	return 0;
}

void display(struct vm a)
{
    cout << left << setw(11) << a.name  << a.cost << "  " << a.num << endl;
}