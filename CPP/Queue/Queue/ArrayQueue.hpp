//
//  ArrayQueue.hpp
//  Queue
//
//  Created by MarkWu on 2019/11/4.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef ArrayQueue_h
#define ArrayQueue_h
#include <iostream>
#include <boost/format.hpp>
#include "zego_log.hpp"

template<class T>
class ArrayQueue
{
public:
    ArrayQueue();
    ~ArrayQueue();
    
    unsigned int Capacity() const;
    unsigned int Size() const;
    
    bool Enqueue(const T& item);
    bool Dequeue(T& item);
  
private:
    unsigned int capacity_;
    T* items_;
    unsigned int head_;
    unsigned int tail_;
};

template<class T>
ArrayQueue<T>::ArrayQueue() : capacity_(1000)
{
    *items_ = new T[capacity_];
    head_ = -1;
    tail_ = -1;
}

template<class T>
ArrayQueue<T>::~ArrayQueue()
{
    if (items_ != nullptr)
    {
        delete items_;
    }
}

template<class T>
unsigned int ArrayQueue<T>::Capacity() const
{
    return capacity_;
}

template<class T>
unsigned int ArrayQueue<T>::Size() const
{
    return tail_ - head_;
}

template<class T>
bool ArrayQueue<T>::Enqueue(const T &item)
{
    if (tail_ == capacity_)
    {
        if (head_ == 0)
        {
            log_v_print(boost::format("[ArrayQueue<T>::Enqueue] Error, the queue has been full, capacity: %d") % capacity_);
            return false;
        }
        
        for (int i = head_; i < tail_; i++)
        {
            items_[i - head_] = items_[i];
        }
        
        head_ = 0;
        tail_ = tail_ - head_;
    }
    
    items_[tail_] = item;
    tail_++;
    
    return true;
}

template<class T>
bool ArrayQueue<T>::Dequeue(T &item)
{
    if (head_ == tail_)
    {
        log_v_print("[ArrayQueue<T>::Dequeue] Error, the queue is emplty!");
        return false;
    }
    
    item = items_[head_];
    head_++;
}

#endif /* ArrayQueue_h */
