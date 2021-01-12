//
//  length_of_longest_sub_string.cpp
//  LeetCode
//  给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
//
//  Created by MarkWu on 2020/6/3.
//  Copyright © 2020 Zego. All rights reserved.
//

#ifndef LENGTH_OF_LONGEST_SUB_STRING
#define LENGTH_OF_LONGEST_SUB_STRING

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>

using namespace std;

class LengthOfLongestSubString
{
public:
    static int Solution1(string s)
    {
        vector<char> vec;
        int max_length = 0;
        
        for (auto c : s){
            auto ret = std::find(vec.begin(), vec.end(), c);
            if (ret == vec.end()){
                vec.push_back(c);
            }else{
                max_length = max(max_length, (int)vec.size());
                vec.erase(vec.begin(), ++ret);
                vec.push_back(c);
            }
        }
        
        return max(max_length, (int)vec.size());
    }
    
    
    // official solution：sliding window + unordered_set
    static int Solution2(string s){
        unordered_set<char> occ;
        int rp = -1, max_length = 0;
        
        for (int i = 0, size = (int)s.size(); i < size; i++){
            if (i != 0){
                occ.erase(s[i -1]);
            }
            
            while ((rp + 1 < size) && !occ.count(s[rp + 1])){
                occ.insert(s[rp + 1]);
                ++rp;
            }
            
            max_length = max(max_length, (rp - i + 1));
        }
        
        return max_length;
    }
    
    static int Solution3(string s){
        unordered_map<char, int> occ;
        int max_length = 0;
        int lp = 0;
        
        for (int i = 0, size = (int)s.size(); i < size; i++){
            if (occ.find(s[i]) != occ.end() && occ[s[i]] >= lp){
                lp = occ[s[i]] + 1;
            }
            
            occ[s[i]] = i;
            max_length = max(max_length, (i - lp + 1));
        }
     
        return max_length;
    }
    
};

#endif
