//
//  quick_sort.hpp
//  Sort
//
//  Created by MarkWu on 2019/10/22.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef quick_sort_h
#define quick_sort_h

void quick_sort_(int data[], int left, int right)
{
    if (left >= right)
        return;
    
    int middle = data[left];
    int i = left;
    int j = right;
    
    while (i != j)
    {
        while (data[j] >= middle && i < j)
            j--;
        
        while (data[i] <= middle && i < j)
            i++;
        
        if (i < j)
        {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    data[left] = data[i];
    data[i] = middle;
    
    quick_sort_(data, left, i - 1);
    quick_sort_(data, i + 1, right);
}

bool quick_sort(int data[], unsigned int size_of_data)
{
    cout << "[quick_sort] Start, size_of_data: " << size_of_data << endl;
    
    if (data == nullptr)
    {
        cout << "[quick_sort] Error, data is nullptr" << endl << endl;
        return false;
    }
    
    quick_sort_(data, 0, size_of_data - 1);
    
    cout << "[quick_sort] Done" << endl;
    
    return true;
}

int find_k_max_(int data[], unsigned int left, unsigned int right, unsigned int k)
{
    int middle = data[left];
    int i = left;
    int j = right;
    
    while (i != j)
    {
        while (data[j] >= middle && i < j)
            j--;
        
        while (data[i] <= middle && i < j)
            i++;
        
        if (i < j)
        {
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    data[left] = data[i];
    data[i] = middle;
    
    if (i == k)
        return middle;
    else if (k > i)
        return find_k_max_(data, i+1, right, k);
    else
        return find_k_max_(data, left, i-1, k);
}

bool find_k_max(int data[], unsigned int size_of_data, unsigned int k, int& k_max_value)
{
    cout << "[find_k_max], k: " << k << endl;
    
    if (data == nullptr)
    {
        cout << "[find_k_max] error, data is nullptr" << endl;
        return false;
    }
    
    if (k >= size_of_data)
    {
        char buf[64];
        sprintf(buf, "[find_k_max] error, k(%u) exceeds size_of_data(%u)", k, size_of_data);
        cout << buf << endl;
        return false;
    }
    
    k_max_value = find_k_max_(data, 0, size_of_data - 1, k);
    
    return true;
}

#endif /* quick_sort_h */
