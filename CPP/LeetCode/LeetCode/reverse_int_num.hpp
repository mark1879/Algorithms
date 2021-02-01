//
//  reverse_int_num.hpp
//  LeetCode
//
//  Created by MarkWu on 2021/2/1.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef reverse_int_num_h
#define reverse_int_num_h
#include <iostream>

class ReverseIntNum{
    public:
    static int Solution1(int x){
        int new_num = 0;

        while (x){
            if (new_num < INT_MIN / 10 || new_num > INT_MAX / 10)
            return 0;

            new_num = new_num * 10 + x % 10;
            x = x / 10;
        }

        return new_num;
    }

    static void TestSolution1(){
        cout << Solution1(1463847412) << endl;
        cout << Solution1(-1463847412) << endl;

    }
    
    
    static int Solution2(int x){
        string int_str = std::to_string(x);
        
        if (x >= 0){
            std::reverse(int_str.begin(), int_str.end());
        }else{
            std::reverse(int_str.begin() + 1, int_str.end());
        }
        
        return std::stoi(int_str);
    }
    
    static void TestSolution2(){
        cout << Solution2(1463847412) << endl;
        cout << Solution2(-1463847412) << endl;

    }
};


#endif /* reverse_int_num_h */
