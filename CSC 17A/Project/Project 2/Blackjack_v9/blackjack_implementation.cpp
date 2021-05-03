#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "hand.h"
#include "player.h"

using namespace std;

//enum for win condition
enum gameResult{lose, win, draw};


//checks if card has been already been played
int check(Hand d, player p, string nam, string su, int dcpp1, int pcp) 
{
    //loop iterates through every dealer card played before and compares it to the card being checked
    for(int i = 0; i < dcpp1-1; i++) 
    {
        if(nam == d.getCardsNam(i) && su == d.getCardsSu(i))
        {
            //returns -1 if the card matches a previously played card
            return -1; 
        }
    }
    
    //only executes if there has been at least on player card played so far
    if(pcp > 0) 
    {
        //loop iterates through every player card played before and compares it to the card being checked
        for(int i = 0; i < pcp-1; i++) 
        {
            if(nam == p.getCardsNam(i) && su == p.getCardsSu(i))
            {
                //returns -1 if the card matches a previously played card
                return -1; 
            }
            
            //return 1 if no repeat cards were found
            return 1; 
        }
    }
    return 1;
}


//outputs game results and records the result
gameResult results(int dc, int pc, int dtotal, int ptotal) 
{
    //creates a cstring for the lose message
    char result[] = "You lose"; 
    gameResult winc;
    
    //outputs the dealer and player totals
    cout << "Dealer's " << dtotal << " vs " << "Player's " << ptotal << endl; 
    
    //outputs no winner if both total differences are zero
    if(dc == 0 && pc == 0 && dc != pc) 
    {
        cout << "No winner" << endl;
        winc = draw;
    }
    //outputs no winner if both total differences are the same
    if(dc == pc) 
    {
        cout << "No winner" << endl;
        winc = draw;
    }
    //outputs no winner if both total differences are negative
    if(dc < 0 && pc < 0) 
    {
        cout << "No winner" << endl;
        winc = draw;
    }
    //outputs dealer busts you win if dealer total difference is negative and the player's is not      
    if(dc < 0 && pc >= 0) 
    {
        cout << "Dealer busts" << endl;
        cout << "You win" << endl;
        winc = win;
    }
    //outputs you bust you lose if player total difference is negative and dealer's is not
    if(dc >= 0 && pc < 0) 
    {
        cout << "You bust" << endl;
        cout << "You lose" << endl;
        winc = lose;
    }
    //outputs lose message cstring if dealer total differnce is smaller than player's and not negative
    if(dc < pc && dc >= 0) 
    {
        cout << result << endl;
        winc = lose;
    }
    //outputs you win if player total difference is smaller than dealer's and is not negative
    if(pc < dc && pc >= 0) 
    {
        cout << "You win" << endl;
        winc = win;
    }
    
    return winc;
}

//reads and writes to binary files
char *binaryFileManip(string fileName, char *inputArray, int arrSize) 
{
    //defines char pointer to hold a char array
    char *arr; 
    arr = new char[10]; 
    //defines a file stream for input and output to a binary file
    fstream file(fileName, ios::in | ios::out | ios::binary); 
    //goes to start of file to write
    file.seekp(0L, ios::beg); 
    //writes the passed array to the file
    file.write(inputArray, arrSize); 
    //goes to the start of the file to read from
    file.seekg(0L, ios::beg); 
    //reads from the file and stores in the char pointer
    file.read(arr, sizeof(arr)+1); 
    
    //close the file
    file.close(); 
    
    //return the memory address of the char pointer
    return arr; 
}