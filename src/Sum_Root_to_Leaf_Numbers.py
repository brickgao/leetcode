# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root, now):
        now = now * 10 + root.val
        if not root.left and not root.right:
            self.cnt += now
            return
        if root.left:
            self.dfs(root.left, now)
        if root.right:
            self.dfs(root.right, now)

    # @param {TreeNode} root
    # @return {integer}
    def sumNumbers(self, root):
        if root is None:
            return 0
        self.cnt = 0
        self.dfs(root, 0)
        return self.cnt


if __name__ == "__main__":
    solution = Solution()
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    a.left, a.right = b, c
    print solution.sumNumbers(a)
