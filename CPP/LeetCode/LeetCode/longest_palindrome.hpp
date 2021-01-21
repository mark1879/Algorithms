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
//                    longest_palindrome = s.substr(ret, (i - ret + 1));
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
        
//        cout << Solution1("anugnxshgonmqydttcvmtsoaprxnhpmpovdolbidqiyqubirkvhwppcdyeouvgedccipsvnobrccbndzjdbgx") << endl;
    }
};

#endif /* longest_palindrome_h */
