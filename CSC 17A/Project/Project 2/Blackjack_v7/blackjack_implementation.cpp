#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "hand.h"
#include "player.h"

using namespace std;

//enum for win condition
enum gameResult{lose, win, draw};


int check(hand d, player p, string nam, string su, int dcpp1, int pcp) //checks if card has been already been played
{
    for(int i = 0; i < dcpp1-1; i++) //loop iterates through every dealer card played before and compares it to the card being checked
    {
        if(nam == d.getCardsNam(i) && su == d.getCardsSu(i))
        {
            return -1; //returns -1 if the card matches a previously played card
        }
    }
    
    if(pcp > 0) //only executes if there has been at least on player card played so far
    {
        for(int i = 0; i < pcp-1; i++) //loop iterates through every player card played before and compares it to the card being checked
        {
            if(nam == p.getCardsNam(i) && su == p.getCardsSu(i))
            {
                return -1; //returns -1 if the card matches a previously played card
            }
            
            return 1; //return 1 if no repeat cards were found
        }
    }
}


gameResult results(int dc, int pc, int dtotal, int ptotal) //outputs game results and records the result
{
    char result[] = "You lose"; //creates a cstring for the lose message
    gameResult winc;
    
    cout << "Dealer's " << dtotal << " vs " << "Player's " << ptotal << endl; //outputs the dealer and player totals
    
    if(dc == 0 && pc == 0 && dc != pc) //outputs no winner if both total differences are zero
    {
        cout << "No winner" << endl;
        winc = draw;
    }
    if(dc == pc) //outputs no winner if both total differences are the same
    {
        cout << "No winner" << endl;
        winc = draw;
    }
    if(dc < 0 && pc < 0) //outputs no winner if both total differences are negative
    {
        cout << "No winner" << endl;
        winc = draw;
    }
          
    if(dc < 0 && pc >= 0) //outputs dealer busts you win if dealer total difference is negative and the player's is not
    {
        cout << "Dealer busts" << endl;
        cout << "You win" << endl;
        winc = win;
    }
    if(dc >= 0 && pc < 0) //outputs you bust you lose if player total difference is negative and dealer's is not
    {
        cout << "You bust" << endl;
        cout << "You lose" << endl;
        winc = lose;
    }
    if(dc < pc && dc >= 0) //outputs lose message cstring if dealer total differnce is smaller than player's and not negative
    {
        cout << result << endl;
        winc = lose;
    }
    if(pc < dc && pc >= 0) //outputs you win if player total difference is smaller than dealer's and is not negative
    {
        cout << "You win" << endl;
        winc = win;
    }
    
    return winc;
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

