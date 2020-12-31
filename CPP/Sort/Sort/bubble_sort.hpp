//
//  bubble_sort.hpp
//  Sort
//
//  Created by MarkWu on 2019/10/16.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef bubble_sort_h
#define bubble_sort_h
#include <iostream>

using namespace std;

bool bubble_sort(int data[], unsigned int size_of_data)
{
    cout << "[bubble_sort] Start, size_of_data: " << size_of_data << endl;

    if (data == nullptr)
    {
        cout << "[bubble_sort] Error, data is nullptr" << endl << endl;
        return false;
    }
    
    
    for (int i = 0; i < size_of_data; i++)
    {
        bool data_exchanged = false;
        for (int j = 0; j < size_of_data - i - 1; j++)
        {
            if (data[j] > data[j + 1])
            {
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
              
                data_exchanged = true;
            }
        }
        
        if (!data_exchanged)
            break;
    }
    
    cout << "[bubble_sort] Done" << endl;
    
    return true;
}

#endif
