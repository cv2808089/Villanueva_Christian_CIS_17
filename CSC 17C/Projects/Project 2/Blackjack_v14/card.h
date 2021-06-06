//holds individual cards

#ifndef CARD_H
#define CARD_H

#include <string>
#include <iostream>
class Card
{
private:
    std::string cardName;
    int cardValue;
    std::string suit;
public:
    int getCardValue()
    {
        return cardValue;
    }
    std::string getCardName()
    {
        return cardName;
    }
    std::string getSuit()
    {
        return suit;
    }
    void setCardValue(int n)
    {
        cardValue = n;
    }
    void setCardName(std::string n)
    {
        cardName = n;
    }
    void setCardSuit(std::string s)
    {
        suit = s;
    }
    bool operator < (const Card &right)
    {
        bool lt;
        if(cardValue < right.cardValue)
            lt = true;
        else lt = false;
        
        return lt;
    }
    bool operator >= (const Card &right)
    {
        bool lt;
        if(cardValue > right.cardValue || cardValue == right.cardValue)
            lt = true;
        else lt = false;
        
        return lt;
    }
    friend std::ostream &operator << (std::ostream &stream, const Card &c)
    {
        stream << c.cardName << ' ' << c.suit;
        return stream;
    }
};

#endif /* CARD_H */