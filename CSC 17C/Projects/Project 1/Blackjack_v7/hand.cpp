#include "hand.h"

void hand::drawCard(int pos) //draws a card
{
    int n = rand() % 13 + 1; //gets a random number between 1 and 13
    int s = rand() % 4 + 1; //gets a random number between 1 and 4
    switch(n) //assigns a card value and name depending on the random number drawn
    {
        case 1: setCardsNam(pos, "Ace"); //assigns ace for 1
                setCardsVal(pos, 1); //sets card value to 1
                break;
        case 2: setCardsNam(pos, "Two"); //assigns two for 2
                setCardsVal(pos, 2); //sets card value to 2
        break;
        case 3: setCardsNam(pos, "Three"); //assigns three for 3
                setCardsVal(pos, 3); //sets card value to 3
        break;
        case 4: setCardsNam(pos, "Four"); //assigns four for 4
                setCardsVal(pos, 4); //sets card value to 4
        break;
        case 5: setCardsNam(pos, "Five"); //assigns five for 5
                setCardsVal(pos, 5); //sets card value to 5
        break;
        case 6: setCardsNam(pos, "Six"); //assigns six for 6
                setCardsVal(pos, 6); //sets card value to 6
        break;
        case 7: setCardsNam(pos, "Seven"); //assigns seven for 7
                setCardsVal(pos, 7); //sets card value to 7
        break;
        case 8: setCardsNam(pos, "Eight"); //assigns eight for 8
                setCardsVal(pos, 8); //sets card value to 8
        break;
        case 9: setCardsNam(pos, "Nine"); //assigns nine for 9
                setCardsVal(pos, 9); //sets card value to 9
        break;
        case 10: setCardsNam(pos, "Ten"); //assigns ten for 10
                 setCardsVal(pos, 10); //sets card value to 10
        break;
        case 11: setCardsNam(pos, "Jack"); //assigns jack for 11
                 setCardsVal(pos, 10); //sets card value to 10
        break;
        case 12: setCardsNam(pos, "Queen"); //assigns queen for 12
                 setCardsVal(pos, 10); //sets card value to 10
        break;
        case 13: setCardsNam(pos, "King"); //assigns king for 13
                setCardsVal(pos, 10); //sets card value to 10
        break;
    }
    
    switch(s)
    {
        case 1: setCardsSu(pos, "Spades"); //assigns suit to spades for 1
                break;
        case 2: setCardsSu(pos, "Clubs"); //assigns suit to clubs for 2
                break;
        case 3: setCardsSu(pos, "Diamonds"); //assigns suit to diamonds for 3
                break;
        case 4: setCardsSu(pos, "Hearts"); //assigns suit to hearts for 4
                break;
    }
}

bool hand::operator < (const hand &right)
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

bool hand::operator > (const hand &right)
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

bool hand::operator ==(const hand& right)
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

hand::hand()
{
    score = 0;
}

int hand::cip = 0;
