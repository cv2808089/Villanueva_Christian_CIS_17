#ifndef PROB2SORT_H
#define PROB2SORT_H
using namespace std;

#include <cstdlib>

template<class T>
class Prob2Sort
{
	private:
		int *index;                                 //Index that is utilized in the sort
	public:
		Prob2Sort(){index = NULL;};                   //Constructor
		~Prob2Sort(){delete []index;};              //Destructor
		T * sortArray(const T* arr, int col,bool asc)            //Sorts a single column array
                {
                    char temp;
                    char *arr2;
                    arr2 = new char;
                    arr2 = arr;
                    
                    for(int i = 0; i < 10; i++)
                        for(int j = i+1; j < 10; j++)
                            if(arr2[j] < arr2[i] && asc == true)
                            {
                                temp = arr2[i];
                                arr2[i] = arr2[j];
                                arr2[j] = temp;
                            }
                    return arr2;
                };
		T * sortArray(const T* arr,int r,int c,int col,bool asc) //Sorts a 2 dimensional array represented as a 1 dim array
                {
                    char temp;
                    char *arr2;
                    arr2 = new char;
                    for(int i = 0; i < 10; i++)
                        if(arr2[i*16+col] < arr2[(i+1)*16+col] && asc == true)
                        {
                            temp = arr2[i*16+col];
                            arr2[i*16+col] = arr2[(i+1)*16+col];
                            arr2[(i+1)*16+col] = temp;
                        }
                    return arr2;    
                };   
}; 

#endif /* PROB2SORT_H */

