//
//  main.cpp
//  Recursion
//
//  Created by MarkWu on 2019/11/12.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "walk_up_stairs.hpp"
#include "recursive_sorting.hpp"

using namespace std;

int main(int argc, const char * argv[])
{
    int n = 50;
//
    test_walk_up_stairs(n, (int(*)(int))walk_up_stairs, "walk_up_stairs");
//    test_walk_up_stairs(n, (int(*)(int))walk_up_stairs2, "walk_up_stairs2");
//    test_walk_up_stairs(n, (int(*)(int))walk_up_stairs_no_recursion, "walk_up_stairs_no_recursion");
    
    
//    test_recursive_sorting();
    
    return 0;
}
