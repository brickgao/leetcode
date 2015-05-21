# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, r1, r2):
        if r1 is None and r2 is None:
            return True
        if ((r1 is None and r2) or
           (r1 and r2 is None)):
            return False
        if r1.val != r2.val:
            return False
        tag = True
        tag = tag and self.dfs(r1.left, r2.left)
        tag = tag and self.dfs(r1.right, r2.right)
        return tag

    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {boolean}
    def isSameTree(self, p, q):
        return self.dfs(p, q)
