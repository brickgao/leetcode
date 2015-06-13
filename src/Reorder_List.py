# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {void} Do not return anything, modify head in-place instead.
    def reorderList(self, head):
        l, node = [], head
        while node:
            l.append(node)
            node = node.next
        half = (len(l) + 1) / 2
        l1, l2 = l[:half], l[half:][::-1]
        length1, length2 = len(l1), len(l2)
        for i in range(length1):
            if i < length2:
                l1[i].next = l2[i]
                l2[i].next = l1[i + 1] if i + 1 < length1 else None
            else:
                l1[i].next = None
        return head


if __name__ == "__main__":
    solution = Solution()
    a, b, c, d = ListNode(1), ListNode(2), ListNode(3), ListNode(4)
    a.next, b.next, c.next = b, c, d
    node = solution.reorderList(a)
    while node:
        print node.val
        node = node.next
