//
//  max_priority_queue.h
//  Heap
//
//  Created by MarkWu on 2019/6/20.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef max_priority_queue_h
#define max_priority_queue_h

using namespace std;

template<class T>
class MaxPriorityQueue
{
public:
    virtual ~MaxPriorityQueue() {}
    virtual bool Empty() const = 0;
    virtual unsigned int Size() const = 0;
    virtual bool Top(T&) = 0;
    virtual bool Pop() = 0;
    virtual bool Push(const T& t) = 0;
};
#endif /* max_priority_queue_h */
