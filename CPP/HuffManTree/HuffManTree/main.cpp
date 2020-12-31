//
//  main.cpp
//  HuffManTree
//
//  Created by MarkWu on 2019/6/14.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "huffman_tree.hpp"

// Driver program to test above functions
int main()
{
    
    char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    
    int size = sizeof(arr) / sizeof(arr[0]);
    
    HuffmanCodes(arr, freq, size);
    
    return 0;
}
