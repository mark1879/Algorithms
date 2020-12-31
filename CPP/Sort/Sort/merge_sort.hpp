//
//  merge_sort.hpp
//  Sort
//
//  Created by MarkWu on 2019/11/26.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef merge_sort_h
#define merge_sort_h
#include <iostream>

void merge(int data[], unsigned int start, unsigned int mid, unsigned int end)
{
    int *temp = (int *)malloc(sizeof(int) * (end - start + 1));
    if (temp == nullptr)
    {
        cout << "[merge] Malloc Error!" << endl;
        return;
    }
    
    int i = start;
    int j = mid + 1;
    int k = 0;
    
    while (i <= mid && j <= end)
    {
        if (data[i] <= data[j])
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];
    }
    
    while (i <= mid)
        temp[k++] = data[i++];
    
    while (j <= end)
        temp[k++] = data[j++];
    
    memcpy((data + start), temp, sizeof(int) * (end - start + 1));
    
    free(temp);
}

void merge_sort_(int data[], unsigned int start, unsigned int end)
{
    if (start >= end)
        return;
    
    unsigned int mid = (start + end) / 2;
    
    merge_sort_(data, start, mid);
    merge_sort_(data, mid+1, end);
    
    merge(data, start, mid, end);
}

bool merge_sort(int data[], unsigned int size_of_data)
{
    cout << "[merge_sort] Start, size_of_data: " << size_of_data << endl;

    if (data == nullptr)
    {
        cout << "[merge_sort] Error, data is nullptr" << endl << endl;
        return false;
    }
    
    merge_sort_(data, 0, size_of_data - 1);
    
    cout << "[merge_sort] Done!" << endl;
    
    return true;
}

#endif /* merge_sort_h */
