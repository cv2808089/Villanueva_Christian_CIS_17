#include <iostream>
using namespace std;


int *getData(int &);               //Fill the array
int *sort(const int *,int);         //Sort smallest to largest
int *reverse(const int *,int);  //Sort in reverse order
void prntDat(const int *,int); //Print the array


int main()
{
    int size;
    int *arr;
    int *sarr;
    int *rarr;
    
    arr = getData(size);
    
    sarr = sort(arr, size);
    prntDat(sarr, size);
    
    rarr = reverse(sarr, size);
    prntDat(rarr, size);
    
    delete[] arr;
    delete[] sarr;
    delete[] rarr;
	return 0;
}

int *getData(int &size)
{
    cin >> size;
    int *arr;
    arr = new int[size];
    for(int i = 0; i < size; i++)
        cin >> arr[i];
        
    return arr;
}

int *sort(const int * arr,int size)
{
    int temp;
    int *sarr;
    sarr = new int[size];
    
    for(int i = 0; i < size; i++)
        sarr[i] = arr[i];
        
    for(int i = 0; i < size-1; i++)
        for(int j = i+1; j < size; j++)
            if(sarr[j] < sarr[i])
            {
                temp = sarr[i];
                sarr[i] = sarr[j];
                sarr[j] = temp;
            }
            
    return sarr;
}

int *reverse(const int *sarr,int size)
{
    int temp;
    int *rarr;
    rarr = new int[size];
    
    for(int i = 0; i < size; i++)
        rarr[i] = sarr[i];
        
    for(int i = 0; i < size-1; i++)
        for(int j = i+1; j < size; j++)
            if(rarr[j] > rarr[i])
            {
                temp = rarr[i];
                rarr[i] = rarr[j];
                rarr[j] = temp;
            }
            
    return rarr;
}

void prntDat(const int * arr,int size)
{
    for(int i = 0; i < size-1; i++)
        cout << arr[i] << ' ';
    if(arr[0] < arr[size-1])
        cout << arr[size-1] << endl;
    else
        cout << arr[size-1];
}


