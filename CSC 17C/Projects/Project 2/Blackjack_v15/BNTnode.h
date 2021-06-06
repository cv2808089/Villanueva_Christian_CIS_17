/* 
 * File:   BNTnode.h
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-avl-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  A binary tree node
 */

#ifndef BNTNODE_H
#define	BNTNODE_H

template<class T>
class BNTnode
{
public:  
    T data;
    BNTnode *left;
    BNTnode *right;
    BNTnode()
    {};
    BNTnode(T val)
    {
        data = val;
    }
};

#endif	/* BNTNODE_H */