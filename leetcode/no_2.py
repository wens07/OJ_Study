# no_2.py
# Author: wengqiang
# Date Last Modified: 16:59 2016/9/12
#
# Changelog:
#  
#     
#
# Usage:
#    
#     

#!/usr/bin/env python
# coding=utf-8


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """

        result_root = ListNode( (l1.val + l2.val) % 10)
        carry = (l1.val + l2.val) // 10

        l1 = l1.next
        l2 = l2.next
        curnode = result_root

        while (l1 != None) and (l2 != None):

            tmpnode = ListNode((l1.val + l2.val + carry) % 10)
            carry = (l1.val + l2.val + carry) // 10
            curnode.next = tmpnode
            curnode = tmpnode
            l1 = l1.next
            l2 = l2.next

        while l1 != None:
            tmpnode = ListNode((l1.val + carry) % 10)
            carry = (l1.val + carry) // 10
            curnode.next = tmpnode
            curnode = tmpnode
            l1 = l1.next


        while l2 != None:
            tmpnode = ListNode((l2.val + carry) % 10)
            carry = (l2.val + carry) // 10
            curnode.next = tmpnode
            curnode = tmpnode
            l2 = l2.next

        if carry != 0:
            curnode.next = ListNode(carry)

        return result_root





