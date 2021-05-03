
#ifndef TABLE_H
#define TABLE_H

#include "RowAray.h"


template<class T>
class Table{
    protected:
        int szRow;
        int szCol;
        RowAray<T> **columns;
    public:
        Table(unsigned int,unsigned int);
        Table(const Table<T> &);
        virtual ~Table();
        int getSzRow()const {return szRow;}
        int getSzCol()const {return szCol;}
        T getData(int,int)const;
        void setData(int,int,T);
        Table<T> operator+(const Table<T> &);
};

template <class T>
Table<T>::Table(unsigned int rows, unsigned int cols)
{
    szRow = rows;
    szCol = cols;
    
    columns = new RowAray<T>*[szRow];
    
    for(int i = 0; i < szRow; i++)
        columns[i] = new RowAray<T>(szCol);
}

template <class T>
Table<T>::Table(const Table<T>& tc)
{
    szRow = tc.getSzRow();
    szCol = tc.getSzCol();
    
    columns = new RowAray<T>*[szRow];
    
    for(int i = 0; i < szRow; i++)
        columns[i] = new RowAray<T>(szCol);
    
    for(int i = 0; i < szRow; i++)
        for(int j = 0; j < szCol; j++)
                columns[i]->setData(j, tc.getData(i, j));
}

template <class T>
Table<T>::~Table()
{
    for(int i = 0; i < szRow; i++)
        delete columns[i];
    
    delete[] columns;
}

template <class T>
T Table<T>::getData(int row, int col) const
{
    return columns[row]->getData(col);
}

template <class T>
void Table<T>::setData(int row, int col, T val)
{
    columns[row]->setData(col, val);
}

template <class T>
Table<T> Table<T>::operator +(const Table<T>& t1)
{
    Table temp(t1.getSzRow(), t1.getSzCol());
    for(int i = 0; i < szRow; i++)
        for(int j = 0; j < szCol; j++)
        {
            temp.setData(i, j, (columns[i]->getData(j) + t1.columns[i]->getData(j)));
        }
    return temp;
}
#endif /* TABLE_H */

