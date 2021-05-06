#ifndef HAND_H
#define HAND_H

#include "card.h"
#include <list>
#include <iterator>
#include <stack>
class Hand
{
protected:
    //cards in play
    static int cip; 
    //total value of cards in hand
    int score;
    //linked list of cards
    std::list<Card> cards;
    //difference from 21
    int df21;
public:
    //return card value for array pos
    Hand();
    ~Hand()
    {};
    
    Card getCard(int pos)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        return *it;
    }
    
    int getCardsVal(int pos)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        
        return it->getCardValue();
    }
    //return card name for array pos
    std::string getCardsNam(int pos)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        return it->getCardName();
    }
    //return card suit for array pos
    std::string getCardsSu(int pos)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        return it->getSuit();
    }
    
    //write card value for array pos
    void setCardsVal(int pos, int val)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        it->setCardValue(val);
    }
    //write card name for array pos
    void setCardsNam(int pos, std::string s)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        it->setCardName(s);
    }
    //write card suit for array pos
    void setCardsSu(int pos, std::string s)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        it->setCardSuit(s);
    }
    //draws a card, setting the value, name and suit for a card
    void drawCard(std::stack<Card> &);
    
    //determines whether an ace is worth 1 or 11
    virtual void aceGet(int pos)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        if(it->getCardValue() == 1 && (score+11 <= 21))
        {
            it->setCardValue(11);
        }
    }
    
    //calculates/ adds to score
    void setScore(int pos)
    {
        std::list<Card>:: iterator it = cards.begin();
        advance(it, pos);
        score+=it->getCardValue();
    }
    //returns score
    int getScore()
    {
        return score;
    }
    //finds the difference in score from 21
    void setdf21()
    {
        df21 = 21-score;
    }
    //returns difference from 21
    int getdf21()
    {
        return df21;
    }
    //increments total cards in play
    void cippp()
    {
        cip++;
    }
    //returns cards in play
    int getCip()
    {
        return cip;
    }
    
    bool operator < (const Hand &);
    bool operator > (const Hand &);
    bool operator == (const Hand &);
};

#endif /* HAND_H */