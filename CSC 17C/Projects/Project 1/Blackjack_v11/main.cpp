#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "hand.h"
#include "card.h"
#include "player.h"
#include "badchoice.h"
#include "badpos.h"
#include <vector>
#include <iterator>
#include <stack>
#include <set>
#include <map>
#include <queue>

using namespace std;

//game can either end in win, loss, or a draw
enum gameResult{lose, win, draw};

//draws a card
void drawCard(Card &); 
//gets the value of ace that the player decides
int aceGet(); 
//outputs game results and records the result
char *binaryFileManip(string, char *, int); 
//writes a card structure to a binary file
void binaryRecord(Card); 
//outputs results and sets win condition
gameResult results(int, int, int, int);

stack<Card> formDeck();

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
    //number of dealer cards played
    int dcp = 0; 
    //number of player cards played
    int pcp = 0; 
    //Holds the player's choice for the value of an ace
    int aceChoice; 
    //holds the result of the game
    gameResult winc;
    
    stack<Card> deck = formDeck();

    //gets the first dealer card
    try
    {
        dealer.drawCard(deck);
    }
    catch(Badpos)
    {
        cout << "Error, invalid number of cards in hand" << endl;
        cout << "This shouldn't even be possible" << endl;
        return 0;
    }
    
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
    try
    {
        dealer.drawCard(deck);
    }
    catch(Badpos)
    {
        cout << "Error, invalid number of cards in hand" << endl;
        cout << "This shouldn't even be possible" << endl;
        return 0;
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
    try
    {
        p1.drawCard(deck);
    }
    catch(Badpos)
    {
        cout << "Error, invalid number of cards in hand" << endl;
        cout << "This shouldn't even be possible" << endl;
        return 0;
    }
    
    
    //increment cards in play
    pcp++; 
    dealer.cippp();
    
    //gets players second card and checks/replaces repeats
    try
    {
        p1.drawCard(deck);
    }
    catch(Badpos)
    {
        cout << "Error, invalid number of cards in hand" << endl;
        cout << "This shouldn't even be possible" << endl;
        return 0;
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
            try
            {
                dealer.drawCard(deck);
            }
            catch(Badpos)
            {
                cout << "Error, invalid number of cards in hand" << endl;
                cout << "This shouldn't even be possible" << endl;
                return 0;
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
            try
            {
                p1.drawCard(deck);
            }
            catch(Badpos)
            {
                cout << "Error, invalid number of cards in hand" << endl;
                cout << "This shouldn't even be possible" << endl;
                return 0;
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
            try
            {
                dealer.drawCard(deck);
            }
            catch(Badpos)
            {
                cout << "Error, invalid number of cards in hand" << endl;
                cout << "This shouldn't even be possible" << endl;
                return 0;
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
    map<int, char> resultMessage; 
    
    //character array to hold game name
    vector<char> gameName = {'b', 'l', 'a', 'c', 'k', 'j', 'a', 'c', 'k'}; 
    //go to line 531 to see iterator in use
    vector<char>::iterator i;
    

    //stores "winner" in resultMessage
    if(winc == win) 
    {
        resultMessage.insert(pair<int, char>(1, 'w'));
        resultMessage.insert(pair<int, char>(2, 'i'));
        resultMessage.insert(pair<int, char>(3, 'n'));
        resultMessage.insert(pair<int, char>(4, 'n'));
        resultMessage.insert(pair<int, char>(5, 'e'));
        resultMessage.insert(pair<int, char>(6, 'r'));
    }
    //stores "loser" in resultMessage
    if(winc == lose) 
    {
        resultMessage.insert(pair<int, char>(1, 'l'));
        resultMessage.insert(pair<int, char>(2, 'o'));
        resultMessage.insert(pair<int, char>(3, 's'));
        resultMessage.insert(pair<int, char>(4, 'e'));
        resultMessage.insert(pair<int, char>(5, 'r'));
    }
    //stores "draw" in result Message
    if(winc == draw) 
    {
        resultMessage.insert(pair<int, char>(1, 'd'));
        resultMessage.insert(pair<int, char>(2, 'r'));
        resultMessage.insert(pair<int, char>(3, 'a'));
        resultMessage.insert(pair<int, char>(4, 'w'));
    }
    
    //writes reaultMessage to array.bin file
    fstream f;
    f.open("array.bin", ios::out | ios::binary);
    map<int, char>::iterator it;
    for(it = resultMessage.begin(); it != resultMessage.end(); it++)
        f << it->second;
    f.close();
    
    
    //outputs winning hand
    cout << endl;
    cout << "The winning hand is: " << endl;
    if(winc == draw)
    {
        cout << "No winning hand" << endl;
        cout << "It was a draw" << endl;
    }
    
    if(winc == win)
    {
        queue<Card> winningHand;
        for(int i = 0; i < pcp; i++)
            winningHand.push(p1.getCard(i));
        while(!winningHand.empty())
        {
            cout << winningHand.front().getCardName() << ' ' << winningHand.front().getSuit()  << endl;
            winningHand.pop();
        }
    }
    if(winc == lose)
    {
        queue<Card> winningHand;
        for(int i = 0; i < dcp; i++)
            winningHand.push(dealer.getCard(i));
        while(!winningHand.empty())
        {
            cout << winningHand.front().getCardName() << ' ' << winningHand.front().getSuit()  << endl;
            winningHand.pop();
        }
    }
    
    cout << endl;
    
    cout << p1.getCip() << " cards were played this game" << endl;
    
    //outputs end message
    cout << endl;
    cout << "Hope you enjoyed ";
    for(i = gameName.begin(); i < gameName.end(); i++)
    {
        cout << *i;
    }
    
    //exits program
    return 0;
}