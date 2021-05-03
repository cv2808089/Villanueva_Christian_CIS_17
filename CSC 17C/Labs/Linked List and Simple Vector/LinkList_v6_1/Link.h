/*
    Author: Dr. Mark E. Lehr
    Date:   March 29th, 2021  1:12pm
    Purpose:Linked from first principles
 */

#ifndef LINK_H
#define LINK_H

#include <cstdlib>
#include <iostream>

template<class T> 
class Node
{
public:
    T data;
    Node *lnkNext;
    
    Node(T val)
    {
        data = val;
        lnkNext = nullptr;
    }
};

template <class T> 
class Link
{
private:
    Node<T> *head;
public:
    Link()
    {
        head = nullptr;
    }
    
    ~Link();

    void pshFrnt(T);      //Push a link to the front
    void pshBack(T);      //Push a link to the end
    void popFrnt();      //Pull/pop a link from the front
    void popBack();      //Pull/pop a link from the back
    void prntLst();
    void fillLst(int n);

};

template<class T>
Link<T>::~Link()
{
    Node<T> *pos;
    Node<T> *nxt;
    
    pos = head;
    while(pos != NULL)
    {
        nxt = pos->lnkNext;
        delete pos;
        pos = nxt;
    }
}

template<class T>
void Link<T>::pshFrnt(T n)
{
    Node<T> *temp;
    temp = new Node<T>(n);
    temp->lnkNext = head;
    head = temp;
}

template<class T>
void Link<T>::pshBack(T n)
{
    Node<T> *temp;
    Node<T> *nxt;
    temp = new Node<T>(n);
            
    if(!head)
        head = temp;
    else
    {
        nxt = head;
        while(nxt->lnkNext)
            nxt = nxt->lnkNext;
        nxt->lnkNext = temp;
    }
}

template<class T>
void Link<T>::popFrnt()
{
    Node<T> *temp;
    temp = head->lnkNext;
    delete head;
    head = temp;
}

template<class T>
void Link<T>::popBack()
{
    Node<T> *slast = head;
    while(slast->lnkNext->lnkNext != NULL)
    {
        slast = slast->lnkNext;
    }
    delete slast->lnkNext;
    slast->lnkNext = NULL;
}

 
template<class T>
void Link<T>::prntLst()
{
    Node<T> *pos;
    pos = head;
    
    while(pos)
    {
        std::cout << pos->data << std::endl;
        pos=pos->lnkNext;
    }
}

template<class T>
void Link<T>::fillLst(int n)
{ 
    for(int i=1;i<=n;i++)
    {
        pshBack(i);
    }
}

#endif /* LINK_H */