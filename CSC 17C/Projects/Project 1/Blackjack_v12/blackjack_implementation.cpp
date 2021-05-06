#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "hand.h"
#include "player.h"
#include "card.h"
#include <iterator>
#include <stack>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

//enum for win condition
enum gameResult{lose, win, draw};

//outputs game results and records the result
gameResult results(int dc, int pc, int dtotal, int ptotal) 
{
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
        cout << "You lose" << endl;
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


stack<Card> formDeck()
{
    vector<Card> deck;
    Card hold;

    //spades
    hold.setCardName("Ace");
    hold.setCardSuit("Spades");
    hold.setCardValue(1);
    deck.push_back(hold);
    
    hold.setCardName("Two");
    hold.setCardSuit("Spades");
    hold.setCardValue(2);
    deck.push_back(hold);
    
    hold.setCardName("Three");
    hold.setCardSuit("Spades");
    hold.setCardValue(3);
    deck.push_back(hold);
    
    hold.setCardName("Four");
    hold.setCardSuit("Spades");
    hold.setCardValue(4);
    deck.push_back(hold);
    
    hold.setCardName("Five");
    hold.setCardSuit("Spades");
    hold.setCardValue(5);
    deck.push_back(hold);
    
    hold.setCardName("Six");
    hold.setCardSuit("Spades");
    hold.setCardValue(6);
    deck.push_back(hold);
    
    hold.setCardName("Seven");
    hold.setCardSuit("Spades");
    hold.setCardValue(7);
    deck.push_back(hold);
    
    hold.setCardName("Eight");
    hold.setCardSuit("Spades");
    hold.setCardValue(8);
    deck.push_back(hold);
    
    hold.setCardName("Nine");
    hold.setCardSuit("Spades");
    hold.setCardValue(9);
    deck.push_back(hold);
    
    hold.setCardName("Ten");
    hold.setCardSuit("Spades");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Jack");
    hold.setCardSuit("Spades");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Queen");
    hold.setCardSuit("Spades");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("King");
    hold.setCardSuit("Spades");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    
    //clubs
    hold.setCardName("Ace");
    hold.setCardSuit("Clubs");
    hold.setCardValue(1);
    deck.push_back(hold);
    
    hold.setCardName("Two");
    hold.setCardSuit("Clubs");
    hold.setCardValue(2);
    deck.push_back(hold);
    
    hold.setCardName("Three");
    hold.setCardSuit("Clubs");
    hold.setCardValue(3);
    deck.push_back(hold);
    
    hold.setCardName("Four");
    hold.setCardSuit("Clubs");
    hold.setCardValue(4);
    deck.push_back(hold);
    
    hold.setCardName("Five");
    hold.setCardSuit("Clubs");
    hold.setCardValue(5);
    deck.push_back(hold);
    
    hold.setCardName("Six");
    hold.setCardSuit("Clubs");
    hold.setCardValue(6);
    deck.push_back(hold);
    
    hold.setCardName("Seven");
    hold.setCardSuit("Clubs");
    hold.setCardValue(7);
    deck.push_back(hold);
    
    hold.setCardName("Eight");
    hold.setCardSuit("Clubs");
    hold.setCardValue(8);
    deck.push_back(hold);
    
    hold.setCardName("Nine");
    hold.setCardSuit("Clubs");
    hold.setCardValue(9);
    deck.push_back(hold);
    
    hold.setCardName("Ten");
    hold.setCardSuit("Clubs");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Jack");
    hold.setCardSuit("Clubs");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Queen");
    hold.setCardSuit("Clubs");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("King");
    hold.setCardSuit("Clubs");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    
    //diamonds
    hold.setCardName("Ace");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(1);
    deck.push_back(hold);
    
    hold.setCardName("Two");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(2);
    deck.push_back(hold);
    
    hold.setCardName("Three");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(3);
    deck.push_back(hold);
    
    hold.setCardName("Four");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(4);
    deck.push_back(hold);
    
    hold.setCardName("Five");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(5);
    deck.push_back(hold);
    
    hold.setCardName("Six");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(6);
    deck.push_back(hold);
    
    hold.setCardName("Seven");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(7);
    deck.push_back(hold);
    
    hold.setCardName("Eight");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(8);
    deck.push_back(hold);
    
    hold.setCardName("Nine");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(9);
    deck.push_back(hold);
    
    hold.setCardName("Ten");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Jack");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Queen");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("King");
    hold.setCardSuit("Diamonds");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    
    //hearts
    hold.setCardName("Ace");
    hold.setCardSuit("Hearts");
    hold.setCardValue(1);
    deck.push_back(hold);
    
    hold.setCardName("Two");
    hold.setCardSuit("Hearts");
    hold.setCardValue(2);
    deck.push_back(hold);
    
    hold.setCardName("Three");
    hold.setCardSuit("Hearts");
    hold.setCardValue(3);
    deck.push_back(hold);
    
    hold.setCardName("Four");
    hold.setCardSuit("Hearts");
    hold.setCardValue(4);
    deck.push_back(hold);
    
    hold.setCardName("Five");
    hold.setCardSuit("Hearts");
    hold.setCardValue(5);
    deck.push_back(hold);
    
    hold.setCardName("Six");
    hold.setCardSuit("Hearts");
    hold.setCardValue(6);
    deck.push_back(hold);
    
    hold.setCardName("Seven");
    hold.setCardSuit("Hearts");
    hold.setCardValue(7);
    deck.push_back(hold);
    
    hold.setCardName("Eight");
    hold.setCardSuit("Hearts");
    hold.setCardValue(8);
    deck.push_back(hold);
    
    hold.setCardName("Nine");
    hold.setCardSuit("Hearts");
    hold.setCardValue(9);
    deck.push_back(hold);
    
    hold.setCardName("Ten");
    hold.setCardSuit("Hearts");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Jack");
    hold.setCardSuit("Hearts");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("Queen");
    hold.setCardSuit("Hearts");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    hold.setCardName("King");
    hold.setCardSuit("Hearts");
    hold.setCardValue(10);
    deck.push_back(hold);
    
    stack<Card> deck2;
    random_shuffle(deck.begin(), deck.end());
    
    for(int i = 0; i < 52; i++)
        deck2.push(deck[i]);
    return deck2;
}

string highCard(Hand d, player p, int dcp, int pcp)
{
    set<int, greater<int>> played;
    for(int i = 0; i < dcp; i++)
        played.insert(d.getCardsVal(i));
    for(int i = 0; i < pcp; i++)
        played.insert(p.getCardsVal(i));
    switch(*played.begin())
    {
        case 1: return "One";
        break;
        case 2: return "Two";
        break;
        case 3: return "Three";
        break;
        case 4: return "Four";
        break;
        case 5: return "Five";
        break;
        case 6: return "Six";
        break;
        case 7: return "Seven";
        break;
        case 8: return "Eight";
        break;
        case 9: return "Nine";
        break;
        case 10: return "Ten";
        break;
        case 11: return "Eleven";
        break;
        default: return "Error";
    }
    
}

string lowCard(Hand d, player p, int dcp, int pcp)
{
    list<int> played;
    for(int i = 0; i < dcp; i++)
        played.push_back(d.getCardsVal(i));
    for(int i = 0; i < pcp; i++)
        played.push_back(p.getCardsVal(i));
    played.sort();
    switch(*played.begin())
    {
        case 1: return "One";
        break;
        case 2: return "Two";
        break;
        case 3: return "Three";
        break;
        case 4: return "Four";
        break;
        case 5: return "Five";
        break;
        case 6: return "Six";
        break;
        case 7: return "Seven";
        break;
        case 8: return "Eight";
        break;
        case 9: return "Nine";
        break;
        case 10: return "Ten";
        break;
        case 11: return "Eleven";
        break;
        default: return "Error";
    }
}