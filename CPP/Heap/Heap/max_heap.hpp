//
//  max_heap.cpp
//  Heap
//
//  Created by MarkWu on 2019/6/20.
//  Copyright © 2019 Zego. All rights reserved.
//
#ifndef MAX_HEAP_HPP
#define MAX_HEAP_HPP
#include <stdio.h>
#include "max_priority_queue.h"
#include <boost/format.hpp>
#include <memory>
#include "zego_log.hpp"

using namespace std;

template<class T>
class MaxHeap : public MaxPriorityQueue<T>
{
public:
    MaxHeap(unsigned int capacity = 10);
    ~MaxHeap();
    bool Empty() const override;
    unsigned int Size() const override;
    bool Top(T& element) override;
    bool Pop() override;
    bool Push(const T&) override;
    
    void Traverse();
    void Sort();
    
private:
    unsigned int AdjustHeap(unsigned int adjust_element, unsigned int last_element);
    unsigned int Compare(unsigned int left_child, unsigned int right_child);
    
private:
    unsigned int heap_size_;
    unsigned int capacity_;
    T *heap_;
};

template<class T>
class TestHeap : public MaxHeap<T>
{
public:
    bool Empty() const override;
};

template<class T>
MaxHeap<T>::MaxHeap(unsigned int capacity)
{
    if (capacity == 0)
    {
        log_v_print(boost::format("[MaxHeap] failed, illegal capacity: %u") % capacity);
        return;
    }
    
    capacity_ = capacity;
    heap_size_ = 0;
    // heap_ 中第一个元素空间不存储数据
    heap_ = new T[capacity_ + 1];
}

template<class T>
MaxHeap<T>::~MaxHeap()
{
    if (heap_ != nullptr)
    {
        delete heap_;
        heap_ = nullptr;
    }
}

template<class T>
bool MaxHeap<T>::Empty() const
{
    return heap_size_ == 0;
}

template<class T>
unsigned int MaxHeap<T>::Size() const
{
    return heap_size_;
}

template<class T>
bool MaxHeap<T>::Push(const T& element)
{
    if (heap_size_ >= capacity_)
    {
        log_v_print(boost::format("[MaxHeap<T>::Push] failed, heap_size_(%u) exceeds capacity(%u)") % heap_size_ % capacity_);
        return false;
    }
    
    heap_size_ += 1;
    heap_[heap_size_] = element;
    
    unsigned int index = heap_size_;
    unsigned int root = 1;
    
    while (index > root)
    {
        unsigned int parent = index / 2;
        
        if (heap_[index] > heap_[parent])
        {
            swap_value(heap_[index],heap_[parent]);
        }
        
        index = parent;
    }
    
    return true;
}

template<class T>
void MaxHeap<T>::Traverse()
{
    if (heap_size_ == 0)
    {
        log_v_print(boost::format("[MaxHeap<T>::Traverse] warning, heap is empty"));
        return;
    }
    
    log_v_print("[MaxHeap<T>::Traverse]:");
    
    for (unsigned int i = 1; i <= heap_size_; i++)
    {
        cout << heap_[i] << "\t";
    }
    
    cout << endl;
}

template<class T>
unsigned int MaxHeap<T>::Compare(unsigned int left_child, unsigned int right_child)
{
    // 返回更大的节点
    if (heap_[left_child] > heap_[right_child])
        return left_child;
        
    return right_child;
}

template<class T>
unsigned int MaxHeap<T>::AdjustHeap(unsigned int adjust_element, unsigned int last_element)
{
    unsigned int left_child = adjust_element * 2;
    unsigned int right_child = adjust_element * 2 + 1;
    
    // 左、右两个字节点都合法
    if (left_child <= last_element && right_child <= last_element)
    {
        unsigned int big = Compare(left_child, right_child);
        
        if (heap_[adjust_element] < heap_[big])
            return big;
      
    // 只有左节点合法
    }else if (left_child <= last_element)
    {
        if (heap_[adjust_element] < heap_[left_child])
            return left_child;
    }
    
    return adjust_element;
}

template<class T>
void MaxHeap<T>::Sort()
{
    if (heap_size_ == 0)
    {
        log_v_print(boost::format("[MaxHeap<T>::Traverse] warning, heap is empty"));
        return;
    }
    
    log_v_print("[MaxHeap<T>::Sort]");
    
    T *temp_array = new T[heap_size_];
    
    for (unsigned int i = 0; i < heap_size_; i++)
    {
        // 取出堆顶元素(最大值)
        temp_array[i] = heap_[1];
        
        // 将最后一个元素放置堆顶
        unsigned int last_element = heap_size_ - i;
        heap_[1] = heap_[last_element];
        last_element -= 1;
        
        // 自上而下调整堆
        unsigned int max_element  = 1;
        
        while (true)
        {
            if ((max_element * 2 <= last_element)
               && (heap_[max_element] < heap_[max_element * 2]))
            {
               max_element = max_element * 2;
            }
            
            if ((max_element * 2 + 1 <= last_element)
                && (heap_[max_element] < heap_[max_element * 2 + 1]))
            {
                max_element = max_element * 2 + 1;
            }
        
            
        }
        
        while (max_element < last_element)
        {
            
            unsigned int need_to_exchange = AdjustHeap(adjust_element, last_element);
            
            if (adjust_element != need_to_exchange)
            {
                swap_value(heap_[adjust_element], heap_[need_to_exchange]);
                adjust_element = need_to_exchange;
            }
            else
            {
                // 不需要调整
                break;
            }
        }
    }
    
    for (unsigned int i = 0; i < heap_size_; i++)
    {
        heap_[i + 1] = temp_array[i];
    }
    
    delete[] temp_array;
}

template<class T>
bool MaxHeap<T>::Top(T& element)
{
    return false;
}

template<class T>
bool MaxHeap<T>::Pop()
{
    return false;
}


#endif
