//
//  main.cpp
//  BSTree
//
//  Created by MarkWu on 2020/4/29.
//  Copyright © 2020 Zego. All rights reserved.
//

#include <iostream>
#include  <vector>

#include "binary_search_tree.hpp"
#include "zego_log.hpp"

using namespace std;

void rotate(vector<int>& nums, int k) {
    size_t size = nums.size();
    size_t last_element_index = size - 1;
    int shift_right = k % size;
    for (int i = 0; i < shift_right; i++){
        int temp = nums[last_element_index];
        for (auto it = nums.end() - 1; it > nums.begin(); it--){
            *it = *(it - 1);
        }
        nums[0] = temp;
    }
   }

void rotate2(vector<int>& nums, int k) {
    int shift_elements = k % nums.size();
    
    if (shift_elements > 0){
        int copy_bytes = shift_elements * sizeof(int);
        u_char *temp = new u_char[copy_bytes];
        
        memcpy(temp, &nums[nums.size() - shift_elements], copy_bytes);
        memcpy(&nums[shift_elements], &nums[0], copy_bytes);
        memcpy(&nums[0], temp, copy_bytes);
        
        delete []temp;
    }
}

void rotate3(vector<int>& nums, int k){
    reverse(nums.begin(),nums.end());

    reverse(nums.begin(),nums.begin()+k%nums.size());

    reverse(nums.begin()+k%nums.size(),nums.end());
}

int main(int argc, const char * argv[]) {
    
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
//    rotate(vec, 5);
//    rotate2(vec, 3);
    
//    rotate3(vec, 3);
//    
//    for (auto it = vec.cbegin(); it != vec.cend(); it++)
//        cout << *it << endl;
    
    
    std::cout << string_format("hello %s\n", "mark");
//
//    std::cout << sum(100, 100) << std::endl;
//
//    std::mutex mutex;
//
//    std::vector<int> vec;
//    vec.push_back(1);
//
//    int a = 2;
//
//    std::cout << (a >> 2) << std::endl;
    
//    std::cout << "Hello, World!\n";
    return 0;
}
