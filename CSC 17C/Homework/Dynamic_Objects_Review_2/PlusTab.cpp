#include "PlusTab.h"

PlusTab PlusTab::operator +(const PlusTab& t1)
{
    PlusTab temp(t1.getSzRow(), t1.getSzCol());
    for(int i = 0; i < szRow; i++)
        for(int j = 0; j < szCol; j++)
        {
            temp.setData(i, j, (columns[i]->getData(j) + t1.columns[i]->getData(j)));
        }
    return temp;
}