//holds individual cards

#ifndef CARD_H
#define CARD_H

#include <string>

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
};

#endif /* CARD_H */