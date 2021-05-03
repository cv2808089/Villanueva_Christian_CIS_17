#ifndef HAND_H
#define HAND_H

#include "card.h"

class hand
{
protected:
    static int cip;
    int score;
    card cards[10];
    int df21;
public:
    //return card value for array pos
    hand();
    ~hand()
    {};
    
    int getCardsVal(int pos)
    {
        return cards[pos].getCardValue();
    }
    //return card name for array pos
    std::string getCardsNam(int pos)
    {
        return cards[pos].getCardName();
    }
    //return card suit for array pos
    std::string getCardsSu(int pos)
    {
        return cards[pos].getSuit();
    }
    
    //write card value for array pos
    void setCardsVal(int pos, int val)
    {
        cards[pos].setCardValue(val);
    }
    //write card name for array pos
    void setCardsNam(int pos, std::string s)
    {
        cards[pos].setCardName(s);
    }
    //write card suit for array pos
    void setCardsSu(int pos, std::string s)
    {
        cards[pos].setCardSuit(s);
    }
    //draws a card, setting the value, name and suit for a card
    void drawCard(int pos);
    
    //determines whether an ace is worth 1 or 11
    virtual void aceGet(int pos)
    {
        if(cards[pos].getCardValue() == 1 && (score+11 < 21))
        {
            cards[pos].setCardValue(11);
        }
    }
    
    //calculates/ adds to score
    void setScore(int pos)
    {
        score+=cards[pos].getCardValue();
    }
    //returns score
    int getScore()
    {
        return score;
    }
    void setdf21()
    {
        df21 = 21-score;
    }
    
    int getdf21()
    {
        return df21;
    }
    void cippp()
    {
        cip++;
    }
    
    int getCip()
    {
        return cip;
    }
    
    bool operator < (const hand &);
    bool operator > (const hand &);
    bool operator == (const hand &);
};

#endif /* HAND_H */


//
//
//template the destructor
//
//