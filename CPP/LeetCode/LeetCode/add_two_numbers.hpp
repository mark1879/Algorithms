//
//  add_two_numbers.cpp
//  LeetCode
//
//  Created by MarkWu on 2020/12/4.
//  Copyright © 2020 Zego. All rights reserved.
//

#include <stdio.h>
#include "linked_list.hpp"

class AddTwoNumbers {
public:
    static ListNode<int>* Solution1(ListNode<int>* l1, ListNode<int>* l2) {
        ListNode<int> *head = nullptr, *tail = nullptr;
        int carry = 0;

        while (l1 || l2){
            int v1 = l1 ? l1->value : 0;
            int v2 = l2 ? l2->value : 0;
            int sum = v1 + v2 + carry;
            
            if (head == nullptr){
                head = tail = new ListNode<int>(sum % 10);
            }else{
                tail->next = new ListNode<int>(sum % 10);
                tail = tail->next;
            }

            carry = sum / 10;

            if (l1){
                l1 = l1->next;
            }

            if (l2){
                l2 = l2->next;
            }
        }

        if (carry > 0){
            tail->next = new ListNode<int>(carry);
        }

        return head;
    }
    
    static void TestSolution1(){
        Solution1(nullptr, nullptr);
    }
};

