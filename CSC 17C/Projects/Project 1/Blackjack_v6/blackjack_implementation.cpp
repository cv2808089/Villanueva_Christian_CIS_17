#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "card.h"
#include "winTracker.h"

using namespace std;

enum gameResult{lose, win, draw};

void getCard(struct card &c) //draws a card
{
    int n = rand() % 13 + 1; //gets a random number between 1 and 13
    int s = rand() % 4 + 1; //gets a random number between 1 and 4
    switch(n) //assigns a card value and name depending on the random number drawn
    {
        case 1: c.cardName = "Ace"; //assigns ace for 1
                c.cardValue = 1; //sets card value to 1
        break;
        case 2: c.cardName = "Two"; //assigns two for 2
                c.cardValue = 2; //sets card value to 2
        break;
        case 3: c.cardName = "Three"; //assigns three for 3
                c.cardValue = 3; //sets card value to 3
        break;
        case 4: c.cardName = "Four"; //assigns four for 4
                c.cardValue = 4; //sets card value to 4
        break;
        case 5: c.cardName = "Five"; //assigns five for 5
                c.cardValue = 5; //sets card value to 5
        break;
        case 6: c.cardName = "Six"; //assigns six for 6
                c.cardValue = 6; //sets card value to 6
        break;
        case 7: c.cardName = "Seven"; //assigns seven for 7
                c.cardValue = 7; //sets card value to 7
        break;
        case 8: c.cardName = "Eight"; //assigns eight for 8
                c.cardValue = 8; //sets card value to 8
        break;
        case 9: c.cardName = "Nine"; //assigns nine for 9
                c.cardValue = 9; //sets card value to 9
        break;
        case 10: c.cardName = "Ten"; //assigns ten for 10
                 c.cardValue = 10; //sets card value to 10
        break;
        case 11: c.cardName = "Jack"; //assigns jack for 11
                 c.cardValue = 10; //sets card value to 10
        break;
        case 12: c.cardName = "Queen"; //assigns queen for 12
                 c.cardValue = 10; //sets card value to 10
        break;
        case 13: c.cardName = "King"; //assigns king for 13
                c.cardValue = 10; //sets card value to 10
        break;
    }
    
    switch(s)
    {
        case 1: c.suit = "Spades"; //assigns suit to spades for 1
        break;
        case 2: c.suit = "Clubs"; //assigns suit to clubs for 2
        break;
        case 3: c.suit = "Diamonds"; //assigns suit to diamonds for 3
        break;
        case 4: c.suit = "Hearts"; //assigns suit to hearts for 4
        break;
    }
}

int check(struct card d[], struct card p[], struct card c, int dcp, int pcp) //checks if card has been already been played
{
    for(int i = 0; i < dcp-1; i++) //loop iterates through every dealer card played before and compares it to the card being checked
        if(c.cardName == d[i].cardName && c.suit == d[i].suit)
            return -1; //returns -1 if the card matches a previously played card
    if(pcp > 0) //only executes if there has been at least on player card played so far
        for(int i = 0; i < pcp-1; i++) //loop iterates through every player card played before and compares it to the card being checked
            if(c.cardName == p[i].cardName && c.suit == p[i].suit)
                return -1; //returns -1 if the card matches a previously played card
    return 1; //return 1 if no repeat cards were found
}

int aceGet() //gets the value of ace that the player decides
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
    return ac; //return the choice for ace
}

struct winTracker results(int dc, int pc, int dtotal, int ptotal) //outputs game results and records the result
{
    struct winTracker s; //defines the struct to return
    char result[] = "You lose"; //creates a cstring for the lose message
    
    cout << "Dealer's " << dtotal << " vs " << "Player's " << ptotal << endl; //outputs the dealer and player totals
    
    if(dc == 0 && pc == 0 && dc != pc) //outputs no winner if both total differences are zero
    {
        cout << "No winner" << endl;
        s.wr.winc = draw; //sets winc to draw
    }
    if(dc == pc) //outputs no winner if both total differences are the same
    {
        cout << "No winner" << endl;
        s.wr.winc = draw; //sets winc to draw
    }
    if(dc < 0 && pc < 0) //outputs no winner if both total differences are negative
    {
        cout << "No winner" << endl;
        s.wr.winc = draw; //sets winc to draw
    }
          
    if(dc < 0 && pc >= 0) //outputs dealer busts you win if dealer total difference is negative and the player's is not
    {
        cout << "Dealer busts" << endl;
        cout << "You win" << endl;
        s.wr.winc = win; //sets winc to win
    }
    if(dc >= 0 && pc < 0) //outputs you bust you lose if player total difference is negative and dealer's is not
    {
        cout << "You bust" << endl;
        cout << "You lose" << endl;
        s.wr.winc = lose; //sets winc to lose
    }
    if(dc < pc && dc >= 0) //outputs lose message cstring if dealer total differnce is smaller than player's and not negative
    {
        cout << result << endl;
        s.wr.winc = lose; //sets winc to lose
    }
    if(pc < dc && pc >= 0) //outputs you win if player total difference is smaller than dealer's and is not negative
    {
        cout << "You win" << endl;
        s.wr.winc = win; //sets winc to win
    }
    
    return s; //return the structure holding the result
}

char *binaryFileManip(string fileName, char *inputArray, int arrSize) //reads and writes to binary files
{
    char *arr; //defines char pointer to hold a char array
    arr = new char[10]; 
    fstream file(fileName, ios::in | ios::out | ios::binary); //defines a file stream for input and output to a binary file
    file.seekp(0L, ios::beg); //goes to start of file to write
    file.write(inputArray, arrSize); //writes the passed array to the file
    file.seekg(0L, ios::beg); //goes to the start of the file to read from
    file.read(arr, sizeof(arr)+1); //reads from the file and stores in the char pointer

    file.close(); //close the file
    
    return arr; //return the memory address of the char pointer
}

void binaryRecord(struct card s) //writes a card structure to a binary file
{
    fstream file("record.bin", ios::out | ios::binary); //defines a file stream for input to record.bin
    file.seekp(0L, ios::beg); //goes to the start of the file
    file.write(reinterpret_cast<char*>(&s), sizeof(s)); //writes the passed structure to record.bin
    
    file.close(); //close the file
}