#include <iostream>
#include "player.h"

using namespace std;

void player::aceGet() //gets the value of ace that the player decides
{
    int ac; // holds ace choice
    cout << "Would you like the Ace to be worth 1 or 11?" << endl;
                cin >> ac; //gets the ace choice
                
                //loops if ace choice is not 1 or 11, outputting an error message and prompting another input for ace choice
                while(ac != 1 && ac != 11 || cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a valid choice" << endl;
                    cin >> ac;
                }
    aceResult =  ac; //return the choice for ace
}