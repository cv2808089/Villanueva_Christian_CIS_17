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
    Node *prev;
    
    Node(T val)
    {
        data = val;
        lnkNext = NULL;
        prev = NULL;
    }
};

template <class T> 
class Link
{
private:
    Node<T> *head;
    Node<T> *tail;
    int numNodes = 0;
public:
    Link()
    {
        head = NULL;
        tail = NULL;
    }
    
    ~Link();

    void pshFrnt(T);      //Push a link to the front
    void pshBack(T);      //Push a link to the end
    void popFrnt();      //Pull/pop a link from the front
    void popBack();      //Pull/pop a link from the back
    void prntLst();
    void fillLst(int n);
    void insert_before(T, int);
    void insert_after(T, int);
    void del(int);
    void sort();
    void find(T);
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

template <class T>
void Link<T>::insert_before(T val, int pos)
{
    if(pos < 1)
        pshFrnt(val);
    else
    {
    Node<T> *temp = head;
    Node<T> *nn = new Node<T>(val);
    for(int i = 0; i < pos-1; i++)
        temp = temp->lnkNext;
    nn->prev = temp->prev;
    temp->prev->lnkNext = nn;
    nn->lnkNext = temp;
    temp->prev = nn;
    numNodes++;
    }
}

template <class T>
void Link<T>::insert_after(T val, int pos)
{
    Node<T> *temp = head;
    Node<T> *nn = new Node<T>(val);
    for(int i = 0; i < pos; i++)
        temp = temp->lnkNext;
    nn->prev = temp->prev;
    temp->prev->lnkNext = nn;
    nn->lnkNext = temp;
    temp->prev = nn;
    numNodes++;
}

template<class T>
void Link<T>::del(int pos)
{
    if(pos < 1)
        popFrnt();
    else if(pos >= numNodes)
        popBack();
    else
    {
        Node<T> *temp = head;
        for(int i = 0; i < pos-1; i++)
            temp = temp->lnkNext;
        temp->prev->lnkNext = temp->lnkNext;
        temp->lnkNext->prev = temp->prev;
        delete temp;
        numNodes--;
    }
}

template<class T>
void Link<T>::pshFrnt(T n)
{
    Node<T> *temp;
    temp = new Node<T>(n);
    temp->lnkNext = head;
    head->prev = temp;
    head = temp;
    numNodes++;
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
        tail = temp;
        temp->prev = nxt;
    }
    numNodes++;
}

template<class T>
void Link<T>::popFrnt()
{
    Node<T> *temp;
    temp = head->lnkNext;
    delete head;
    head = temp;
    head->prev = NULL;
    numNodes--;
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
    numNodes--;
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

template<class T>
void Link<T>::sort()
{
    Node<T> *temp = head;
    Node<T> *temp2 = temp->lnkNext;
    T hold;
    for(int i = 0; i < numNodes; i++) 
    {
        while(temp2 != NULL)
        {
            if(temp->data < temp2->data)
            {
                hold = temp->data;
                temp->data = temp2->data;
                temp2->data = hold;
            }
            temp2 = temp2->lnkNext;
        }
        temp2 = head;
        temp = temp->lnkNext;
    }
}

template<class T>
void Link<T>::find(T val)
{
    Node<T> *temp = head;
    int pos = 0;
    bool found = false;
    while(temp != NULL && found == false)
    {
        if(temp->data == val)
        {
            pshFrnt(val);
            del(pos+2);
            found = true;
        }
        else
        {
            pos++;
            temp = temp->lnkNext;
        }
    }
    if(found == false)
        cout << "Value not found" << endl;
    else
        cout << "Found at position: " << pos << endl;
}
#endif /* LINK_H */