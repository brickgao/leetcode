# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def reverseList(self, head):
        if head is None:
            return None
        l, node = [], head
        while node:
            l.append(node)
            node = node.next
        for i in range(len(l) - 1, 0, -1):
            l[i].next = l[i - 1]
        l[0].next = None
        return l[-1]
