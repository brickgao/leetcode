# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def getLength(self, node):
        if node is None:
            return
        self.length += 1
        nxt = node.next
        self.getLength(nxt)

    def dfs(self, node):
        if node.next is None:
            self.cnt, self.tail = self.cnt + 1, node
            return
        self.dfs(node.next)
        self.cnt += 1
        if self.cnt == self.k + 1:
            self.new_tail = node

    # @param {ListNode} head
    # @param {integer} k
    # @return {ListNode}
    def rotateRight(self, head, k):
        if head is None:
            return None
        self.length = 0
        self.getLength(head)
        self.k, self.cnt = k % self.length, 0
        self.new_tail, self.tail = None, None
        self.dfs(head)
        if self.new_tail and self.tail:
            self.tail.next = head
            beg, self.new_tail.next = self.new_tail.next, None
            return beg
        else:
            return head


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(2)
    c, d = ListNode(3), ListNode(4)
    e = ListNode(5)
    a.next, b.next = b, c
    c.next, d.next = d, e
    head = solution.rotateRight(a, 2)
    while head:
        print head.val
        head = head.next
