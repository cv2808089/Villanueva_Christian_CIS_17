#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "card.h"
#include "winTracker.h"
using namespace std;


//game can either end in win, loss, or a draw
enum gameResult{lose, win, draw};

//draws a card
void getCard(struct card &); 
//checks if card has been already been played
int check(struct card[], struct card[], struct card, int, int); 
//gets the value of ace that the player decides
int aceGet(); 
//outputs game results and records the result
struct winTracker results(int, int, int, int); 
//reads and writes to binary files
char *binaryFileManip(string, char *, int); 
//writes a card structure to a binary file
void binaryRecord(struct card); 


int main()
{
    //random number seed
    srand(time(0)); 
    //player cards
    struct card player[10]; 
    //dealer cards
    struct card dealer[10]; 
    //pointer to structure
    struct winTracker *gameResults; 
    gameResults = new winTracker;
    //stores hit or stay
    string choice; 
    //total sum of card values for dealer
    int dtotal = 0; 
    //total sum of card values for player
    int ptotal; 
    //difference from 21 of card total for dealer
    int dc; 
    //difference from 21 of card total for player
    int pc; 
    //either 1 or -1
    int chk; 
    //number of dealer cards played
    int dcp = 0; 
    //number of player cards played
    int pcp = 0; 
    //Holds the player's choice for the value of an ace
    int aceChoice; 
    
    //gets the first dealer card
    getCard(dealer[0]);
    //increment cards in play
    dcp++; 
    //chooses the value of aces to be 11
    if(dealer[0].cardValue == 1)
        dealer[0].cardValue = 11;
    
    //gets the second dealer card and checks for/replaces repeat cards
    getCard(dealer[1]);
    //increment cards in play
    dcp++; 
    chk = check(dealer, player, dealer[1], dcp, pcp); 
    if(chk == -1)
    {
        while(chk == -1)
        {
            getCard(dealer[1]);
            chk = check(dealer, player, dealer[1], dcp, pcp);
        }
    }
    //if an ace is drawn, 11 is chosen for its value if the dealer's total doesn't exceed 21
    if(dealer[0].cardValue == 1)
        if(dealer[0].cardValue + 11 <= 21)
            dealer[0].cardValue = 11;
    
    //gets player's first card and checks/replaces repeats
    getCard(player[0]);
    //increment cards in play
    pcp++; 
    chk = check(dealer, player, player[0], dcp+1, pcp);
    while(chk == -1)
    {
        getCard(player[0]);
        chk = check(dealer, player, player[0], dcp+1, pcp);
    }
    
    //gets players second card and checks/replaces repeats
    getCard(player[1]);
    //increment cards in play
    pcp++; 
    chk = check(dealer, player, player[1], dcp+1, pcp);
    while(chk == -1)
    {
        getCard(player[1]);
        chk = check(dealer, player, player[1], dcp+1, pcp);
    }
    
    //outputs the first dealer card and the two player cards
    cout << "The dealers shown card is: ";
    cout << dealer[0].cardName << ' ' << dealer[0].suit << endl << endl;
    cout << "Your cards are: " << endl;
    cout << player[0].cardName << ' ' << player[0].suit << endl;
    cout << player[1].cardName << ' ' << player[1].suit << endl << endl;
    
    //if the player draws a(n) ace(s), gets the players choice of value of either 1 or 11
    if(player[0].cardValue ==1)
    {
        aceChoice = aceGet();
                if(aceChoice == 11)
                    player[0].cardValue = 11;
    }
    if(player[1].cardValue ==1)
    {
        aceChoice = aceGet();
                if(aceChoice == 11)
                    player[1].cardValue = 11;
    }

    //gets the player's choice to draw another card or to keep current cards
    cout << "Would you like to hit or stay?" << endl;
    cin >> choice;
    
    //if choice is not "hit" or "stay" outputs an error message and prompts another input for choice
    while(choice != "hit" && choice != "stay")
    {
        cin.clear();
        cout << "Please enter either hit or stay" << endl;
        cin >> choice;
    }
    
    
    //executes if choice is "stay"
    if(choice == "stay") 
    {
        cout << endl;
        //finds the player's current total
        ptotal = player[0].cardValue + player[1].cardValue; 
        cout << "The Dealer's second card is: " << endl; 
        //outputs dealer's second card
        cout << dealer[1].cardName << ' ' << dealer[1].suit << endl << endl; 
        //array position for dealer's next drawn cards
        int dh = 2; 
        //finds dealer's current total
        dtotal = dealer[0].cardValue + dealer[1].cardValue; 
        
        //only executes if the dealer total is less than or equal to 16 and loops until the dealer total is above 16
        while(dtotal <= 16) 
        {
            cout << "The dealer draws a card" << endl;
            //gets dealers next card
            getCard(dealer[dh]); 
            //iterates the number of dealer cards in play
            dcp++; 
            //checks for/replaces repeat cards
            chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            while(chk == -1)
            {
                getCard(dealer[dh]);
                chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            }
            
            //if an ace is drawn, 11 is chosen for its value if the dealer's total doesn't exceed 21
            if(dealer[dh].cardValue == 1)
                if(dtotal + 11 <= 21)
                    dtotal += 10;
            cout << "The next card is " << endl;
            //outputs the dealer's next card
            cout << dealer[dh].cardName << ' ' << dealer[dh].suit << endl << endl; 
            //adds the card value to their total
            dtotal += dealer[dh].cardValue; 
            //iterates dealer structure array position
            dh++; 
        }  
    }
    
    
    //array position for player's next card drawn
    int ph = 2; 
    
    //only executes if choice is "hit"
    if(choice == "hit") 
    {
        //finds the player's current total
        ptotal = player[0].cardValue + player[1].cardValue; 
        //only executes if choice is "hit" and loops until choice is "stay"
        while(choice == "hit") 
        {
            //gets player's next card
            getCard(player[ph]); 
            //iterates the number of player cards in play
            pcp++; 
            
            //checks for /replaces repeat cards
            chk = check(dealer, player, player[ph], dcp+1, pcp);
            while(chk == -1)
            {
                getCard(player[ph]);
                chk = check(dealer, player, player[ph], dcp+1, pcp);
            }
            //outputs the player's drawn card
            cout << "You drew " << player[ph].cardName << ' ' << player[ph].suit << endl; 
            
            //if the player draws an ace, gets the players choice of value of either 1 or 11
            if(player[ph].cardValue == 1)
            {
                aceChoice = aceGet();
                //if the player chooses 11, changes the card value to 11
                if(aceChoice == 11) 
                    player[ph].cardValue = 11;
            }
            //adds the card value to the player total
            ptotal += player[ph].cardValue; 
            
            //makes choice "stay" if their total reaches or exceeds 21
            if(ptotal >= 21) 
                choice = "stay"; 
            
            //only executes if the player total is less than 21
            if(ptotal < 21) 
            {
                //gets the player's choice to draw another card or to keep current cards
                cout << "Would you like to hit or stay?" << endl; 
                cin >> choice;
                
                //if choice is not "hit" or "stay" outputs an error message and prompts another input for choice
                while(choice != "hit" && choice != "stay")
                {
                    cin.clear();
                    cout << "Please enter either hit or stay" << endl;
                    cin >> choice;
                }
            }
            //iterates the player structure array position
            ph++; 
        }
        
        cout << endl;
        cout << "The Dealer's second card is: " << endl; 
        //outputs dealer's second card
        cout << dealer[1].cardName << ' ' << dealer[1].suit << endl << endl; 
        //array position for dealer's next drawn cards
        int dh = 2; 
        //finds dealer's current total
        dtotal = dealer[0].cardValue + dealer[1].cardValue; 
        //only executes if the dealer total is less than or equal to 16 and loops until the dealer total is above 16
        while(dtotal <= 16) 
        {
            cout << "The dealer draws a card" << endl;
            //gets dealers next card
            getCard(dealer[dh]); 
            //iterates the number of dealer cards in play
            dcp++; 
            //checks for/replaces repeat cards
            chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            while(chk == -1)
            {
                getCard(dealer[dh]);
                chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            }
            
            //if an ace is drawn, 11 is chosen for its value if the dealer's total doesn't exceed 21
            if(dealer[dh].cardValue == 1)
                if(dtotal + 11 <= 21)
                    dtotal += 10;
            cout << "The next card is " << endl;
            //outputs the dealer's next card
            cout << dealer[dh].cardName << ' ' << dealer[dh].suit << endl << endl; 
            //adds the card value to their total
            dtotal += dealer[dh].cardValue;
            //iterates dealer structure array position
            dh++; 
        }  
    }
    
    
    //finds the difference of dealer's total and 21
    dc = 21-dtotal; 
    //finds the difference of player's total and 21
    pc = 21-ptotal; 
    
    //Finds and outputs results of game as well as writes to gameResults structure
    *gameResults = results(dc, pc, dtotal, ptotal);
   
    //character array to hold the result message
    char resultMessage[7]; 
    //character array to hold game name
    char gameName[9] = {'b', 'l', 'a', 'c', 'k', 'j', 'a', 'c', 'k'}; 
    //pointer to hold copy of result message
    char *readArray1; 
    readArray1 = new char;
    //pointer to hold copy of game name
    char *readArray2; 
    readArray2 = new char;
    
    //stores "winner" in resultMessage
    if(gameResults->wr.winc == win) 
    {
        resultMessage[0] = 'w';
        resultMessage[1] = 'i';
        resultMessage[2] = 'n';
        resultMessage[3] = 'n';
        resultMessage[4] = 'e';
        resultMessage[5] = 'r';
    }
    //stores "loser" in resultMessage
    if(gameResults->wr.winc == lose) 
    {
       resultMessage[0] = 'l';
       resultMessage[1] = 'o';
       resultMessage[2] = 's';
       resultMessage[3] = 'e';
       resultMessage[4] = 'r';
    }
    //stores "draw" in result Message
    if(gameResults->wr.winc == draw) 
    {
       resultMessage[0] = 'd';
       resultMessage[1] = 'r';
       resultMessage[2] = 'a';
       resultMessage[3] = 'w';
    }
    
    //writes reaultMessage to array.bin file and copies it to readArray1
    readArray1 = binaryFileManip("array.bin", resultMessage, sizeof(resultMessage)); 
    //writes gameName to array2.bin file and copies it to readArray2
    readArray2 = binaryFileManip("array2.bin", gameName, sizeof(gameName)); 
    //writes player[0] to record.bin
    binaryRecord(player[0]); 
    //outputs readArray2
    for(int i = 0; i < 9; i++)
        cout << readArray2[i];
    
    //frees gameResult's memory
    delete gameResults; 
    //frees readArray1's memory
    delete[] readArray1; 
    //frees readArray2's memory
    delete[] readArray2; 
    
    //exits program
    return 0;
}