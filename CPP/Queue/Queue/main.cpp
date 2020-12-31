//
//  main.cpp
//  Queue
//
//  Created by MarkWu on 2019/11/4.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "ArrayQueue.hpp"
#include "LinkedQueue.hpp"

void test_linked_queue()
{
    log_v_print("[test_linked_queue] Start...");
    
    LinkedQueue<int> linked_queue;
    
    const unsigned int capacity_of_queue = linked_queue.Capacity();
    
    for (unsigned int i = 0; i < capacity_of_queue; i++)
    {
        assert(linked_queue.Enqueue(i) == true);
    }
    
    // overflow
    assert(linked_queue.Enqueue(-1) == false);
    
    int value;
    for (unsigned int i = 0; i < capacity_of_queue; i++)
    {
        assert(linked_queue.Dequeue(value) == true);
        assert(value == i);
    }
    
    // empty
    assert(linked_queue.Dequeue(value) == false);
    
    log_v_print("[test_linked_queue] Done!");
}

int main(int argc, const char * argv[])
{
    test_linked_queue();
    return 0;
}
