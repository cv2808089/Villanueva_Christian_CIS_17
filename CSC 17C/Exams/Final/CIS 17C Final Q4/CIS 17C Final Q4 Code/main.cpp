#include <iostream>
#include <list>
#include <fstream>
using namespace std;

void merge(short int arr[], int l, int m, int r);
void mergeSort(short int arr[],int l,int r);
void selSort(short int a[],int n);


int opeq = 0, opcomp = 0, opas = 0, opmd = 0, opind = 0;

int main() 
{
    ifstream in;
    short int arr[100000];
    int i = 0;
    in.open("rint.txt");
    while(in)
    {
        in >> arr[i];
        i++;
    }
    //mergeSort(arr, 0, 99999);
    selSort(arr, 4000);
    cout << opeq + opas + opmd + opcomp + opind << endl;
    return 0;
}

void merge(short int arr[], int l, int m, int r)
{
    int n1 = m - l + 1;
    int n2 = r - m;
    opeq+=2; opas += 3;
    // Create temp arrays
    int L[n1], R[n2];
    opeq++;
    // Copy data to temp arrays L[] and R[]
    for (int i = 0; i < n1; i++)
    {
        L[i] = arr[l + i];
        opcomp++; opas+=2; opind+=2;
    }
    opeq++;
    for (int j = 0; j < n2; j++)
    {
        R[j] = arr[m + 1 + j];
        opcomp++; opas+=3; opind+=2;
    }
 
    // Merge the temp arrays back into arr[l..r]
 
    // Initial index of first subarray
    int i = 0;
 
    // Initial index of second subarray
    int j = 0;
 
    // Initial index of merged subarray
    int k = l;
 
    opeq+=3;
    while (i < n1 && j < n2) 
    {
        opcomp+=2;
        opcomp++; opind+=2;
        if (L[i] <= R[j]) 
        {
            opind+=2;opeq++;opas++;
            arr[k] = L[i];
            i++;
        }
        else {
            opind+=2; opeq++;opas++;
            arr[k] = R[j];
            j++;
        }
        k++;
        opas++;
    }
 
    // Copy the remaining elements of
    // L[], if there are any
    opcomp++;
    while (i < n1) 
    {
        opind+=2; opeq++; opas+=2;
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of
    // R[], if there are any
    opcomp++;
    while (j < n2) 
    {
        opind+=2;opeq++;opas+=2;
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// l is for left index and r is
// right index of the sub-array
// of arr to be sorted */
void mergeSort(short int arr[],int l,int r)
{
    opcomp++;
    if(l>=r){
        return;//returns recursively
    }
    opeq++; opas+=2; opmd++;
    int m =l+ (r-l)/2;
    mergeSort(arr,l,m);
    opas++;
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
}

void selSort(short int a[],int n){
    //Loop and declare variables
    int indx,min;
    opeq++;
    for(int pos=0;pos<n-1;pos++)
    {
        opcomp++; opas+=2;
        //Find the smallest in the list, swap after finding
        opind++; opeq+=2;
        min=a[pos];indx=pos;
        opeq++;
        for(int i=pos+1;i<n;i++)
        {
            opcomp++;opas+=2;opind++;opcomp++;
            if(a[i]<min){
                opeq+=2; opind++;
                min=a[i];
                indx=i;
            }
        }
        //Perform the swap
        opind+=3; opeq+=2;
        a[indx]=a[pos];
        a[pos]=min;
    }
}