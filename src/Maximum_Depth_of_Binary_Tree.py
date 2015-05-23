# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root, dep):
        dep += 1
        self.dep = max(dep, self.dep)
        l, r = root.left, root.right
        if l:
            self.dfs(l, dep)
        if r:
            self.dfs(r, dep)

    # @param {TreeNode} root
    # @return {integer}
    def maxDepth(self, root):
        self.dep = 0
        if root is None:
            return 0
        self.dfs(root, 0)
        return self.dep


if __name__ == "__main__":
    solution = Solution()
    a = TreeNode(1)
    b, c = TreeNode(2), TreeNode(3)
    a.left, a.right = b, c
    print solution.maxDepth(a)
