#include "prob1random.h"
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

Prob1Random::Prob1Random(const char ns, const char *s)
{
    nset = ns;
    set = new char[nset];
    freq = new int[nset];
    for(int i = 0; i < nset; i++)
        set[i] = s[i];
    numRand = 0;
}

Prob1Random::~Prob1Random()
{
    delete[] set;
    delete[] freq;
}

char Prob1Random::randFromSet()
{
    char val;
    int pos = rand() % nset;
    freq[pos] += 1;
    numRand++;
    hold[counter] = pos;
    counter++;
    val = set[pos];
    return val;
}

int *Prob1Random::getFreq() const
{
    for(int i=0; i<nset; i++)
        for(int j=0; j<numRand; j++)
            if(i==hold[j])
                freq[i]++;
        
    return freq;
}

char *Prob1Random::getSet() const
{
    return set;
}

int Prob1Random::getNumRand() const
{
    return numRand;
}