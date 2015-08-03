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
            return 0
        l = self.dfs(root.left)
        r = self.dfs(root.right)
        if abs(l - r) > 1:
            self.flag = False
        return max(l, r) + 1

    # @param {TreeNode} root
    # @return {boolean}
    def isBalanced(self, root):
        self.flag = True
        self.dfs(root)
        return self.flag


if __name__ == "__main__":
    solution = Solution()
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    b.left = a
    print solution.isBalanced(b)
