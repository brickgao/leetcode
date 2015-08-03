# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {ListNode}
    def deleteDuplicates(self, head):
        if head is None:
            return None
        node, pre = head.next, head
        while node:
            if pre.val != node.val:
                pre.next = node
                pre = node
            node = node.next
        pre.next = None
        return head


if __name__ == '__main__':
    solution = Solution()
    a, b = ListNode(1), ListNode(1)
    c, d = ListNode(2), ListNode(2)
    e, f = ListNode(3), ListNode(3)
    a.next, b.next = b, c
    c.next, d.next = d, e
    e.next = f
    node = solution.deleteDuplicates(a)
    while node:
        print node.val
        node = node.next
