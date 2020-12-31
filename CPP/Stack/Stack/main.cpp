//
//  main.cpp
//  Stack
//
//  Created by MarkWu on 2019/9/14.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "array_stack.hpp"
#include "linked_stack.hpp"

using namespace std;

void test_array_stack()
{
    cout << "[test_array_stack] Start" << endl;
    
    ArrayStack<int> array_stack;
    
    const int max_size = 1000;
    
    for (int i = 0; i < max_size; i++)
    {
        assert(array_stack.Push(i) == true);
        assert(array_stack.Size() == (i + 1));
        int value;
        assert(array_stack.GetNode(i, value) == true);
        assert(value == i);
    }
    
    // overflow
    assert(array_stack.Push(-1) == false);
    
     int value;
    
    for (int i = max_size - 1; i >= 0; i--)
    {
        assert(array_stack.Pop(value) == true);
        assert(value == i);
        assert(array_stack.Size() == i);
    }
   
    // empty
    assert(array_stack.Pop(value) == false);
    
    
    cout << "[test_array_stack] Done" << endl;
    
}

void test_linked_stack()
{
    cout << "[test_linked_stack] Start" << endl;
    
    Stack<int> stack;
    
    const int max_size = 100;
    
    // test push
    for (int i = 0; i < max_size; i++)
    {
        assert(stack.Push(i) == true);
        assert(stack.Size() == i + 1);
        int value;
        assert(stack.GetNode(0, value) == true);
        assert(value == i);
    }
    
    // overflow
    assert(stack.Push(-1) == false);
    
    int value;
    
    // test pop
    for (int i = max_size - 1; i >= 0; i--)
    {
        assert(stack.Pop(value) == true);
        assert(stack.Size() == i);
        assert(value == i);
    }
    
    // tempty
    assert(stack.Pop(value) == false);
    
    cout << "[test_linked_stack] Done" << endl;
}

int main(int argc, const char * argv[])
{
    test_array_stack();
    test_linked_stack();
    
    return 0;
}
