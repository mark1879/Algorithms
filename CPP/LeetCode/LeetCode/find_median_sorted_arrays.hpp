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
    static int GetKthElement(const vector<int>& nums1,  const vector<int>& nums2, int k) {
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
    
    static double Solution1(const vector<int>& nums1, const vector<int>& nums2){
        int total_size = (int)nums1.size() + (int)nums2.size();
        
        if (total_size % 2 == 1){
            return GetKthElement(nums1, nums2, (total_size + 1) / 2);
        }
    
        return (GetKthElement(nums1, nums2, total_size / 2) + GetKthElement(nums1, nums2, (total_size / 2 + 1))) / 2.0f;
    }
    
    static double Solution2(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()){
            return Solution2(nums2, nums1);
        }
        
        int size_nums1 = (int)nums1.size();
        int size_nums2 = (int)nums2.size();
        int left = 0, right = size_nums1;
        int media1 = 0, media2 = 0;
        
        while (left <= right){
            int left_size_nums1 = (left + right) / 2;
            int left_size_nums2 = (size_nums1 + size_nums2 + 1) / 2 - left_size_nums1;
            
            int left_max_value_nums1 = (left_size_nums1 == 0 ? INT_MIN : nums1[left_size_nums1 - 1]);
            int right_min_value_nums1 = (left_size_nums1 == size_nums1 ? INT_MAX : nums1[left_size_nums1]);
            int left_max_value_nums2 = (left_size_nums2 == 0 ? INT_MIN : nums2[left_size_nums2 - 1]);
            int right_min_value_nums2 = (left_size_nums2 == size_nums2 ? INT_MAX : nums2[left_size_nums2]);
            
            if (left_max_value_nums1 <= right_min_value_nums2){
                media1 = max(left_max_value_nums1, left_max_value_nums2);
                media2 = min(right_min_value_nums1, right_min_value_nums2);
                left = left_size_nums1 + 1;
            }else{
                right = left_size_nums1 - 1;
            }
        }
        
        return (size_nums1 + size_nums2) % 2 == 0 ? (media1 + media2) / 2.0 : media1;
    }
};

#endif /* find_median_sorted_arrays_h */
