#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "hand.h"
#include "card.h"
#include "player.h"
#include "badchoice.h"
#include <vector>
#include <iterator>

using namespace std;


//game can either end in win, loss, or a draw
enum gameResult{lose, win, draw};

//draws a card
void drawCard(Card &); 
//checks if card has been already been played
int check(Hand, player, string, string, int, int); 
//gets the value of ace that the player decides
int aceGet(); 
//outputs game results and records the result
char *binaryFileManip(string, char *, int); 
//writes a card structure to a binary file
void binaryRecord(Card); 
//outputs results and sets win condition
gameResult results(int, int, int, int);


int main()
{
    //random number seed
    srand(time(0)); 
    //player cards
    player p1; 
    //dealer cards
    Hand dealer;
    //stores hit or stay
    string choice; 
    //either 1 or -1
    int chk; 
    //number of dealer cards played
    int dcp = 0; 
    //number of player cards played
    int pcp = 0; 
    //Holds the player's choice for the value of an ace
    int aceChoice; 
    //holds the result of the game
    gameResult winc;
    
    
    //gets the first dealer card
    dealer.drawCard(dcp);
    //chooses the value of aces to be 11
    if(dealer.getCardsVal(dcp) == 1)
    {
        dealer.aceGet(dcp);
    }
    dealer.setScore(dcp);
    //increment cards in play
    dcp++; 
    dealer.cippp();
    //gets the second dealer card and checks for/replaces repeat cards
    dealer.drawCard(dcp);
    
    chk = check(dealer, p1, dealer.getCardsNam(dcp),dealer.getCardsSu(dcp), dcp+1, pcp);
    if(chk == -1)
    {
        while(chk == -1)
        {
            dealer.drawCard(dcp);
            chk = check(dealer, p1, dealer.getCardsNam(dcp),dealer.getCardsSu(dcp), dcp+1, pcp);
        }
    }
    //if an ace is drawn, 11 is chosen for its value if the dealer's total doesn't exceed 21
    //chooses the value of aces to be 11
    if(dealer.getCardsVal(dcp) == 1)
    {
        dealer.aceGet(dcp);
    }
    
    dealer.setScore(dcp);
    //increment cards in play
    dcp++; 
    dealer.cippp();
    
    //gets player's first card and checks/replaces repeats
    p1.drawCard(pcp);
    
    chk = check(dealer, p1, p1.getCardsNam(pcp),p1.getCardsSu(pcp), dcp+1, pcp);
    while(chk == -1)
    {
        p1.drawCard(pcp);
        chk = check(dealer, p1, p1.getCardsNam(pcp),p1.getCardsSu(pcp), dcp+1, pcp);
    }
    
    //increment cards in play
    pcp++; 
    dealer.cippp();
    
    //gets players second card and checks/replaces repeats
    p1.drawCard(pcp);
    
    chk = check(dealer, p1, p1.getCardsNam(pcp),p1.getCardsSu(pcp), dcp+1, pcp);
    while(chk == -1)
    {
        p1.drawCard(pcp);
        chk = check(dealer, p1, p1.getCardsNam(pcp),p1.getCardsSu(pcp), dcp+1, pcp);
    }
    
    //increment cards in play
    pcp++; 
    dealer.cippp();
    
    //outputs the first dealer card and the two player cards
    cout << "The dealers shown card is: ";
    cout << dealer.getCardsNam(0) << ' ' << dealer.getCardsSu(0) << endl << endl;
    cout << "Your cards are: " << endl;
    cout << p1.getCardsNam(0) << ' ' << p1.getCardsSu(0) << endl;
    cout << p1.getCardsNam(1) << ' ' << p1.getCardsSu(1) << endl << endl;
    
    
    //if the player draws a(n) ace(s), gets the players choice of value of either 1 or 11
    if(p1.getCardsVal(0) == 1)
    {
        p1.aceGet();
        aceChoice = p1.getAceRes();
                if(aceChoice == 11)
                {
                    p1.setCardsVal(0,11);
                }
    }
    if(p1.getCardsVal(1) == 1)
    {
        p1.aceGet();
        aceChoice = p1.getAceRes();
                if(aceChoice == 11)
                {
                    p1.setCardsVal(1,11);
                }
    }

    
    //gets the player's choice to draw another card or to keep current cards
    cout << "Would you like to hit or stay?" << endl;
    //exception handling for choices
    try
    {
        cin >> choice;
        if(choice != "hit" && choice != "stay")
        {
            throw BadChoice();
        }
    }
    //if choice is not "hit" or "stay", error is output
    catch(BadChoice)
    {
        cout << "Error, invalid choice" << endl;
        cout << "Play again with some more competence" << endl;
        
        return 0;
    }
    
    
    //executes if choice is "stay"
    if(choice == "stay") 
    {
        cout << endl;
        //finds the player's current total
        p1.setScore(0);
        p1.setScore(1);
        cout << "The Dealer's second card is: " << endl; 
        //outputs dealer's second card
        cout << dealer.getCardsNam(1) << ' ' << dealer.getCardsSu(1) << endl << endl; 
        //finds dealer's current total    
        //only executes if the dealer total is less than or equal to 16 and loops until the dealer total is above 16
        while(dealer.getScore() <= 16) 
        {
            cout << "The dealer draws a card" << endl;
            //gets dealers next card
            dealer.drawCard(dcp);
            
            //checks for/replaces repeat cards
            chk = check(dealer, p1, dealer.getCardsNam(dcp), dealer.getCardsSu(dcp), dcp+1, pcp);
            while(chk == -1)
            {
                dealer.drawCard(dcp);
                chk = check(dealer, p1, dealer.getCardsNam(dcp), dealer.getCardsSu(dcp), dcp+1, pcp);
            }
            
            //if an ace is drawn, 11 is chosen for its value if the dealer's total doesn't exceed 21
            if(dealer.getCardsVal(dcp) == 1)
            {
                dealer.aceGet(dcp);
            }
            
            //adds the card value to their total
            dealer.setScore(dcp);         
                       
            
            cout << "The next card is " << endl;
            //outputs the dealer's next card
            cout << dealer.getCardsNam(dcp) << ' ' << dealer.getCardsSu(dcp) << endl << endl; 

            //iterates the number of dealer cards in play
            dcp++;  
            dealer.cippp();
        }  
    }

    
    //only executes if choice is "hit"
    if(choice == "hit") 
    {
        //finds the player's current total
        p1.setScore(0);
        p1.setScore(1);
        //only executes if choice is "hit" and loops until choice is "stay"
        while(choice == "hit") 
        {
            //gets player's next card
            p1.drawCard(pcp);
            
            //checks for /replaces repeat cards
            chk = check(dealer, p1, p1.getCardsNam(pcp), dealer.getCardsSu(pcp), dcp+1, pcp);
            while(chk == -1)
            {
                p1.drawCard(pcp);
                chk = check(dealer, p1, p1.getCardsNam(pcp), dealer.getCardsSu(pcp), dcp+1, pcp);
            }
            //outputs the player's drawn card
            cout << "You drew " << p1.getCardsNam(pcp) << ' ' << p1.getCardsSu(pcp) << endl; 
            
            //if the player draws an ace, gets the players choice of value of either 1 or 11
            if(p1.getCardsVal(pcp) == 1)
            {
                p1.aceGet();
                aceChoice = p1.getAceRes();
                if(aceChoice == 11)
                {
                    p1.setCardsVal(pcp,11);
                }
            }
            
            //adds the card value to the player total
            p1.setScore(pcp);
            
            //iterates the number of player cards in play
            pcp++; 
            dealer.cippp();
            
            //makes choice "stay" if their total reaches or exceeds 21
            if(p1.getScore() >= 21) 
                choice = "stay"; 
            
            //only executes if the player total is less than 21
            if(p1.getScore() < 21) 
            {
                //gets the player's choice to draw another card or to keep current cards
                cout << "Would you like to hit or stay?" << endl; 
                try
                {
                    cin >> choice;
                    if(choice != "hit" && choice != "stay")
                    {
                        throw BadChoice();
                    }
                }
                //if choice is not "hit" or "stay", error is output
                catch(BadChoice)
                {
                    cout << "Error, invalid choice" << endl;
                    cout << "Play again with some more competence" << endl;
                    
                    return 0;
                }  
            }
        }
        
        
        cout << endl;
        cout << "The Dealer's second card is: " << endl; 
        //outputs dealer's second card
        cout << dealer.getCardsNam(1) << ' ' << dealer.getCardsSu(1) << endl << endl; 
        
        //only executes if the dealer total is less than or equal to 16 and loops until the dealer total is above 16
        while(dealer.getScore() <= 16) 
        {
            cout << "The dealer draws a card" << endl;
            //gets dealers next card
            dealer.drawCard(dcp);
            
            //checks for/replaces repeat cards
            chk = check(dealer, p1, dealer.getCardsNam(dcp), dealer.getCardsSu(dcp), dcp+1, pcp);
            while(chk == -1)
            {
                dealer.drawCard(dcp);
                chk = check(dealer, p1, dealer.getCardsNam(dcp), dealer.getCardsSu(dcp), dcp+1, pcp);
            }
            
            //if an ace is drawn, 11 is chosen for its value if the dealer's total doesn't exceed 21
            if(dealer.getCardsVal(dcp) == 1)
            {
                dealer.aceGet(dcp);
            }
            
            //adds the card value to their total
            dealer.setScore(dcp);         
                       
            
            cout << "The next card is " << endl;
            //outputs the dealer's next card
            cout << dealer.getCardsNam(dcp) << ' ' << dealer.getCardsSu(dcp) << endl << endl; 

            //iterates the number of dealer cards in play
            dcp++; 
            dealer.cippp();
        }  
    }    

    
    //finds the difference of dealer's total and 21
    dealer.setdf21();
    //finds the difference of player's total and 21
    p1.setdf21();
    
    //outputs the results of the game and sets the win condition
    winc = results(dealer.getdf21(), p1.getdf21(), dealer.getScore(), p1.getScore());
    
    //character array to hold the result message
    char resultMessage[7]; 
    
    //character array to hold game name
    vector<char> gameName = {'b', 'l', 'a', 'c', 'k', 'j', 'a', 'c', 'k'}; 
    vector<char>::iterator i;
    
    //pointer to hold copy of result message
    char *readArray1; 
    readArray1 = new char;
    //pointer to hold copy of game name
    char *readArray2; 
    readArray2 = new char;
    
    //stores "winner" in resultMessage
    if(winc == win) 
    {
        resultMessage[0] = 'w';
        resultMessage[1] = 'i';
        resultMessage[2] = 'n';
        resultMessage[3] = 'n';
        resultMessage[4] = 'e';
        resultMessage[5] = 'r';
    }
    //stores "loser" in resultMessage
    if(winc == lose) 
    {
       resultMessage[0] = 'l';
       resultMessage[1] = 'o';
       resultMessage[2] = 's';
       resultMessage[3] = 'e';
       resultMessage[4] = 'r';
    }
    //stores "draw" in result Message
    if(winc == draw) 
    {
       resultMessage[0] = 'd';
       resultMessage[1] = 'r';
       resultMessage[2] = 'a';
       resultMessage[3] = 'w';
    }
    
    //writes reaultMessage to array.bin file and copies it to readArray1
    readArray1 = binaryFileManip("array.bin", resultMessage, sizeof(resultMessage)); 
    
    cout << p1.getCip() << " cards were played this game" << endl;
    
    //outputs end message
    cout << endl;
    cout << "Hope you enjoyed ";
    for(i = gameName.begin(); i < gameName.end(); i++)
    {
        cout << *i;
    }
    

    //frees readArray1's memory
    delete[] readArray1; 
    //frees readArray2's memory
    delete[] readArray2; 
    
    
    //exits program
    return 0;
}