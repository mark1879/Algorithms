//
//  z_transform.hpp
//  LeetCode
//
//  Created by MarkWu on 2021/1/25.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef z_transform_h
#define z_transform_h
#include <iostream>

using  namespace std;

class ZTransformation{
public:
    static string Solution1(string s, int num_rows){
        string z_str;
        int size = (int)s.size();
        
        for (int i = 0; i < num_rows; ++i){
            int position = i;
            bool is_down = false;
            while (position < size){
                z_str.push_back(s[position]);
                
                if (i == 0){
                    is_down = true;
                }else if (i < (num_rows - 1)){
                    is_down = is_down ? false : true;
                }
                
                if (is_down){
                    position = position + (num_rows - 1 - i) * 2;
                }else{
                    position = position + i * 2;
                }
            }
        }
        return z_str;
    }
    
    static void TestSolution1(){
        cout << Solution1("A", 1) << endl;
//        cout << Solution1("PAYPALISHIRING", 3) << endl;
//        cout << Solution1("PAYPALISHIRING", 4) << endl;
    }
};


#endif /* z_transform_h */
