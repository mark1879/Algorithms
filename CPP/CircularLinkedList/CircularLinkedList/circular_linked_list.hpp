//
//  circular_linked_list.cpp
//  CircularLinkedList
//
//  Created by MarkWu on 2019/5/29.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef circular_linked_list_hpp
#define circular_linked_list_hpp

#include <iostream>
#include <boost/format.hpp>
#include "zego_log.hpp"

using namespace std;

template<class T>
struct ListNode
{
public:
    T val;
    Node *prev_node;
    Node *next;
    
public:
    ListNode() {}
    ListNode(T t, Node *prev_node, Node *next_node)
    {
        this->value = t;
        this->prev_node = prev_node;
        this->next_node = next_node;
    }
};

template<class T>
class CircularLinkedList
{
public:
    CircularLinkedList();
    ~CircularLinkedList();
    
    unsigned int Size() const;
    bool IsEmpty();
    
    bool GetNode(unsigned int index, T& value);
    bool InsertNode(unsigned int index, T t);
    bool DeleteNode(unsigned int index);
    
    void Traverse(bool reverse);
    
private:
    unsigned int count_of_list_;
    ListNode<T> *head_of_list_;
};

template<class T>
CircularLinkedList<T>::CircularLinkedList() : count_of_list_(0)
{
    head_of_list_ = new ListNode<T>();
    head_of_list_->prev_node = head_of_list_->next_node = head_of_list_;
    
    log_v_print(boost::format("[CircularLinkedList] create"));
}

template<class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    ListNode<T> *node = head_of_list_->next_node;
    while (node != head_of_list_)
    {
        ListNode<T> *temp = node;
        node = node->next_node;
        delete temp;
    }
    
    delete head_of_list_;
    head_of_list_ = nullptr;
    
    log_v_print(boost::format("[~CircularLinkedList] done"));
}

template<class T>
unsigned int CircularLinkedList<T>::Size() const
{
    return count_of_list_;
}

template<class T>
bool CircularLinkedList<T>::IsEmpty()
{
    return count_of_list_ == 0;
}

template<class T>
bool CircularLinkedList<T>::InsertNode(unsigned int index, T t)
{
    log_v_print(boost::format("[InsertNode] enter, index: %u") % index);
    
    if (index > count_of_list_)
    {
        log_v_print(boost::format("[Insert Node] Error, length of list: %u, index: %u Overflowed") % count_of_list_ % index);
        return false;
    }
    
    ListNode<T> *node = head_of_list_;
    for(unsigned int i = 0; i < index; i++)
    {
        node = node->next_node;
    }
    
    ListNode<T> *new_node = new ListNode<T>(t, node, node->next_node);
    node->next_node->prev_node = new_node;
    node->next_node = new_node;
    
    count_of_list_++;
    
    log_v_print(boost::format("[InserNode] insert done!"));
    return true;
}

template<class T>
bool CircularLinkedList<T>::GetNode(unsigned int index, T& value)
{
    log_v_print(boost::format("[GetNode] enter, index: %u") % index);
    
    if (index >= count_of_list_)
    {
        log_v_print(boost::format("[GetNode] Error, length of list: %u, index: %u Overflowed") % count_of_list_ % index);
        return false;
    }
    
    ListNode<T> *node = head_of_list_;
    for (unsigned int i = 0; i <= index; i++)
    {
        node = node->next_node;
    }
    
    value = node->value;
    
    return true;
}

template<class T>
bool CircularLinkedList<T>::DeleteNode(unsigned int index)
{
    log_v_print(boost::format("[DeleteNode] enter, index: %u") % index);
    
    if (index >= count_of_list_)
    {
        log_v_print(boost::format("[DeleteNode] Error, length of list: %u, index: %u, Overflowed") % index % count_of_list_);
        return false;
    }
    
    ListNode<T> *node_deleted = head_of_list_;
    for (unsigned int i = 0; i <= index; i++)
    {
        node_deleted = node_deleted->next_node;
    }
    
    node_deleted->prev_node->next_node = node_deleted->next_node;
    node_deleted->next_node->prev_node = node_deleted->prev_node;
    
    delete node_deleted;
    count_of_list_ -= 1;
    
    log_v_print(boost::format("[DeleteNode] delete done!"));
    return true;
}

template<class T>
void CircularLinkedList<T>::Traverse(bool reverse)
{
    if (count_of_list_ == 0)
    {
        log_v_print(boost::format("[Traverse] Waring, the list is empty!"));
        return;
    }
    
    log_v_print(boost::format("[Traverse] traversing the list(reverse: %d):") % reverse);
    
    if (!reverse)
    {
        ListNode<T> *node = head_of_list_->next_node;
        while (node != head_of_list_)
        {
            cout << node->value << endl;
            node = node->next_node;
        }
    }
    else
    {
        ListNode<T> *node = head_of_list_->prev_node;
        while (node != head_of_list_)
        {
            cout << node->value << endl;
            node = node->prev_node;
        }
    }
}

#endif
