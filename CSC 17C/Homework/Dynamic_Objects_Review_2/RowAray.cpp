#include "RowAray.h"
#include <cstdlib>
RowAray::RowAray(unsigned int s)
{
    size = s;
    rowData = new int[size];
    for(int i = 0; i < size; i++)
        rowData[i] = rand() % 90 + 10;
}

RowAray::~RowAray()
{
    delete[] rowData;
}

void RowAray::setData(int pos, int value)
{
    rowData[pos] = value;
}