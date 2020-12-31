//
//  insert_sort.hpp
//  Sort
//
//  Created by MarkWu on 2019/11/12.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef insert_sort_h
#define insert_sort_h
#include <iostream>

using namespace std;

bool insert_sort(int data[], unsigned int size_of_data)
{
    cout << "[insert_sort] Start, size_of_data: " << size_of_data << endl;

    if (data == nullptr)
    {
        cout << "[insert_sort] Error, data is nullptr" << endl << endl;
        return false;
    }
    
    for (int i = 1; i < size_of_data; i++)
    {
        int value = data[i];
        int j = i - 1;
        
        for (; j >= 0; j--)
        {
            if (data[j] > value)
            {
                data[j+1] = data[j];
            }
            else
            {
                break;
            }
        }
        
        data[j+1] = value;
    }

    cout << "[insert_sort] Done" << endl;
    
    return true;
}

#endif /* insert_sort_h */
