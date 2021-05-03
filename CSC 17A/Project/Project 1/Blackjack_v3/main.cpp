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
int check(struct card[], struct card[], struct card, int, int);

int main()
{
    srand(time(0));
    struct card player[10];
    struct card dealer[10];
    string choice;
    int dtotal = 0; //total sum of card values for dealer
    int ptotal; //total sum of card values for player
    int dc; //difference from 21 of card total for dealer
    int pc; //difference from 21 of card total for player
    int chk; //either 1 or -1
    int dcp = 0; //number of dealer cards played
    int pcp = 0; //number of player cards played
    int ac; //Holds the player's choice for the value of an ace
    
    getCard(dealer[0]);
    dcp++;
    if(dealer[0].nv == 1)
        dealer[0].nv = 11;
    
    getCard(dealer[1]);
    dcp++;
    chk = check(dealer, player, dealer[1], dcp, pcp);
    if(chk == -1)
    {
        while(chk == -1)
        {
            getCard(dealer[1]);
            chk = check(dealer, player, dealer[1], dcp, pcp);
        }
    }
    if(dealer[0].nv == 1)
        if(dealer[0].nv + 11 <= 21)
            dealer[0].nv = 11;
    
    getCard(player[0]);
    pcp++;
    chk = check(dealer, player, player[0], dcp+1, pcp);
    while(chk == -1)
    {
        getCard(player[0]);
        chk = check(dealer, player, player[0], dcp+1, pcp);
    }
    
    getCard(player[1]);
    pcp++;
    chk = check(dealer, player, player[1], dcp+1, pcp);
    while(chk == -1)
    {
        getCard(player[1]);
        chk = check(dealer, player, player[1], dcp+1, pcp);
    }
    
    cout << "The dealers shown card is: ";
    cout << dealer[0].val << ' ' << dealer[0].suit << endl << endl;
    cout << "Your cards are: " << endl;
    cout << player[0].val << ' ' << player[0].suit << endl;
    cout << player[1].val << ' ' << player[1].suit << endl << endl;
    
    if(player[0].nv ==1)
    {
        cout << "Would you like the Ace to be worth 1 or 11?" << endl;
                cin >> ac;
                while(ac != 1 && ac != 11 && cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a valid choice" << endl;
                    cin >> ac;
                }
                if(ac == 11)
                    player[0].nv = 11;
    }
    if(player[1].nv ==1)
    {
        cout << "Would you like the Ace to be worth 1 or 11?" << endl;
                cin >> ac;
                while(ac != 1 && ac != 11 && cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a valid choice" << endl;
                    cin >> ac;
                }
                if(ac == 11)
                    player[1].nv = 11;
    }

    cout << "Would you like to hit or stay?" << endl;
    cin >> choice;
    while(choice != "hit" && choice != "stay")
    {
        cin.clear();
        cout << "Please enter either hit or stay" << endl;
        cin >> choice;
    }
    
    
    if(choice == "stay")
    {
        cout << endl;
        ptotal = player[0].nv + player[1].nv;
        cout << "The Dealer's second card is: " << endl;
        cout << dealer[1].val << ' ' << dealer[1].suit << endl << endl;
        int dh = 2; //start of new cards for dealer
        dtotal = dealer[0].nv + dealer[1].nv;
        
        while(dtotal <= 16)
        {
            cout << "The dealer draws a card" << endl;
            getCard(dealer[dh]);
            dcp++;
            chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            while(chk == -1)
            {
                getCard(dealer[dh]);
                chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            }
            if(dealer[dh].nv == 1)
                if(dtotal + 11 <= 21)
                    dtotal += 10;
            cout << "The next card is " << endl;
            cout << dealer[dh].val << ' ' << dealer[dh].suit << endl << endl;
            dtotal += dealer[dh].nv;
            dh++;
        }  
    }
    
    
    int ph = 2; //start of new cards for player
    
    if(choice == "hit")
    {
        ptotal = player[0].nv + player[1].nv;
        while(choice == "hit")
        {
            getCard(player[ph]);
            pcp++;
            chk = check(dealer, player, player[ph], dcp+1, pcp);
            while(chk == -1)
            {
                getCard(player[ph]);
                chk = check(dealer, player, player[ph], dcp+1, pcp);
            }
            cout << "You drew " << player[ph].val << ' ' << player[ph].suit << endl;
            if(player[ph].nv == 1)
            {
                cout << "Would you like the Ace to be worth 1 or 11?" << endl;
                cin >> ac;
                while(ac != 1 && ac != 11 && cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "Please enter a valid choice" << endl;
                    cin >> ac;
                }
                if(ac == 11)
                    ptotal += 10;
            }
            ptotal += player[ph].nv;
            if(ptotal >= 21)
                choice = "stay";
            if(ptotal < 21)
            {
                cout << "Would you like to hit or stay?" << endl;
                cin >> choice;
                while(choice != "hit" && choice != "stay")
                {
                    cin.clear();
                    cout << "Please enter either hit or stay" << endl;
                    cin >> choice;
                }
            }
            ph++;
        }
        
        cout << endl;
        cout << "The Dealer's second card is: " << endl;
        cout << dealer[1].val << ' ' << dealer[1].suit << endl << endl;
        int dh = 2; //start of new cards for dealer
        dtotal = dealer[0].nv + dealer[1].nv;
        while(dtotal <= 16)
        {
            cout << "The dealer draws a card" << endl;
            getCard(dealer[dh]);
            dcp++;
            chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            while(chk == -1)
            {
                getCard(dealer[dh]);
                chk = check(dealer, player, dealer[dh], dcp, pcp+1);
            }
            if(dealer[dh].nv == 1)
                if(dtotal + 11 <= 21)
                    dtotal += 10;
            cout << "The next card is " << endl;
            cout << dealer[dh].val << ' ' << dealer[dh].suit << endl << endl;
            dtotal += dealer[dh].nv;
            dh++;
        }  
    }
    
    //finds the difference in totals
    dc = 21-dtotal;
    pc = 21-ptotal;
    
    //Finds and outputs results of game
    cout << "Dealer's " << dtotal << " vs " << "Player's " << ptotal << endl;
    if(dc == 0 && pc == 0 && dc != pc)
        cout << "No winner" << endl;
    if(dc == pc)
        cout << "No winner" << endl;
    if(dc < 0 && pc < 0)
            cout << "No winner" << endl;
    if(dc < 0 && pc >= 0)
    {
        cout << "Dealer busts" << endl;
        cout << "You win" << endl;
    }
    if(dc >= 0 && pc < 0)
    {
        cout << "You bust" << endl;
        cout << "You lose" << endl;
    }
    if(dc < pc && dc >= 0)
        cout << "You lose" << endl;
    if(pc < dc && pc >= 0)
        cout << "You win" << endl;
    
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

int check(struct card d[], struct card p[], struct card c, int dcp, int pcp)
{
    for(int i = 0; i < dcp-1; i++)
        if(c.val == d[i].val && c.suit == d[i].suit)
            return -1;
    if(pcp > 0)
        for(int i = 0; i < pcp-1; i++)
            if(c.val == p[i].val && c.suit == p[i].suit)
                return -1;
    return 1;
}