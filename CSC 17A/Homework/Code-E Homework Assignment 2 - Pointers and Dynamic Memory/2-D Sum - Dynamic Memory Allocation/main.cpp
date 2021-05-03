#include <iostream>
using namespace std;


int **getData(int &,int &);        //Return the 2-D array and its size.
void prntDat(const int* const *,int,int);//Print the 2-D Array
void destroy(int **,int,int);       //Deallocate memory
int sum(const int * const *, int,int);    //Return the Sum


int main()
{
    int row;
    int col;
    int **arr;
    arr = getData(row, col);
    
   prntDat(arr, row, col);
   cout << sum(arr, row, col);
   destroy(arr, row, col);
    
	return 0;
}

int **getData(int & row,int &col)
{
    cin >> row;
    cin >> col;
    int **arr;
    arr = new int*[col];
    
    for(int i = 0; i < col; i++)
        arr[i] = new int[col];
    
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
    return arr;
}

void prntDat(const int* const * arr,int row,int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col-1; j++)
            cout << arr[i][j] << ' ';
        cout << arr[i][col-1];
        cout << endl;
    }
}

void destroy(int ** arr,int row,int col)
{
    for(int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}

int sum(const int * const * arr, int row,int col)
{
    int sum = 0;
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            sum+=arr[i][j];
    
    return sum;
}


