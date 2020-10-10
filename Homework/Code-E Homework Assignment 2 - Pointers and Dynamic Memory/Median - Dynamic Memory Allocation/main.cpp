#include <iostream>
#include <iomanip>
using namespace std;


int *getData(int &);         //Return the array size and the array
void prntDat(int *,int);    //Print the integer array
float *median(int *,int);  //Fill the median Array with the Float array size, the median, and the integer array data
void prntMed(float *);     //Print the median Array


int main()
{
    int size;
    int *inums = nullptr;
    inums = getData(size);
    prntDat(inums, size);
    float *mar;
    mar = median(inums, size);
    prntMed(mar);
    
    delete[] inums;
    delete[] mar;
    
	return 0;
}

int *getData(int &size)
{
    int *nums;
    nums = new int[size];
    cin >> size;
    for(int i = 0; i < size; i++)
        cin >> nums[i];
    return nums;
}

void prntDat(int *nums, int size)
{
    for(int i = 0; i < size-1; i++)
        cout << nums[i] << ' ';
    cout << nums[size-1];
    cout << endl;
}

float *median(int * nums, int size)
{
    int num[size];
    for(int i = 0; i < size; i++)
        num[i] = nums[i];
    int temp;
    for(int i = 0; i < size-1; i++)
        for(int j = i+1; j < size; j++)
            if(num[j] < num[i])
            {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
            

    int fsize = (size+2);
    float median;
    float*med;
    med = new float[fsize];
    int mc;
    
    if((size)%2 == 0)
    {
         int m1 = (size/2)-1;
        int m2 = size/2;
        median = (num[m1] + num[m2])/2.0;
    }
    else
    {
        mc = (size+1)/2;
        median = num[mc-1];
    }
        
        
    med[0] = fsize;
    med[1] = median;
    int j = 2;
    for(int i = 0; i < size; i++)
    {
        med[j] = nums[i];
        j++;
    }
    return med;
}

void prntMed(float *med)
{   
    int size = med[0];
    cout << med[0] << ' ';
    cout << fixed << showpoint << setprecision(2);
    for(int i = 1; i < size-1; i++)
        cout << med[i] << ' ';
    cout << med[size-1];
}
