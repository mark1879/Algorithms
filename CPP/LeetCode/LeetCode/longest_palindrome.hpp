//
//  longest_palindrome.hpp
//  LeetCode
//
//  Created by MarkWu on 2021/1/18.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef longest_palindrome_h
#define longest_palindrome_h
#include <algorithm>

class LongestPalindrome {
public:
    static int IsPalindrome(const string& s, int left, int right){
        while (left < right){
            if (s[left] != s[right])
                return false;
            
            ++left;
            --right;
        }
        
        return true;
    }
    
    // 暴力搜索
    static string Solution1(string s) {
        int size = (int)s.size();
        
        if (size == 0)
            return "";
        
        string longest_palindrome;
        int start = 0, end = 0;
        
        for(unsigned i = (size -1); i >= 0; i--){
            if (i <= end - start)
                break;
            
            auto ret = s.find(s[i], 0);
            
            while (i - ret > end - start){
                if (IsPalindrome(s, (int)ret, i)){
                    start = (int)ret;
                    end = i;
                    break;
                }
                
                ret = s.find(s[i], ret + 1);
            }
        }
        
        return s.substr(start, (end - start + 1));
    }
    
    static void TestSolution1(){
        cout << Solution1("eabcb") << endl;
        cout << Solution1("anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgx") << endl;
    }
    
    
    // 动态规划
    static string Solution2(string s){
        int size = (int)s.size();
        vector<vector<int>> dp(size, vector<int>(size));
        
        int start = 0, end = 0;
        
        for (int l = 0; l < size; ++l) {
            for (int i = 0; i + l < size; ++i) {
                int j = i + l;
                if (l == 0) {
                    dp[i][j] = 1;
                } else if (l == 1) {
                    dp[i][j] = (s[i] == s[j]);
                } else {
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                }
                
                if (dp[i][j] && (l > end - start)) {
                    start = i;
                    end = l;
                }
            }
        }
        return s.substr(start, end + 1);
    }
    
    static void TestSolution2(){
        cout << Solution2("eabcb") << endl;
        cout << Solution2("anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgx") << endl;

    }
    
    static pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        int size = (int)s.size();
        
        while (left >= 0 && right < size && s[left] == s[right]){
            left--;
            right++;
        }
        
        return {++left, --right};
    }
    
    // 中心扩散法
    static string Solution3(string s){
        if (s.size() == 0){
            return "";
        }
        
        int start = 0, end = 0;
        
        for (int i = 0, size = (int)s.size(); i < size; i++){
            pair<int, int> ret1 = expandAroundCenter(s, i, i);
            pair<int, int> ret2 = expandAroundCenter(s, i, i+1);
            
            if (ret1.second - ret1.first > end - start){
                start = ret1.first;
                end = ret1.second;
            }
            
            if (ret2.second - ret2.first > end - start){
                start = ret2.first;
                end = ret2.second;
            }
        }
        
        return s.substr(start, end - start + 1);
    }
    
    static void TestSolution3(){
        cout << Solution3("") << endl;
        cout << Solution3("a") << endl;
        cout << Solution3("ab") << endl;
        cout << Solution3("aa") << endl;
        cout << Solution3("anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgx") << endl;
    }
};

#endif /* longest_palindrome_h */
