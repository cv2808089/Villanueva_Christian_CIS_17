/* 
 * File:   BNTnode.h
 * Modified:  from http://www.sanfoundry.com/cpp-program-implement-AVL-trees/
 * Created on May 23, 2021, 9:14 PM
 * Purpose:  An Binary Tree using an AVL balancing technique
 */

#ifndef AVLTREE_H
#define	AVLTREE_H

#include <iostream>
using namespace std;

#include "BNTnode.h"

template <class T>
class AVLTree{
    public:
        BNTnode<T> *root;                   //Root node
        int height(BNTnode<T> *);           //Tree height
        int diff(BNTnode<T> *);             //Difference of right/left subtrees
        BNTnode<T> *rr_rotation(BNTnode<T> *); //Right-Right rotation
        BNTnode<T> *ll_rotation(BNTnode<T> *); //Left-Left   rotation
        BNTnode<T> *lr_rotation(BNTnode<T> *); //Left-Right  rotation
        BNTnode<T> *rl_rotation(BNTnode<T> *); //Right-Left  rotation
        BNTnode<T>* balance(BNTnode<T> *);     //Balance subtrees with diff > 1
        BNTnode<T>* insert(BNTnode<T> *, T);//Insert and balance the tree
        BNTnode<T>* delet(BNTnode<T>*, T);   //Delete and balance the tree
        void display(BNTnode<T> *, int);    //Funky display root left to right
        void inorder(BNTnode<T> *);         //In order display
        void preorder(BNTnode<T> *);        //Pre order display
        void postorder(BNTnode<T> *);       //Post order display
        void levelOrder(BNTnode<T>*);       //level order display
        void prntLev(BNTnode<T>*, int);     //Print nodes at a given level
        AVLTree(){root = NULL;}          //Constructor
        void construct(BNTnode<T> *&, int); //construct
        void cleanUp(BNTnode<T> *);         //delete all nodes
};

//******************************************************************************
//                            Height of AVL Sub Trees
//******************************************************************************
template <class T>
int AVLTree<T>::height(BNTnode<T> *temp){
    int h = 0;
    if (temp != NULL){
        int l_height = height (temp->left);
        int r_height = height (temp->right);
        int max_height = max (l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
 
//******************************************************************************
//                      Height Difference of AVL Sub Trees
//******************************************************************************
template <class T>
int AVLTree<T>::diff(BNTnode<T> *temp){
    int l_height = height (temp->left);
    int r_height = height (temp->right);
    int b_factor= l_height - r_height;
    return b_factor;
}
 
//******************************************************************************
//                      Right-Right Rotations of Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::rr_rotation(BNTnode<T> *parent){
    BNTnode<T> *temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

//******************************************************************************
//                      Left-Left Rotations of Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::ll_rotation(BNTnode<T> *parent){
    BNTnode<T> *temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
 
//******************************************************************************
//                      Left-Right Rotations of Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::lr_rotation(BNTnode<T> *parent){
    BNTnode<T> *temp;
    temp = parent->left;
    parent->left = rr_rotation (temp);
    return ll_rotation (parent);
}
 
//******************************************************************************
//                      Right-Left Rotations of Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::rl_rotation(BNTnode<T> *parent){
    BNTnode<T> *temp;
    temp = parent->right;
    parent->right = ll_rotation (temp);
    return rr_rotation (parent);
}
 
//******************************************************************************
//                         Balancing of Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::balance(BNTnode<T> *temp){
    int bal_factor = diff (temp);
    if (bal_factor > 1){
        if (diff (temp->left) > 0)
            temp = ll_rotation (temp);
        else
            temp = lr_rotation (temp);
    }else if (bal_factor < -1){
        if (diff (temp->right) > 0)
            temp = rl_rotation (temp);
        else
            temp = rr_rotation (temp);
    }
    return temp;
}
 
//******************************************************************************
//                    Insert the Data into the Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::insert(BNTnode<T> *root, T value){
    if (root == NULL){
        root = new BNTnode<T>();
        root->data = value;
        root->left = NULL;
        root->right = NULL;
        return root;
    }else if (value < root->data){
        root->left = insert(root->left, value);
        root = balance (root);
    }else if (value >= root->data){
        root->right = insert(root->right, value);
        root = balance (root);
    }
    return root;
}

//******************************************************************************
//                    Delete the Data from the Sub Trees
//******************************************************************************
template <class T>
BNTnode<T> *AVLTree<T>::delet(BNTnode<T> *root, T value){
// base case
    if (root == NULL)
        return root;

    if (value < root->data)
    {
        root->left = delet(root->left, value);
        root = balance(root);
    }

    else if (value > root->data)
    {
        root->right = delet(root->right, value);
        root = balance(root);
    }

    else
    {
        if (root->left==NULL && root->right==NULL)
            return NULL;

        else if (root->left == NULL) {
            BNTnode<T> *temp = root->right;
            temp = balance(temp);
            return temp;
        }
        else if (root->right == NULL) {
            BNTnode<T> *temp = root->left;
            temp = balance(temp);
            return temp;
        }
 
        BNTnode<T> *temp = root->right;
        while (temp && temp->left != NULL)
            temp = temp->left;
        
        root->data = temp->data;

        root->right = delet(root->right, temp->data);
        root = balance(root);
    }
    return root;
}
//******************************************************************************
//                         Display all Sub Trees
//******************************************************************************
template <class T>
void AVLTree<T>::display(BNTnode<T> *ptr, int level){
    int i;
    if (ptr!=NULL){
        display(ptr->right, level + 1);
        cout<<endl;
        if (ptr == root)
        cout<<"R -> ";
        for (i = 0; i < level && ptr != root; i++)
            cout<<"     ";
        cout<<ptr->data;
        display(ptr->left, level + 1);
    }
}
 
//******************************************************************************
//                      In-order Output of Tree
//******************************************************************************
template <class T>
void AVLTree<T>::inorder(BNTnode<T> *tree){
    if (tree == NULL)
        return;
    inorder (tree->left);
    cout<<tree->data<<"  ";
    inorder (tree->right);
}

//******************************************************************************
//                      Pre-order Output of Tree
//******************************************************************************
template <class T>
void AVLTree<T>::preorder(BNTnode<T> *tree){
    if (tree == NULL)
        return;
    cout<<tree->data<<"  ";
    preorder (tree->left);
    preorder (tree->right);
}
 
//******************************************************************************
//                      Post-order Output of Tree
//******************************************************************************
template <class T>
void AVLTree<T>::postorder(BNTnode<T> *tree){
    if (tree == NULL)
        return;
    postorder ( tree ->left );
    postorder ( tree ->right );
    cout<<tree->data<<"  ";
}

//******************************************************************************
//                      Level-order Output of Tree
//******************************************************************************
template <class T>
void AVLTree<T>::levelOrder(BNTnode<T> *root){  
    int h = height(root);
    for (int i=1;i<=h;i++)prntLev(root, i);  
}  

//Print nodes at a given level
template <class T>
void AVLTree<T>::prntLev(BNTnode<T> *root, int level){  
    if (root == NULL)return;  
    if (level == 1)  
        cout << root->data << " ";  
    else if (level > 1){  
        prntLev(root->left, level-1);  
        prntLev(root->right, level-1);  
    }  
}

template <class T>
void AVLTree<T>::construct(BNTnode<T> *&root, int initialSize)
{
    for(int i = 0; i < initialSize; i++)
    {
        root = insert(root, (rand() % 20 + 1));
    }
}

template <class T>
void AVLTree<T>::cleanUp(BNTnode<T> *root)
{
    if(root == NULL)
        return;
    cleanUp(root->left);
    cleanUp(root->right);
    
    delete root;
}

#endif	/* AVLTREE_H */