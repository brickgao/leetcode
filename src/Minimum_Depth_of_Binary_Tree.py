# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root, dep):
        if root.left:
            self.dfs(root.left, dep + 1)
        if root.right:
            self.dfs(root.right, dep + 1)
        if root.left is None and root.right is None:
            self.dep = min(dep + 1, self.dep)

    # @param {TreeNode} root
    # @return {integer}
    def minDepth(self, root):
        if root is None:
            return 0
        self.dep = 0xFFFFFFFFFFFF
        self.dfs(root, 0)
        return self.dep


if __name__ == "__main__":
    solution = Solution()
    a, b = TreeNode(1), TreeNode(2)
    a.left = b
    print solution.minDepth(a)
