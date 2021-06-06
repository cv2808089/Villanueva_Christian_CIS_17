#include "hand.h"
#include "badpos.h"

//draws a card
void Hand::drawCard(std::stack<Card> &deck) 
{
    Card hold;
    hold = deck.top();
    deck.pop();
    cards.push_back(hold);
}

//overrides the < operator for comaring hands
bool Hand::operator < (const Hand &right)
{
        bool res;
        if(score < right.score)
        {
            res = true;
        }
        else 
            res = false;
        return res;
}

//overrides the > operator for comaring hands
bool Hand::operator > (const Hand &right)
{
        bool res;
        if(score > right.score)
        {
            res = true;
        }
        else 
            res = false;
        return res;
}

//overrides the == operator for comaring hands
bool Hand::operator ==(const Hand& right)
{
    bool res;
    if(score == right.score)
    {
        res = true;
    }
    else 
        res = false;
    return res;
}

//constructor for hand
Hand::Hand()
{
    score = 0;
}

int Hand::cip = 0;