//
//  main.cpp
//  Heap
//
//  Created by MarkWu on 2019/6/18.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "max_heap.hpp"

using namespace std;

void testMaxHeap()
{
    unsigned int capacity = 100;
    
    MaxHeap<unsigned int> max_heap(capacity);
    
    for (unsigned int i = 1; i <= capacity; i++)
    {
        max_heap.Push(i);
    }

    max_heap.Traverse();
    
    max_heap.Sort();
    
    max_heap.Traverse();
    
}

int main(int argc, const char * argv[])
{
    std::cout << "Test Heap!\n";
    
    testMaxHeap();
   
    return 0;
}
