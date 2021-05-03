#include "Triangle.h"
#include <cstdlib>
Triangle::Triangle(int row)
{
    szRow = row;
    records = new RowAray*[row];
    szCol = new int[szRow];
    int hold;

    for(int i = 0; i < row; i++)
    {
        hold = rand() % 9 + 1;
        records[i] = new RowAray(hold);
        szCol[i] = hold;
    }
}

Triangle::~Triangle()
{
    delete[] records;
    delete[] indx;
}

Triangle::getData(int row, int col)
{
    return records[row]->getData(col);
}
