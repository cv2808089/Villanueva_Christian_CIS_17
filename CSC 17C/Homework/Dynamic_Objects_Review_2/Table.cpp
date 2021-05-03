
#include "Table.h"
#include <iostream>
Table::Table(unsigned int row, unsigned int col)
{
    szRow = row;
    szCol = col;
    columns = new RowAray*[row];
    
    for(int i = 0; i < row; i++)
    {
        columns[i] =  new RowAray(col);
    }
}

Table::Table(const Table& t1)
{
    szRow = t1.getSzRow();
    szCol = t1.getSzCol();
    columns = new RowAray*[szRow];
    
    for(int i = 0; i < szRow; i++)
        columns[i] = new RowAray(szCol);
    
    for(int i = 0; i < szRow; i++)
        for(int j = 0; j < szCol; j++)
            columns[i]->setData(j, t1.columns[i]->getData(j));
    
    
}

Table::~Table()
{
    for(int i = 0; i < szRow; i++)
        delete columns[i];
    
    delete[] columns;
}

Table::getData(int row, int col) const
{
    return columns[row]->getData(col);
}

void Table::setData(int row, int col, int val)
{
    columns[row]->setData(col, val);
}