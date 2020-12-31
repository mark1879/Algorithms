//
//  main.cpp
//  CircularLinkedList
//
//  Created by MarkWu on 2019/5/29.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "circular_linked_list.hpp"
#include <cassert>

void TestInsertNode()
{
    log_v_print(">>> TestInsertNode");
    
    CircularLinkedList<int> circular_linked_list;
    
    unsigned int index;
    int value;
    int value_was_inserted;
    
    // insert the head
    index = 0;
    value = 100;
    assert(circular_linked_list.InsertNode(index, value) == true);
    assert(circular_linked_list.GetNode(index, value_was_inserted));
    assert(value_was_inserted == value);
    
    // insert the tail
    index = circular_linked_list.Size();
    value = 200;
    assert(circular_linked_list.InsertNode(index, value) == true);
    assert(circular_linked_list.GetNode(index, value_was_inserted));
    assert(value_was_inserted == value);
    
    // insert the intermediate
    index = circular_linked_list.Size() / 2;
    value = 150;
    assert(circular_linked_list.InsertNode(index, value) == true);
    assert(circular_linked_list.GetNode(index, value_was_inserted));
    assert(value_was_inserted == value);
    
    // index overflow
    index = circular_linked_list.Size() + 1;
    value = 0;
    assert(circular_linked_list.InsertNode(index, value) == false);
    
    index = circular_linked_list.Size();
    assert(circular_linked_list.GetNode(index, value_was_inserted) == false);
    
    circular_linked_list.Traverse(false);
    circular_linked_list.Traverse(true);
}

void TestDeleteNode()
{
    log_v_print(">>> TestDeleteNode");
    
    CircularLinkedList<int> circular_linked_list;
    
    for (unsigned int index = 0; index < 10; index++)
    {
        circular_linked_list.InsertNode(index, index);
    }
    
    // index overflow
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size()) == false);
    
    // delete the head
    assert(circular_linked_list.DeleteNode(0) == true);
    
    // delete the intermediate
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size() / 2) == true);
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size() / 2) == true);
    
    // delete the tail
    assert(circular_linked_list.DeleteNode(circular_linked_list.Size() - 1) == true);
    
    
    
    circular_linked_list.Traverse(false);
    circular_linked_list.Traverse(true);
}

int main(int argc, const char * argv[])
{
    
//    TestInsertNode();
    
    TestDeleteNode();
    
    return 0;
}
