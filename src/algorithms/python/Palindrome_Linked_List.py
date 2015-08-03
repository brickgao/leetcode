# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    # @param {ListNode} head
    # @return {boolean}
    def isPalindrome(self, head):
        if not head:
            return True
        node, length, end = head, 0, None
        while node:
            if not node.next:
                end = node
            node, length = node.next, length + 1
        node = head
        for i in range(length / 2):
            node = node.next
        pre = node
        node = node.next
        while node:
            _next = node.next
            node.next, pre = pre, node
            node = _next
        node1, node2 = head, end
        for i in range(length / 2):
            if node1.val != node2.val:
                return False
            node1, node2 = node1.next, node2.next
        return True


if __name__ == "__main__":
    solution = Solution()
    l = [1, 2, 3, 3, 1]
    l = map(ListNode, l)
    for i in range(len(l) - 1):
        l[i].next = l[i + 1]
    print solution.isPalindrome(l[0])
