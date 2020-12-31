//
//  heap_sort.hpp
//  Sort
//
//  Created by MarkWu on 2019/10/22.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef heap_sort_h
#define heap_sort_h

#include <iostream>
#include <cassert>

using namespace std;

void adjust_heap_down_(int data[], unsigned int size_of_data, int adjust_position)
{
    if (adjust_position >= size_of_data)
        return;
    
    int left_child = (adjust_position + 1) * 2 - 1;
    int right_child = (adjust_position + 1) * 2;
    
    int smaller_position = -1;
    
    if (left_child < size_of_data && right_child < size_of_data)
    {
        int small = data[left_child] < data[right_child] ? left_child : right_child;
        
        if (data[small] < data[adjust_position])
        {
            smaller_position = small;
        }
    }
    else if (left_child < size_of_data)
    {
        if (data[left_child] < data[adjust_position])
        {
            smaller_position = left_child;
        }
    }
    else if (right_child < size_of_data)
    {
        if (data[right_child] < data[adjust_position])
        {
            smaller_position = right_child;
        }
    }
    
    if (smaller_position != -1)
    {
        int temp = data[adjust_position];
        data[adjust_position] = data[smaller_position];
        data[smaller_position] = temp;
        
        adjust_heap_down_(data, size_of_data, smaller_position);
    }
}

void construct_min_heap_(int data[], unsigned int size_of_data)
{
    for (unsigned int i = size_of_data - 1; i > 0; i--)
    {
        unsigned int child = i;
        unsigned int parent = (child - 1) / 2;
        
        if (data[child] < data[parent])
        {
            int temp = data[child];
            data[child] = data[parent];
            data[parent] = temp;
            
            adjust_heap_down_(data, size_of_data, child);
        }
    }
}

bool verify_min_heap_(int data[], unsigned int size_of_data)
{
    for (unsigned int i = size_of_data - 1; i > 0; i--)
    {
        unsigned int child = i;
        while (child > 0)
        {
            unsigned int parent = (child - 1) / 2;
           
            if (data[parent] > data[child])
            {
                cout << "[verify_max_heap_] Failed" << endl;
                return false;
            }
          
            child = parent;
        }
    }
    
    cout << "[verify_max_heap_] Passed" << endl;
    
    return true;
}

void heap_sort_(int data[], unsigned int size_of_data)
{
    int* data_sorted = (int *)malloc(size_of_data * sizeof(int));
    
    for (unsigned int i = 0; i < size_of_data; i++)
    {
        data_sorted[i] = data[0];
        data[0] = data[size_of_data - 1 - i];
        adjust_heap_down_(data, size_of_data - 1 - i, 0);
    }
    
    memcpy(data, data_sorted, size_of_data * sizeof(int));
    
    free(data_sorted);
}

bool heap_sort(int data[], unsigned int size_of_data)
{
    cout << "[heap_sort] Start, size_of_data: " << size_of_data << endl;
    
    if (data == nullptr)
    {
        cout << "[heap_sort] Error, data is nullptr" << endl;
        return false;
    }
    
    construct_min_heap_(data, size_of_data);
    
    assert(verify_min_heap_(data, size_of_data) == true);
    
    heap_sort_(data, size_of_data);
    
    cout << "[heap_sort] Done" << endl;
    
    return true;
}

#endif /* heap_sort_h */
