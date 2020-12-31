//
//  array_stack.hpp
//  Stack
//
//  Created by MarkWu on 2019/9/14.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef array_stack_h
#define array_stack_h
#include <boost/format.hpp>
#include "zego_log.hpp"

template<class T>
class ArrayStack
{
public:
    ArrayStack();
    ~ArrayStack();
    
    unsigned int Size() const;
    bool Push(T t);
    bool Pop(T &t);
    bool GetNode(const unsigned int index, T& t);
    
private:
    T *elements_ = nullptr;
    unsigned int count_of_elements_ = 0;
    unsigned int size_of_stack_ = 0;
    
    const unsigned int kSizeOfSingleAllocation = 200;
    const unsigned int kMaxSizeOfStack = 1000;
};

template<class T>
ArrayStack<T>::ArrayStack()
{
    size_of_stack_ = kSizeOfSingleAllocation;
    elements_ = new T[size_of_stack_];
    count_of_elements_ = 0;
}

template<class T>
ArrayStack<T>::~ArrayStack()
{
    if (elements_)
        delete elements_;
    
    size_of_stack_ = 0;
    count_of_elements_ = 0;
}

template<class T>
unsigned int ArrayStack<T>::Size() const
{
    return count_of_elements_;
}

template<class T>
bool ArrayStack<T>::Push(T t)
{
    if (count_of_elements_ >= size_of_stack_)
    {
       
        if (size_of_stack_ >= kMaxSizeOfStack)
        {
           log_v_print(boost::format("[ArrayStack::Push] size_of_stack_(%u) Exceeded kMaxSizeOfStack(%u)") % size_of_stack_ % kMaxSizeOfStack);
           return false;
        }

        unsigned int new_size_of_stack = size_of_stack_ + kSizeOfSingleAllocation;
        T *new_elements = new T[new_size_of_stack];
        memcpy(new_elements, elements_, size_of_stack_ * sizeof(T));

        size_of_stack_ = new_size_of_stack;

        delete elements_;
        elements_ = new_elements;
    }
           
    elements_[count_of_elements_] = t;
    count_of_elements_ += 1;
           
    return true;
}

template<class T>
bool ArrayStack<T>::Pop(T &t)
{
    if (count_of_elements_ == 0)
    {
        log_v_print(boost::format("[ArrayStack<T>::Pop] Error, count_of_elements_ is 0"));
        return false;
    }
        
           
    t = elements_[count_of_elements_ - 1];
    count_of_elements_ -= 1;
           
    return true;
}

template<class T>
bool ArrayStack<T>::GetNode(const unsigned int index, T& t)
{
    if (index >= count_of_elements_)
    {
        log_v_print(boost::format("[ArrayStack<T>::GetNode] Error, index(%u) must be less than count_of_elements_(%u)") % index % count_of_elements_);
        return false;
    }

    t = elements_[index];
    
    return true;
}

#endif /* array_stack_h */
