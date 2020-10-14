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
    string choice;
    int dtotal;
    int ptotal;
    int dc;
    int pc;
    

    getCard(dealer[0]);
    getCard(dealer[1]);
    getCard(player[0]);
    getCard(player[1]);
    
    cout << "The dealers shown card is: ";
    cout << dealer[0].val << ' ' << dealer[0].suit << endl;
    cout << "Your cards are: " << endl;
    cout << player[0].val << ' ' << player[0].suit << endl;
    cout << player[1].val << ' ' << player[1].suit << endl;
    
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
        ptotal = player[0].nv + player[1].nv;
        cout << "The Dealer's second card is: " << endl;
        cout << dealer[1].val << ' ' << dealer[1].suit << endl;
        int dh = 2;
        dtotal = dealer[0].nv + dealer[1].nv;
        
        while(dtotal <= 16)
        {
            cout << "The dealer draws a card" << endl;
            getCard(dealer[dh]);
            if(dealer[dh].nv == 1)
                if(dtotal + 11 <= 21)
                    dtotal += 10;
            cout << "The next card is " << endl;
            cout << dealer[dh].val << ' ' << dealer[dh].suit << endl;
            dtotal += dealer[dh].nv;
            dh++;
        }  
    }
    int ph = 2;
    int ac;
    if(choice == "hit")
    {
        ptotal = player[0].nv + player[1].nv;
        while(choice == "hit")
        {
            getCard(player[ph]);
            cout << "You drew " << player[ph].val << ' ' << player[ph].suit << endl;
            if(player[ph].nv == 1)
            {
                cout << "Would you like the Ace to be worth 1 or 11?" << endl;
                cin >> ac;
                while(ac != 1 && ac != 11)
                {
                    cin.clear();
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
        
        cout << "The Dealer's second card is: " << endl;
        cout << dealer[1].val << ' ' << dealer[1].suit << endl;
        int dh = 2;
        dtotal = dealer[0].nv + dealer[1].nv;
        while(dtotal <= 16)
        {
            cout << "The dealer draws a card" << endl;
            getCard(dealer[dh]);
            if(dealer[dh].nv == 1)
                if(dtotal + 11 <= 21)
                    dtotal += 10;
            cout << "The next card is " << endl;
            cout << dealer[dh].val << ' ' << dealer[dh].suit << endl;
            dtotal += dealer[dh].nv;
            dh++;
        }  
    }
    dc = 21-dtotal;
    pc = 21-ptotal;
    cout << "Dealer's " << dtotal << " vs " << "Player's " << ptotal << endl;
    if(dc == 0 && pc == 0)
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
