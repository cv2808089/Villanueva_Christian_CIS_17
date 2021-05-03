#include "hand.h"
#include "badpos.h"

//draws a card
void Hand::drawCard(int pos) 
{
    if(pos > 14)
    {
       throw Badpos();
    }
    //gets a random number between 1 and 13
    int n = rand() % 13 + 1; 
    //gets a random number between 1 and 4
    int s = rand() % 4 + 1; 
    //assigns a card value and name depending on the random number drawn
    switch(n) 
    {
        //assigns ace for 1
        case 1: setCardsNam(pos, "Ace"); 
        //sets card value to 1
                setCardsVal(pos, 1); 
                break;
        //assigns two for 2
        case 2: setCardsNam(pos, "Two"); 
        //sets card value to 2
                setCardsVal(pos, 2); 
        break;
        //assigns three for 3
        case 3: setCardsNam(pos, "Three"); 
                setCardsVal(pos, 3); 
        break;
        //assigns four for 4
        case 4: setCardsNam(pos, "Four"); 
        //sets card value to 4
                setCardsVal(pos, 4); 
        break;
        //assigns five for 5
        case 5: setCardsNam(pos, "Five"); 
        //sets card value to 5
                setCardsVal(pos, 5); 
        break;
        //assigns six for 6
        case 6: setCardsNam(pos, "Six"); 
        //sets card value to 6
                setCardsVal(pos, 6); 
        break;
        //assigns seven for 7
        case 7: setCardsNam(pos, "Seven"); 
        //sets card value to 7
                setCardsVal(pos, 7); 
        break;
        //assigns eight for 8
        case 8: setCardsNam(pos, "Eight"); 
        //sets card value to 8
                setCardsVal(pos, 8); 
        break;
        //assigns nine for 9
        case 9: setCardsNam(pos, "Nine"); 
        //sets card value to 9
                setCardsVal(pos, 9); 
        break;
        //assigns ten for 10
        case 10: setCardsNam(pos, "Ten"); 
        //sets card value to 10
                 setCardsVal(pos, 10); 
        break;
        //assigns jack for 11
        case 11: setCardsNam(pos, "Jack"); 
        //sets card value to 10
                 setCardsVal(pos, 10); 
        break;
        //assigns queen for 12
        case 12: setCardsNam(pos, "Queen"); 
        //sets card value to 10
                 setCardsVal(pos, 10); 
        break;
        //assigns king for 13
        case 13: setCardsNam(pos, "King"); 
        //sets card value to 10
                setCardsVal(pos, 10); 
        break;
    }
    
    switch(s)
    {
        //assigns suit to spades for 1
        case 1: setCardsSu(pos, "Spades"); 
                break;
        //assigns suit to clubs for 2
        case 2: setCardsSu(pos, "Clubs"); 
                break;
        //assigns suit to diamonds for 3
        case 3: setCardsSu(pos, "Diamonds"); 
                break;
        //assigns suit to hearts for 4
        case 4: setCardsSu(pos, "Hearts"); 
                break;
    }
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