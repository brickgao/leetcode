# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def deal(self, cnt, node):
        if node is None:
            return
        if cnt == self.m - 1:
            self.beg1 = node
        if cnt == self.n + 1:
            self.end1 = node
        if cnt == self.m:
            self.beg2 = node
        if cnt == self.n:
            self.end2 = node
        self.deal(cnt + 1, node.next)
        if self.m <= cnt < self.n:
            node.next.next = node

    # @param {ListNode} head
    # @param {integer} m
    # @param {integer} n
    # @return {ListNode}
    def reverseBetween(self, head, m, n):
        self.beg1, self.end1 = None, None
        self.beg2, self.end2 = None, None
        self.m, self.n = m, n
        self.deal(1, head)
        if self.beg1:
            self.beg1.next = self.end2
        else:
            head = self.end2
        self.beg2.next = self.end1
        return head


if __name__ == "__main__":
    solution = Solution()
    a, b = ListNode(1), ListNode(2)
    c, d = ListNode(3), ListNode(4)
    e = ListNode(5)
    a.next, b.next = b, c
    c.next, d.next = d, e
    node = solution.reverseBetween(a, 1, 4)
    while node:
        print node.val
        node = node.next
