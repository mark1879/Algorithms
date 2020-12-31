//
//  select_sort.hpp
//  Sort
//
//  Created by MarkWu on 2019/10/22.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef select_sort_h
#define select_sort_h

using namespace std;

bool select_sort(int data[], unsigned int size_of_data)
{
    cout << "[select_sort] Start, size_of_data: " << size_of_data << endl;
    
    if (data == nullptr)
    {
        cout << "[select_sort] Error, data is nullptr" << endl << endl;
        return false;
    }
    
    
    for (unsigned int i = 0; i < (size_of_data - 1); i++)
    {
        unsigned int target = i;
        
        for (unsigned int j = i + 1; j < size_of_data; j++)
        {
            if (data[j] < data[target])
            {
                target = j;
            }
        }
        
        if (target != i)
        {
            int temp = data[i];
            data[i] = data[target];
            data[target] = temp;
        }
    }
    
    cout << "[select_sort] Done" << endl;
    
    return true;
}

#endif /* select_sort_h */
