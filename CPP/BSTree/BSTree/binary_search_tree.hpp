//
//  binary_search_tree.hpp
//  BSTree
//
//  Created by MarkWu on 2020/4/29.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef binary_search_tree_hpp
#define binary_search_tree_hpp

#include <iostream>

template <class T>
class BSTNode
{
public:
    T value_;
    BSTNode *left_;
    BSTNode *right_;
    BSTNode *parent_;
    

public:
    BSTNode(T value, BSTNode *left, BSTNode *right, BSTNode *parent)
    {
        this->value_ = value;
        this->left_ = left;
        this->right_ = right;
        this->parent_ = parent;
    }
};

template <class T>
class BSTree
{
private:
    BSTNode<T> *root_;
    
public:
    BSTree();
    ~BSTree();
    
    void PreOrder();
    void InOrder();
    void PostOrder();
    
    BSTNode<T>* Search(T value);
    // 非递归实现
    BSTNode<T>* IterativeSearch(T value);
    
    T Minimum();
    T Maximum();
    
    bool Insert(T value);
    void Remove(T value);
    void Destroy();
    void Print();

};

template<class T>
bool BSTree<T>::Insert(T value)
{
    
}

#endif /* binary_search_tree_hpp */
