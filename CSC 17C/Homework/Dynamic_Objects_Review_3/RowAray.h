#ifndef ROWARAY_H
#define ROWARAY_H

template<class T>
class RowAray{
    protected:
        int size;
        T *rowData;
    public:
        RowAray(int);
        virtual ~RowAray();
        int getSize()const{return size;}
        T getData(int i)const{
            if(i>=0&&i<size)return rowData[i];
            else return 0;}
        void setData(int,T);
};

template <class T>
RowAray<T>::RowAray(int s)
{
    size = s;
    rowData = new T[size];
    
    for(int i = 0; i < size; i++)
        rowData[i] = rand() % 90 + 10;
}

template <class T>
RowAray<T>::~RowAray()
{
    delete[] rowData;
}

template <class T>
void RowAray<T>::setData(int pos, T val)
{
    rowData[pos] = val;
}

#endif /* ROWARAY_H */

