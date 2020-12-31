//
//  walk_up_stairs.hpp
//  Recursion
//
//  Created by MarkWu on 2019/11/12.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef walk_up_stairs_h
#define walk_up_stairs_h
#include <iostream>
#include <chrono>
#include <unordered_map>

using namespace std;

int walk_up_stairs(int n)
{
    if (n == 1)
        return 1;
    
    if (n == 2)
        return 2;
    
    return walk_up_stairs(n - 1) + walk_up_stairs(n - 2);
}

unordered_map<int, int> solved_map;
int walk_up_stairs2(int n)
{
    if (n == 1)
        return 1;
    
    if (n == 2)
        return 2;
    
    unordered_map<int, int>::const_iterator target = solved_map.find(n);
    if (target != solved_map.end())
    {
        return target->second;
    }
    
    int ret = walk_up_stairs2(n - 1) + walk_up_stairs2(n - 2);
    solved_map.insert(pair<int, int>(n, ret));
    
    return ret;
}

int walk_up_stairs_no_recursion(int n)
{
    if (n == 1)
        return 1;
    
    if (n == 2)
        return 2;
    
    int ret = 0;
    int pre = 2;
    int prepre = 1;
    for (int i = 3; i <= n; i++)
    {
        ret = pre + prepre;
        prepre = pre;
        pre = ret;
    }
    
    return pre;
}

void test_walk_up_stairs(int n, int(*func)(int), const char* func_name)
{
    cout << "[test_walk_up_stairs], func_name:" << func_name << ", n: " << n << endl;
    
    std::chrono::milliseconds start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
                   std::chrono::system_clock::now().time_since_epoch());
                
    cout << "result: " << func(n) << endl;
    
    std::chrono::milliseconds end_time = std::chrono::duration_cast< std::chrono::milliseconds >(
        std::chrono::system_clock::now().time_since_epoch());
    
    cout << "time_consumed: " << (end_time.count() - start_time.count()) << "ms" << endl;
    
}


#endif /* walk_up_stairs_h */
