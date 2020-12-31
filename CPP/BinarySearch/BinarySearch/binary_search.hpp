//
//  binary_search.hpp
//  BinarySearch
//
//  Created by MarkWu on 2019/12/3.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef binary_search_h
#define binary_search_h

bool binary_search(const int data[], const int data_len, const int value, int& index)
{
    if (data == nullptr)
        return false;
    
    int start = 0;
    int end = data_len - 1;
    
    while (start <= end)
    {
        int mid = start + ((end - start) >> 1);
        if (data[mid] == value)
        {
            index = mid;
            return true;
        }
        else if (data[mid] < value)
            start = mid + 1;
        else
            end = mid - 1;
    }
    
    return false;
}

bool binary_search_recursively_(const int data[], const int start, const int end, const int value, int& index)
{
    if (start > end)
        return false;

    int mid = start + ((end - start) >> 1);
    if (data[mid] == value)
    {
        index = mid;
        return true;
    }
    else if (data[mid] < value)
        return binary_search_recursively_(data, mid + 1, end, value, index);
    else
        return binary_search_recursively_(data, start, end - 1, value, index);
}

bool binary_search_recursively(const int data[], const int data_len, const int value, int& index)
{
    if (data == nullptr)
        return false;
    
    return binary_search_recursively_(data, 0, data_len - 1, value, index);
}


#endif /* binary_search_h */
