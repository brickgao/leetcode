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
        ret = root.val
        if l > 0:
            ret += l
        if r > 0:
            ret += r
        self.ret = max(self.ret, ret)
        return max(root.val, root.val + l, root.val + r)

    # @param {TreeNode} root
    # @return {integer}
    def maxPathSum(self, root):
        self.ret = -100000000000
        self.dfs(root)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    a.left, a.right = b, c
    print solution.maxPathSum(a)
