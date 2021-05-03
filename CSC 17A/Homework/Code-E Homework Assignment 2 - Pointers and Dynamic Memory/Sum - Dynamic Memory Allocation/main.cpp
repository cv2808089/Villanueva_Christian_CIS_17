#include <iostream>
using namespace std;


int *getData(int &); //Return the array size and the array from the inputs
int *sumAry(const int *,int); //Return the array with successive sums
void prntAry(const int *,int); //Print the array


int main()
{
    int size;
    int *arr;
    int *sarr;
    arr = getData(size);
    prntAry(arr, size);
    cout << endl;
    sarr = sumAry(arr, size);
    prntAry(sarr, size);
    delete[] arr;
    delete[] sarr;
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

int *sumAry(const int *arr,int size)
{
    int *sarr;
    sarr = new int[size];
    sarr[0] = arr[0];
    int sum = arr[0];
    for(int i = 1; i < size; i++)
    {
        sum += arr[i];
        sarr[i] = sum;
    }
    
    return sarr;
}

void prntAry(const int * sarr,int size)
{
    for(int i = 0; i < size-1; i++)
        cout << sarr[i] << ' ';
    cout << sarr[size-1];
}

