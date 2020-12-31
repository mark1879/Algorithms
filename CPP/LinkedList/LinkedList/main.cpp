//
//  main.cpp
//  LinkedList
//
//  Created by MarkWu on 2019/3/16.
//  Copyright © 2019 Zego. All rights reserved.
//

#include <iostream>
#include "linked_list.hpp"
#include <cassert>

void TestInsertNode()
{
    log_v_print("<<< TestInsertNode");

    unsigned int index;
    unsigned int count;
    int value;
    int value_inserted;
    
    LinkedList<int> linked_list;
    
    // test index overflow
    index = linked_list.Size() + 1;
    assert(linked_list.Insert(index, 0) == false);
    std::cout << std::endl;
    
    // insert into the first position
    index = 0;
    value = 100;
    count = linked_list.Size();
    assert(linked_list.Insert(index, value) == true);
    assert(linked_list.Get(index, value_inserted));
    assert(value_inserted == value);
    assert(linked_list.Size() == (count + 1));
    std::cout << std::endl;
    
    // insert into the tail position
    index = linked_list.Size();
    value = 200;
    count = linked_list.Size();
    assert(linked_list.Insert(index, value) == true);
    assert(linked_list.Get(index, value_inserted) == true);
    assert(value_inserted == value);
    assert(linked_list.Size() == (count + 1));
    std::cout << std::endl;
    
    // insert into the immediate position
    index = linked_list.Size() / 2;
    value = 150;
    count = linked_list.Size();
    assert(linked_list.Insert(index, value) == true);
    assert(linked_list.Get(index, value_inserted) == true);
    assert(value_inserted == value);
    assert(linked_list.Size() == (count + 1));
    std::cout << std::endl;
    
    linked_list.Traverse();
    std::cout << std::endl;
}

void TestDeleteNode()
{
    log_v_print("<<< TestDeleteNode");
    
    const unsigned int kLengthOfList = 5;
    
    unsigned int index;
    unsigned int count;
    int value_inserted;
    int value_deleted;
    int value;
    
    LinkedList<int> linked_list;
    
    for (unsigned int i = 0; i < kLengthOfList; i++)
    {
        linked_list.Insert(i, i);
        assert(linked_list.Size() == (i + 1));
        
        linked_list.Get(i, value_inserted);
        assert(value_inserted == i);
    }
    
    std::cout << std::endl;
    
    // test index overflow
    index = kLengthOfList;
    assert(linked_list.Delete(index) == false);
    std::cout << std::endl;
    
    // delete the intermediate node
    index = kLengthOfList / 2;
    value = index;
    count = linked_list.Size();
    assert(linked_list.Delete(index) == true);
    linked_list.Get(index, value_deleted);
    assert(value != value_deleted);
    assert(linked_list.Size() == (count - 1));
    std::cout << std::endl;
    
    // delete the first node
    index = 0;
    value = 0;
    count = linked_list.Size();
    assert(linked_list.Delete(index) == true);
    linked_list.Get(index, value_deleted);
    assert(value != value_deleted);
    assert(linked_list.Size() == (count - 1));
    std::cout << std::endl;
    
    // delete the last node
    index = linked_list.Size() - 1;
    value = kLengthOfList - 1;
    count = linked_list.Size();
    assert(linked_list.Delete(index) == true);
    linked_list.Get((index - 1), value_deleted);
    assert(value != value_deleted);
    assert(linked_list.Size() == (count - 1));
    std::cout << std::endl;
    
    linked_list.Traverse();
    std::cout << std::endl;
}

void verify_data(const unsigned int size_of_data)
{
    LinkedList<int> linked_list;
   
    if (size_of_data == 0)
    {
        // empty list
        assert(linked_list.Reverse() == false);
        return;
    }
    
   int data[size_of_data];
   for (unsigned int i = 0; i < size_of_data; i++)
   {
       data[i] = i;
       linked_list.Insert(i, i);
   }
   
   linked_list.Reverse();
    
    linked_list.Traverse();
   
//   for (unsigned int i = 0; i < size_of_data; i++)
//   {
//       int value;
//       linked_list.GetNode(i, value);
//       assert(value == data[size_of_data - 1 - i]);
//   }
}

void TestReverseNode()
{
    log_v_print("<<< TestReverseNode");
    
    verify_data(0);
    verify_data(1);
    verify_data(3);
}


int main(int argc, const char * argv[])
{
    TestInsertNode();
    TestDeleteNode();
    TestReverseNode();
    
    return 0;
}
