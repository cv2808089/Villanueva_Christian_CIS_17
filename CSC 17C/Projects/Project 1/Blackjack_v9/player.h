#ifndef PLAYER_H
#define PLAYER_H

#include "hand.h"

class player : public Hand
{
private:
    int aceResult;
public:
    void results(int, int, int, int);
    void aceGet();
    int getAceRes()
    {
        return aceResult;
    }
};

#endif /* PLAYER_H */