# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param head, a ListNode
    # @return a boolean
    def hasCycle(self, head):
        node1, node2 = head, head
        while node1 and node2:
            node1 = node1.next
            if node2.next:
                node2 = node2.next.next
            else:
                node2 = node2.next
            if node1 and node1 == node2:
                return True
        return False
        
