#include "Triangle.h"
#include <cstdlib>
Triangle::Triangle(int row)
{
    szRow = row;
    records = new RowAray*[row];
    for(int i = 0; i < row; i++)
        records[i] = new RowAray(i+1);
}

Triangle::~Triangle()
{
    delete[] records;
}

Triangle::getData(int row, int col)
{
    return records[row]->getData(col);
}
