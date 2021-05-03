#include <iostream>
using namespace std;

int *getData(int &);//Read the array
int *augment(const int *,int);//Augment and copy the original array
void prntAry(const int *,int);//Print the array


int main()
{
    int size;
    int *arr1;
    int *arr2;
    arr1 = getData(size);
    arr2 = augment(arr1, size);
    
    prntAry(arr1, size);
    cout << endl;
    prntAry(arr2, size);
    
    delete[] arr1;
    delete[] arr2;
    
	return 0;
}

int *getData(int & size)
{
    cin >> size;
    int* arr;
    arr = new int[size];
    
    for(int i = 0; i < size; i++)
        cin >> arr[i];
        
    return arr;
}

int *augment(const int * arr1,int size)
{
    int nsize = size + 1;
    int *arr2;
    arr2 = new int[nsize];
    *arr2 = 0;
    
    for(int i = 1; i < nsize; i++)
    {
        arr2[i] = arr1[i-1];
    }
    
    return arr2;
}

void prntAry(const int * arr,int size)
{
    if(*arr == 0)
        size = size+1;
    for(int i = 0; i < size-1; i++)
        cout << arr[i] << ' ';
    cout << arr[size-1];
}