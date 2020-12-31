//
//  three_sum.cpp
//  LeetCode
//
//  Created by MarkWu on 2020/11/23.
//  Copyright © 2020 Zego. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

class ThreeSum{
public:
    static vector<vector<int>> Solution(vector<int>& nums){
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int size = (int)nums.size();
        
        for (int first = 0; first < size; ++first){
            if (first > 0 && nums[first] == nums[first -1])
                continue;
            
            int third = size - 1;
            int target = -nums[first];
            
            for (int second = first + 1; second < size; ++second){
                if (second > (first + 1) && nums[second] == nums[second -1])
                    continue;
                
                while (second < third && (nums[second] + nums[third]) > target )
                    third--;
                
                if (second == third)
                    break;
                
                if (nums[second] + nums[third] == target)
                    ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        
        
        return ans;
    }
    
    static void TestSolution(){
        vector<int> vec = {-1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 2};
        
        vector<vector<int>> answer = Solution(vec);
        
        for (auto it = answer.begin(); it != answer.end(); ++it){
            cout << (*it)[0] << "," << (*it)[1] << "," << (*it)[2] << endl;
        }
    }
};
