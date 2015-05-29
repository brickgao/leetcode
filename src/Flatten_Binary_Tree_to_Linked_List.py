# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root):
        if root is None:
            return
        self.pre.left = root
        self.pre = root
        self.dfs(root.left)
        self.dfs(root.right)
        root.right = None

    # @param {TreeNode} root
    # @return {void} Do not return anything, modify root in-place instead.
    def flatten(self, root):
        if root is None:
            return None
        head = TreeNode(-1)
        head.left = root
        self.pre = head
        self.dfs(root)
        pre, node = head, root
        while node:
            pre.left = None
            pre.right = node
            if root is None:
                break
            pre = node
            node = node.left
        return root

if __name__ == "__main__":
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    b.left, b.right = a, c
    solution = Solution()
    node = solution.flatten(b)
    print node.val, node.right.val, node.right.right.val
