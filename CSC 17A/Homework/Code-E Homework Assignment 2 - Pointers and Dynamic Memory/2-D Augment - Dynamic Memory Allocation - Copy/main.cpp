#include <iostream>
using namespace std;

int **getData(int &,int &);//Get the Matrix Data
void printDat(const int * const *,int,int);//Print the Matrix
int **augment(const int * const *,int,int);//Augment the original array
void destroy(int **,int);//Destroy the Matrix, i.e., reallocate memory


int main()
{
    int row;
    int col;
    int **arr1;
    int **arr2;
    arr1 = getData(row, col);
    printDat(arr1, row, col);
    cout << endl;
    arr2 = augment(arr1, row, col);
    printDat(arr2, row, col);
    
    destroy(arr1, row);
    destroy(arr2, row);
	return 0;
}
int **getData(int &row, int&col)
{
    cin >> row;
    cin >> col;
    int **arr;
    arr = new int*[col];
    
    for(int i = 0; i < col; i++)
        arr[i] =  new int[col];
        
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            cin >> arr[i][j];
    
    return arr;
}

int **augment(const int * const * arr,int row,int col)
{
    int nrow = row +1;
    int ncol = col+1;
    int **narr;
    narr = new int*[ncol];
    for(int i = 0; i < ncol; i++)
        narr[i] = new int[ncol];
    for(int i = 0; i < ncol; i++)
        narr[0][i] = 0;
    for(int i = 0; i < nrow; i++)
        narr[i][0] = 0;
    for(int i = 1; i < nrow; i++)
        for(int j = 1; j < ncol; j++)
            narr[i][j] = arr[i-1][j-1];
    
    return narr;
}

void printDat(const int * const * arr,int row,int col)
{
    if(arr[0][0] == 0)
    {
        row += 1;
        col += 1;
    }
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(j == col-1)
                cout << arr[i][j];
            else
                cout << arr[i][j] << ' ';
        }
        if(i != row-1)
            cout << endl;
    }
}

void destroy(int ** arr,int row)
{
    for(int i = 0; i < row; i++)
        delete[] arr[i];
    delete[] arr;
}