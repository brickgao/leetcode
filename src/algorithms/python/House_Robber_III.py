#!/bin/env python2
# -*- coding: utf-8 -*-


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def dfs(self, root):
        v0, v1, nxts = 0, root.val, [root.left, root.right]
        for nxt in nxts:
            if nxt:
                _v = self.dfs(nxt)
                v0, v1 = v0 + max(_v[0], _v[1]), v1 + _v[0]
        return (v0, v1)

    def rob(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        return max(self.dfs(root)) if root else 0
