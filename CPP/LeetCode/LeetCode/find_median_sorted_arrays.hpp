//
//  find_median_sorted_arrays.hpp
//  LeetCode
//
//  Created by MarkWu on 2021/1/9.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef find_median_sorted_arrays_h
#define find_median_sorted_arrays_h
#include <algorithm>

class FindMedianSortedArrays {
public:
    int GetKthElement(const vector<int>& nums1,  const vector<int>& nums2, int k) {
        int size_nums1 = (int)nums1.size();
        int size_nums2 = (int)nums2.size();
        
        int index_nums1 = 0, index_nums2 = 0;
        
        while(true){
            if (index_nums1 == size_nums1){
                return nums2[index_nums2 + k - 1];
            }
            
            if (index_nums2 == size_nums2){
                return nums1[index_nums1 + k - 1];
            }
            
            if (k == 1){
                return min(nums1[index_nums1], nums2[index_nums2]);
            }
            
            int new_index_nums1 = min(index_nums1 + k/2, size_nums1) - 1;
            int new_index_nums2 = min(index_nums2 + k/2, size_nums2) - 1;
            
            if (nums1[new_index_nums1] <= nums2[new_index_nums2]){
                k -= new_index_nums1 - index_nums1 + 1;
                index_nums1 = new_index_nums1 + 1;
            }else{
                k -= new_index_nums2 - index_nums2 + 1;
                index_nums2 = new_index_nums2 + 1;
            }
        }
    }
    
    double Solution1(const vector<int>& nums1, const vector<int>& nums2){
        int total_size = (int)nums1.size() + (int)nums2.size();
        
        if (total_size % 2 == 1){
            return GetKthElement(nums1, nums2, (total_size + 1) / 2);
        }
    
        return (GetKthElement(nums1, nums2, total_size / 2) + GetKthElement(nums1, nums2, (total_size / 2 + 1))) / 2.0f;
    }
};

#endif /* find_median_sorted_arrays_h */
