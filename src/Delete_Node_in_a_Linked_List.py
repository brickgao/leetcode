# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} node
    # @return {void} Do not return anything, modify node in-place instead.
    def deleteNode(self, node):
        l = []
        while node:
            l.append(node)
            node = node.next
        for i in range(len(l) - 1):
            l[i].val = l[i + 1].val
        l[-2].next = None
