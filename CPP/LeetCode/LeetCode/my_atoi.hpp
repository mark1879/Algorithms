//
//  my_atoi.hpp
//  LeetCode
//
//  Created by MarkWu on 2021/2/5.
//  Copyright © 2021 Zego. All rights reserved.
//

#ifndef my_atoi_h
#define my_atoi_h

using namespace std;

class MyAtoi{
public:
    static int Solution1(string s){
        long result = 0;
        int sign = 1;
        bool found_num = false;
        
        for (int i = 0, size = (int)s.size(); i < size; i++){
            char chr = s[i];
            
            if (chr == ' ' && !found_num)
                continue;
            
            if ((chr == '-' || chr == '+') && !found_num){
                found_num = true;
                if (chr == '-')
                    sign = -1;
                
                continue;
            }
            
            int num = chr - '0';
            if (num >= 0 && num <= 9){
                if (!found_num)
                    found_num = true;
                result = result * 10 + num;
            }else{
                break;
            }
            
            long temp = result * sign;
            if (temp < INT_MIN)
                return INT_MIN;
            
            if (temp > INT_MAX)
                return INT_MAX;
        }
            
        return (int)(result * sign);
    }
    
    static void TestSolution1(){
        cout << Solution1("  -12") << endl;
        cout << Solution1("  --12") << endl;
        cout << Solution1("  -12 ") << endl;
        cout << Solution1("  -12a") << endl;
        cout << Solution1("  - 12") << endl;
        cout << Solution1("  -a12") << endl;

        cout << Solution1("  +12") << endl;
        cout << Solution1("  ++12") << endl;
        cout << Solution1("  +12 ") << endl;
        cout << Solution1("  +12a") << endl;
        cout << Solution1("  + 12") << endl;
        cout << Solution1("  +a12") << endl;
        
        cout << Solution1("-9128347233") << endl;
    }
    
};


#endif /* my_atoi_h */
