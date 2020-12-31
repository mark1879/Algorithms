//
//  link_stack.hpp
//  Stack
//
//  Created by MarkWu on 2019/9/18.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef linked_stack_h
#define linked_stack_h
#include <iostream>

using namespace std;

template<class T>
struct ListNode
{
public:
    T val;
    Node *next;
    
public:
    ListNode() {}
    ListNode(T t, Node *next_node)
    {
        this->value = t;
        this->next_node = next_node;
    }
};

template<class T>
class Stack
{
public:
    Stack();
    ~Stack();
    
    unsigned int Size() const;
    bool IsEmpty();
    bool Push(const T value);
    bool Pop(T& value);
    bool GetNode(const unsigned int index, T& value);
    
    void Traverse();
    
private:
    unsigned int count_of_nodes_;
    ListNode<T> *head_of_stack_;
    
    const unsigned int kMaxNodesOfStack = 100;
};

template<class T>
Stack<T>::Stack() : count_of_nodes_(0)
{
    head_of_stack_ = new ListNode<T>();
    head_of_stack_->next_node = nullptr;
    
    log_v_print(boost::format("[Stack<T>::Stack] created"));
}

template<class T>
Stack<T>::~Stack()
{
    ListNode<T> *node = head_of_stack_->next_node;
    while (node != nullptr)
    {
        ListNode<T> *temp = node;
        node = node->next_node;
        
        delete temp;
    }
    
    delete head_of_stack_;
    head_of_stack_ = nullptr;
    
    log_v_print(boost::format("[Stack<T>::~Stack] destroyed"));
}

template<class T>
unsigned int Stack<T>::Size() const
{
    return count_of_nodes_;
}

template<class T>
bool Stack<T>::IsEmpty()
{
    return count_of_nodes_;
}

template<class T>
bool Stack<T>::Push(const T value)
{
    if (count_of_nodes_ >= kMaxNodesOfStack)
    {
        log_v_print(boost::format("[Stack<T>::Push] Error, count_of_nodes_(%u) exceeded kMaxNodesOfStack(%u)") % count_of_nodes_ % kMaxNodesOfStack);
        return false;
    }
    
    ListNode<T> *new_node = new ListNode<T>(value, head_of_stack_->next_node);
    head_of_stack_->next_node = new_node;
    count_of_nodes_ += 1;
    
    return true;
}

template<class T>
bool Stack<T>::Pop(T& value)
{
    if (count_of_nodes_ == 0)
    {
        log_v_print("[Stack<T>::Pop] Error, count_of_nodes_ is 0\n");
        return false;
    }
    
    ListNode<T> *node = head_of_stack_->next_node;
    head_of_stack_->next_node = node->next_node;
    value = node->value;
    
    count_of_nodes_ -= 1;
    delete node;
    
    return true;
}

template<class T>
bool Stack<T>::GetNode(const unsigned int index, T& value)
{
    if (index >= count_of_nodes_)
    {
        log_v_print(boost::format("[Stack<T>::GetNode] Error, index(%u) must be less than count_of_nodes_(%u)") % index % count_of_nodes_);
        return false;
    }
    
    ListNode<T> *node = head_of_stack_;
    
    for (unsigned int i = 0; i <= index; i++)
    {
        node = node->next_node;
    }
    
    value = node->value;
    
    return true;
}

template<class T>
void Stack<T>::Traverse()
{
    log_v_print("[Stack<T>::Traverse] Start:");
    
    ListNode<T> *node = head_of_stack_->next_node;
    
    while (node != nullptr)
    {
        cout << node->value << "\t";
        
        node = node->next_node;
    }
    
    cout << endl;
}


#endif /* linked_stack_h */
