//
//  recursive_sorting.hpp
//  Recursion
//
//  Created by MarkWu on 2019/11/13.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef recursive_sorting_h
#define recursive_sorting_h
#include <iostream>

using namespace std;

int get_max(int data[], int next_index, int length, int max_value)
{
    if (data == nullptr)
        return -1;
    
    if (next_index == length)
        return max_value;
    
    max_value = data[next_index] > max_value ? data[next_index] : max_value;
    
    return get_max(data, next_index + 1, length, max_value);
}

int get_max2(int data[], int current_index, int end)
{
    if (data == nullptr)
        return -1;
    
    if (current_index == end)
        return data[current_index];
    
    int current_max = data[current_index];
    int next = get_max2(data, current_index + 1, end);
    
    return current_max >= next ? current_max : next;
}

void test_recursive_sorting()
{
    int data[] = {2, 3, 4, 5, 1, 5, 2, 9, 5, 6, 8, 3, 2, 10, 12};
    int length = sizeof(data) / sizeof(int);
    
    cout << "get_max: " << endl;
    cout << get_max(data, 1, length, data[0]) << endl;
    
    cout << "get_max2: " << endl;
    cout << get_max2(data, 0, length - 1) << endl;
}



#endif /* recursive_sorting_h */
