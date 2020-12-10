#ifndef MILTIME_H
#define MILTIME_H

#include "time.h"

class milTime : public Time
{
    private:
        int milHours;
        int milSeconds;
    public: 
        milTime(int h, int s) : Time(h/100, h%100, s)
        {
            setTime(h, s);
        }
        class badHour
        {};
        class badSecond
        {};
        void setTime(int, int);
        int getHours()
            { return milHours; }
        int getStandHr();
};


#endif /* MILTIME_H */

