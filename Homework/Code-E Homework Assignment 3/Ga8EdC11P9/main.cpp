#include <iostream>
using namespace std;

struct speaker
{
    string name;
    int pnum;
    string topic;
    float fee;
};

int main()
{
    struct speaker s[10];
    int num;
    int choice;
    
    cout << "Enter the number of Speakers " <<endl;
    cin >> num;
    
    for(int i = 0; i < num; i++)
    {
        cout << "Enter the name for speaker " << i+1 << endl;
        cin >> s[i].name;
        cout << "Enter the phone number for speaker " << i+1 << endl;
        cin >> s[i].pnum;
        cout << "Enter the topic for speaker " << i+1 << endl;
        cin >> s[i].topic;
        cout << "Enter the fee for speaker " << i+1 << endl;
        cin >> s[i].fee;
        if(s[i].fee < 0)
        {
            cout << "Enter a valid fee" <<endl;
            cin.clear();
            cin >> s[i].fee;
        }    
    }
    
    cout << "Enter the number of the speaker whose info you want to view" << endl;
    cout << "Enter -1 to exit" << endl;
    for(int i = 0; i < num; i++)
        {
            cout << i+1 << ". " << s[i].name << endl;
        }
    while(cin >> choice)
    {
        if(choice == -1)
            break;
        cout << "Name: " << s[choice-1].name << endl;
        cout << "Phone Number: " << s[choice-1].pnum << endl;
        cout << "Topic: " << s[choice-1].topic << endl;
        cout << "Fee: $" << s[choice-1].fee << endl;
        
        cout << "Enter the number of the speaker whose info you want to view" << endl;
        cout << "Enter -1 to exit" << endl;
        for(int i = 0; i < num; i++)
            {
                cout << i+1 << ". " << s[i].name << endl;
            }
    }
    
    return 0;
}