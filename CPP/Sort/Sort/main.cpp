//
//  main.cpp
//  Sort
//
//  Created by MarkWu on 2019/10/16.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include <cassert>
#include <cstdlib>
#include <time.h>
#include "Test.hpp"
#include "bubble_sort.hpp"
#include "select_sort.hpp"
#include "quick_sort.hpp"
#include "heap_sort.hpp"
#include "insert_sort.hpp"
#include "merge_sort.hpp"

int main(int argc, const char * argv[])
{
    unsigned int size_of_data = 10000;
    
    int *data = TestSortingAlgorithm::GenerateTestData(size_of_data);
    if (data == nullptr)
    {
        cout << "[TestSortingAlgorithm::Test] Error, No Test Data" << endl;
        return -1;
    }
    
    TestSortingAlgorithm::Test((bool(*)(int *, int))bubble_sort, data, size_of_data);
    TestSortingAlgorithm::Test((bool(*)(int *, int))select_sort, data, size_of_data);
    TestSortingAlgorithm::Test((bool(*)(int *, int))insert_sort, data, size_of_data);
    TestSortingAlgorithm::Test((bool(*)(int *, int))quick_sort, data, size_of_data);
    TestSortingAlgorithm::Test((bool(*)(int *, int))heap_sort, data, size_of_data);
    TestSortingAlgorithm::Test((bool(*)(int *, int))merge_sort, data, size_of_data);
    
    free(data);
    
    return 0;
}
