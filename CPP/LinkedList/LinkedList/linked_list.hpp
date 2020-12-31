//
//  linked_list.hpp
//  LinkedList
//
//  Created by MarkWu on 2019/3/16.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef linked_list_hpp
#define linked_list_hpp

#include <iostream>
#include "zego_log.hpp"

using namespace std;

template<class T>
struct ListNode
{
public:
    T value;
    ListNode *next;
    
public:
    ListNode() : value(0), next(nullptr) {}
    ListNode(T t) : value(t), next(nullptr) {}
    ListNode(T t, ListNode *next) : value(t), next(next){}
};

template<class T>
class LinkedList
{
public:
    LinkedList();
    ~LinkedList();
    
    unsigned int Size() const;
    bool IsEmpty();
    
    bool Get(unsigned int index, T& value);
   
    bool Insert(unsigned int index, T t);
    
    bool Delete(unsigned int index);
    
    bool Traverse();
    
    bool Reverse();

private:
    ListNode<T>* DoReverse(ListNode<T> *current_node);
    
private:
    unsigned int count_of_nodes_;
    ListNode<T> *head_of_list_;
};

template<class T>
LinkedList<T>::LinkedList() : count_of_nodes_(0)
{
    head_of_list_ = new ListNode<T>();
    head_of_list_->next = nullptr;
    
    log_v_print("[LinkedList<T>::LinkedList] created\n");
}

template<class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *node = head_of_list_->next;
    while (node != nullptr)
    {
        ListNode<T> *temp = node;
        node = node->next;
        delete temp;
    }
    
    delete head_of_list_;
    head_of_list_ = nullptr;
    
    log_v_print("[LinkedList<T>::~LinkedList] destroyed\n");
}

template<class T>
unsigned int LinkedList<T>::Size() const
{
    return count_of_nodes_;
}

template<class T>
bool LinkedList<T>::IsEmpty()
{
    return count_of_nodes_ == 0;
}

template<class T>
bool LinkedList<T>::Insert(unsigned int index, T t)
{
    if (index > count_of_nodes_)
    {
//        log_v_print(boost::format(") % index % count_of_nodes_);
        
        log_v_print(string_format("[LinkedList<T>::Insert] Error, index(%u) Overflowed, Size Of The List: %u", index, count_of_nodes_));
        return false;
    }

    ListNode<T> *node = head_of_list_;
    for (unsigned int i = 0; i < index; i++)
    {
        node = node->next;
    }
    
    ListNode<T> *new_node = new ListNode<T>(t, node->next);
    node->next = new_node;
    
    count_of_nodes_++;
    
    log_v_print(string_format("[LinkedList<T>::Insert] Done! index: %u", index));
    
    return true;
}

template<class T>
bool LinkedList<T>::Get(unsigned int index, T& value)
{
    if (index >= count_of_nodes_)
    {
        log_v_print(string_format("[LinkedList<T>::Get] Error, index(%u) Overflowed, Size Of The List: %u", index  % count_of_nodes_));
        return false;
    }
    
    ListNode<T> *node = head_of_list_;
    for (unsigned int i = 0; i <= index; i++)
    {
        node = node->next;
    }
    
    value = node->value;
    
    return true;
}

template<class T>
bool LinkedList<T>::Delete(unsigned int index)
{
    if (index >= count_of_nodes_)
    {
        log_v_print(string_format("[LinkedList<T>::Delete] Error, index(%u) Overflowed, Size Of The List: %u", index % count_of_nodes_));
        return false;
    }
    
    ListNode<T> *prev_node = head_of_list_;
    ListNode<T> *current_node = head_of_list_->next;
    
    for (unsigned int i = 0; i < index; i++)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    
    prev_node->next = current_node->next;
    
    delete current_node;
    count_of_nodes_ -= 1;
    
    log_v_print(string_format("[LinkedList<T>::Delete] Done! index: %u", index));
    return true;
}

template<class T>
bool LinkedList<T>::Traverse()
{
    if (count_of_nodes_ == 0)
    {
        log_v_print("[LinkedList<T>::Traverse] Warning, the list is empty!");
        return false;
    }
    
    log_v_print("[LinkedList<T>::Traverse] the list:");
    
    ListNode<T> *node = head_of_list_->next;
    while (node != nullptr)
    {
        cout << node->value << "\t";
        node = node->next;
    }
    
    cout << endl;
    
    return true;
}

template<class T>
bool LinkedList<T>::Reverse()
{
    if (count_of_nodes_ == 0 || count_of_nodes_ == 1)
    {
        log_v_print(string_format("[LinkedList<T>::Reverse] Warning, do not need to reverse the list, size: %u", count_of_nodes_));
        return false;
    }
    
    ListNode<T> *current_node = head_of_list_->next;
    ListNode<T> *next_node = current_node->next;
    
    while (next_node != nullptr)
    {
        current_node->next = next_node->next;
        next_node->next = current_node;
        head_of_list_->next = next_node;
        
        next_node = current_node->next;
    }
    
    log_v_print("[LinkedList<T>::Reverse], complete reversing the linked list");
    
    return true;
}

#endif /* linked_list_h */
