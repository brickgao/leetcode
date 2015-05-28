# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root, cnt):
        if root.left:
            self.dfs(root.left, cnt + root.val)
        if root.right:
            self.dfs(root.right, cnt + root.val)
        if root.left is None and root.right is None:
            if cnt + root.val == self.sum:
                self.flag = True

    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def hasPathSum(self, root, sum):
        if root is None:
            return False
        self.flag = False
        self.sum = sum
        self.dfs(root, 0)
        return self.flag


if __name__ == "__main__":
    solution = Solution()
    print solution.hasPathSum(None, 0)
    node = TreeNode(1)
    print solution.hasPathSum(node, 1)
