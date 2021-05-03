#include "RowAray.h"
#include <cstdlib>

RowAray::RowAray(int cols)
{
    size = cols;
    rowData = new int[cols];
    for(int i = 0 ; i < cols; i++)
        rowData[i] = rand() % 90 + 10;
}

RowAray::~RowAray()
{
    delete[] rowData;
}
