#include "Table.h"

Table::Table(int row, int col)
{
    szRow = row;
    szCol = col;
    
    records = new RowAray*[row];
    for(int i = 0; i < row; i++)
        records[i] = new RowAray(col);
}

Table::~Table()
{
    delete[] records;
}

int Table::getData(int row, int col)
{
    return records[row]->getData(col);
}