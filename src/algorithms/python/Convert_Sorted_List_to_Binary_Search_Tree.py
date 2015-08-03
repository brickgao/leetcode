# -*- coding: utf-8 -*-


# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def build(self, l, r):
        if l == r:
            return None
        if l == r - 1:
            node = TreeNode(self.node.val)
            self.node = self.node.next
            return node
        mid = (l + r) >> 1
        l_node = self.build(l, mid)
        node = TreeNode(self.node.val)
        self.node = self.node.next
        r_node = self.build(mid + 1, r)
        node.left, node.right = l_node, r_node
        return node

    # @param {ListNode} head
    # @return {TreeNode}
    def sortedListToBST(self, head):
        length = 0
        node = head
        while node:
            length += 1
            node = node.next
        self.node = head
        return self.build(0, length)


if __name__ == "__main__":
    a, b = ListNode(1), ListNode(2)
    c = ListNode(3)
    a.next, b.next = b, c
    solution = Solution()
    node = solution.sortedListToBST(a)
    print node.val, node.left.val, node.right.val
