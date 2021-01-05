//
//  two_sum.cpp
//  LeetCode
// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
//
//  Created by MarkWu on 2020/11/11.
//  Copyright © 2020 Zego. All rights reserved.
//

#include <stdio.h>
#include <unordered_map>

using namespace std;

class TwoSum {
public:
    static vector<int> Solution1(const vector<int>& nums, int target){
        unordered_map<int, int> hash_table;
        
        size_t size = nums.size();
        
        for (int i = 0; i < size; i++){
            auto it = hash_table.find(target - nums[i]);
            if (it != hash_table.end()){
                return {it->second, i};
            }
            hash_table[nums[i]] = i;
        }
        
        return {};
    }
    
    static void TestSolution1(){
        vector<int> nums = {1, 2, 3, 5};
        vector<int> result = TwoSum::Solution1(nums, 6);
        
        if (result.size() > 1){
            cout << result[0] << ":" << result[1] << endl;
        }
    }
    
    static vector<int> Solution2(const vector<int>& nums, int target){
        size_t size = nums.size();
        for (int i = 0; i < (size - 1); i++){
            for (int j = i + 1; j < size; j++){
                if (nums[i] + nums[j] == target){
                    return {i, j};
                }
            }
        }
        return {};
    }
    
    static void TestSolution2(){
        vector<int> nums = {1, 2, 3, 5};
        vector<int> result = TwoSum::Solution2(nums, 6);
        
        if (result.size() > 1){
            cout << result[0] << ":" << result[1] << endl;
        }
    }
};
