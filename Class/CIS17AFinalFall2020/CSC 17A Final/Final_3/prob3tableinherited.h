#ifndef PROB3TABLEINHERITED_H
#define PROB3TABLEINHERITED_H

#include "prob3table.h"
#include<fstream>
using namespace std;

template<class T>
class Prob3TableInherited:public Prob3Table<T>
{
	protected:
		T *augTable;                                  //Augmented Table with sums
	public:
		Prob3TableInherited(char *txt, int r, int c)//Constructor
                {
                    rows = r;
                    cols = c;
                    colSum=0;
                    rowSum = 0;
                    fstream in;
                    in.open(txt, ios::in);
                    in.get(*table);
                    in.close();
                    
                    calcTable();
                    rows = r+1;
                    cols = c+1;
                    
                    augTable = table;
                    for(int i = 1; i <= rows; i++)
                    {
                        augTable[cols*i] = rowSum[i-1];
                    }
                    for(int i = 1; i < cols; i++)
                    {
                        augTable[rows*cols-i] = colSum[cols-i];
                    }
                    augTable[rows*cols] = getGrandTotal();
                };          
		~Prob3TableInherited(){delete [] augTable;};  //Destructor
		const T *getAugTable(void){return augTable;}; 
};

#endif /* PROB3TABLEINHERITED_H */

