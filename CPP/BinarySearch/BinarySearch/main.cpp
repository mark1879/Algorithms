//
//  main.cpp
//  BinarySearch
//
//  Created by MarkWu on 2019/12/3.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <cassert>
#include "binary_search.hpp"

using namespace std;

void test_binary_search(int data_len, bool(* search)(const int*, const int, const int, int&), const char* func_name)
{
    cout << "[test_binary_search] Start, func_name: " << func_name << ", data_len: " << data_len << endl;
    
    if (data_len > INT_MAX)
    {
        cout << "[test_binary_search] Error, data_len overflowed\n";
        return;
    }
    
    int* data = (int *)malloc(data_len * sizeof(int));
    if (data == nullptr)
    {
        cout << "[test_binary_search], malloc error!" << endl;
        return;
    }
    
    for (int index = 0; index < data_len; index++)
    {
        data[index] = index;
    }
    
    int target_index;
    assert(search(nullptr, data_len, data_len - 1, target_index) == false);
    
    assert(search(data, data_len, data_len - 1, target_index) == true);
    assert(target_index == (data_len - 1));
    
    assert(search(data, data_len, 0, target_index) == true);
    assert(target_index == 0);
    
    assert(search(data, data_len, data_len/2, target_index) == true);
    assert(target_index == (data_len/2));
    
    cout << "[test_binary_search] Done\n";
    
    free(data);
}

int main(int argc, const char * argv[])
{
//    test_binary_search(100, binary_search, "binary_search");
    
    test_binary_search(100, binary_search_recursively, "binary_search_recursively");
    return 0;
}
