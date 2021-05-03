#include <iostream>
#include <ctime>
using namespace std;

struct card
{
    string val;
    int nv;
    string suit;
};

void getCard(struct card &);
int main()
{
    srand(time(0));
    struct card player[10];
    struct card dealer[10];

    getCard(dealer[0]);
    getCard(dealer[1]);
    getCard(player[0]);
    getCard(player[1]);

    cout << "The dealers shown card is: ";
    cout << dealer[0].val << ' ' << dealer[0].suit << endl;
    cout << "Your cards are: " << endl;
    cout << player[0].val << ' ' << player[0].suit << endl;
    cout << player[1].val << ' ' << player[1].suit << endl;

    return 0;
}

void getCard(struct card &c)
{
    int n = rand() % 13 + 1;
    int s = rand() % 4 + 1;
    switch(n)
    {
        case 1: c.val = "Ace";
                c.nv = 1;
        break;
        case 2: c.val = "Two";
                c.nv = 2;
        break;
        case 3: c.val = "Three";
                c.nv = 3;
        break;
        case 4: c.val = "Four";
                c.nv = 4;
        break;
        case 5: c.val = "Five";
                c.nv = 5;
        break;
        case 6: c.val = "Six";
                c.nv = 6;
        break;
        case 7: c.val = "Seven";
                c.nv = 7;
        break;
        case 8: c.val = "Eight";
                c.nv = 8;
        break;
        case 9: c.val = "Nine";
                c.nv = 9;
        break;
        case 10: c.val = "Ten";
                 c.nv = 10;
        break;
        case 11: c.val = "Jack";
                 c.nv = 10;
        break;
        case 12: c.val = "Queen";
                 c.nv = 10;
        break;
        case 13: c.val = "King";
                c.nv = 10;
        break;
    }
    
    switch(s)
    {
        case 1: c.suit = "Spades";
        break;
        case 2: c.suit = "Clubs";
        break;
        case 3: c.suit = "Diamonds";
        break;
        case 4: c.suit = "Hearts";
        break;
    }
}