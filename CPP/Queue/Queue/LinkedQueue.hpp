//
//  LinkedQueue.hpp
//  Queue
//
//  Created by MarkWu on 2019/11/5.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef LinkedQueue_h
#define LinkedQueue_h
#include <iostream>
#include <boost/format.hpp>
#include "zego_log.hpp"

template<class T>
struct ListNode
{
public:
    T val;
    Node *next;

public:
    ListNode()
    {
        this->next_node = nullptr;
    };
    
    ListNode(T t)
    {
        this->value = t;
        this->next_node = nullptr;
    }
};

template<class T>
class LinkedQueue
{
public:
    LinkedQueue();
    ~LinkedQueue();
    
    unsigned int Capacity() const;
    unsigned int Size() const;
    
    bool Enqueue(const T& value);
    bool Dequeue(T& value);
    
private:
    const unsigned int capacity_of_queue_;
    unsigned int count_of_nodes_;
    ListNode<T> *head_of_queue_;
    ListNode<T> *tail_of_queue_;
};

template<class T>
LinkedQueue<T>::LinkedQueue() : capacity_of_queue_(1000)
{
    count_of_nodes_ = 0;
    
    head_of_queue_ = new ListNode<T>();
    tail_of_queue_ = head_of_queue_;
    
    log_v_print("[LinkedQueue<T>::LinkedQueue] Create!");
}

template<class T>
LinkedQueue<T>::~LinkedQueue()
{
    ListNode<T> *node = head_of_queue_->next_node;
    while (node != nullptr)
    {
        ListNode<T> *temp = node;
        node = node->next_node;
        
        delete temp;
    }
    
    delete head_of_queue_;
    
    log_v_print("[LinkedQueue<T>::~LinkedQueue] Done!");
}

template<class T>
unsigned int LinkedQueue<T>::Capacity() const
{
    return capacity_of_queue_;
}

template<class T>
unsigned int LinkedQueue<T>::Size() const
{
    return count_of_nodes_;
}

template<class T>
bool LinkedQueue<T>::Enqueue(const T& value)
{
    if (count_of_nodes_ >= capacity_of_queue_)
    {
        log_v_print(boost::format("[LinkedQueue<T>::Enqueue] Error, the queue has been full! count_of_nodes_:%u, capacity_of_queue_:%u") % count_of_nodes_ % capacity_of_queue_);
        return false;
    }
    
    ListNode<T> *node = new ListNode<T>(value);
    tail_of_queue_->next_node = node;
    tail_of_queue_ = node;
    
    count_of_nodes_++;
    
    return true;
}

template<class T>
bool LinkedQueue<T>::Dequeue(T& value)
{
    if (count_of_nodes_ == 0)
    {
        log_v_print("[LinkedQueue<T>::Dequeue] Error, the queue is empty!");
        return false;
    }
    
    ListNode<T> *node = head_of_queue_->next_node;
    value = node->value;
    head_of_queue_->next_node = node->next_node;
    
    count_of_nodes_ --;
    
    delete node;
    
    return true;
}

#endif /* LinkedQueue_h */
