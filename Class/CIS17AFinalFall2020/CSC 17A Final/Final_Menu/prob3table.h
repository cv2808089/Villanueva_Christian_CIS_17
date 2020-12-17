#ifndef PROB3TABLE_H
#define PROB3TABLE_H

#include<fstream>
using namespace std;

template<class T>
class Prob3Table
{
	protected:
		int rows;                                 //Number of rows in the table
		int cols;                                 //Number of cols in the table
		T *rowSum;                                //RowSum array
		T *colSum;                                //ColSum array
		T *table;                                 //Table array
		T grandTotal;                             //Grand total
		void calcTable(void)
                {
                    for(int i = 0; i < rows; i++)
                        for(int j = 0; j < cols; j++)
                        {
                            rowSum[i] += table[i*cols+j];
                        }
                    for(int i = 0; i < cols; i++)
                        for(int j = 0; j < rows; j++)
                        {
                            colSum[i] += table[i*rows+j];
                        }
                    int rts = 0;
                    int cts = 0;
                    for(int i = 0; i < rows; i++)
                        rts += rowSum[i];
                    for(int i = 0; i < cols; i++)
                        cts += colSum[i];
                    grandTotal = rts + cts;
                };                     //Calculate all the sums
	public:
		Prob3Table(char *txt,int r,int c)                //Constructor then Destructor
                {
                    fstream in;
                    in.open(txt, ios::in);
                    in.get(*table);
                    in.close();
                    rows = r;
                    cols = c;
                    calcTable();
                };               
		~Prob3Table(){delete [] table;delete [] rowSum;delete [] colSum;};
		const T *getTable(void){return table;};
		const T *getRowSum(void){return rowSum;};
		const T *getColSum(void){return colSum;};
		T getGrandTotal(void){return grandTotal;};
};

#endif /* PROB3TABLE_H */

