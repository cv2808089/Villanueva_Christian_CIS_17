#include <fstream>
#include <iostream>
using namespace std;


void tf(string, int *, int);
void ta(string, int *, int);


int main()
{
    int arr1[6] = {1, 2, 3, 4, 5, 6};
    int arr2[6];

    tf("file1.bin", arr1, sizeof(arr1));
    ta("file1.bin", arr2, sizeof(arr1));

    cout << "The contents of the array is " << endl;
    for(int i = 0; i < 6; i++)
        cout << arr2[i] << ", ";

    return 0;
}

void tf(string file, int *arr, int size)
{
    fstream out(file, ios::out | ios::binary);
    out.write(reinterpret_cast<char  *>(arr), size);
    out.close();
}

void ta(string file, int *arr, int size)
{
    fstream in(file, ios::in | ios::binary);
    in.read(reinterpret_cast<char *>(arr), size);
    in.close();
}