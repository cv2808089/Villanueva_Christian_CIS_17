#include <iostream>
#include <iomanip>
using namespace std;

struct movie
{
    string title;
    string dir;
    int year;
    float rt;
};
    
void display(struct movie);

int main()
{
    int num;
	cin >> num;
	struct movie m[num];
	
	cout << "This program reviews structures" << endl;
	cout << "Input how many movies, the Title of the Movie, Director, Year Released, and the Running Time in (minutes)." << endl << endl;
	
	for(int i = 0; i < num; i++)
	{
	    cin.ignore();
	    getline(cin, m[i].title);
	    getline(cin, m[i].dir);
	    cin >> m[i].year;
	    cin >> m[i].rt;
	}
	

	for(int i = 0; i < num; i++)
	{
	    display(m[i]);
	    if(i < num-1)
	        cout << endl;
	}
	
	return 0;
}

void display(struct movie m)
{
    cout << left << setw(11) << "Title:" << m.title << endl;
    cout << left << setw(11) << "Director:" << m.dir << endl;
    cout << left << setw(11) << "Year:" << m.year << endl;
    cout << left << setw(11) << "Length:" << m.rt << endl;
    
}