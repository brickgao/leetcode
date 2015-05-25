# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def levelOrderBottom(self, root):
        ret = []
        q, l = [root], []
        cnt1, cnt2, bound = 0, 0, 1
        while q != []:
            node = q[0]
            q = q[1:]
            cnt1 += 1
            if node:
                left, right = node.left, node.right
                q += [left, right]
                l.append(node.val)
                cnt2 += 1
            if cnt1 == bound:
                if l != []:
                    ret.append(list(l))
                l, cnt1, cnt2, bound = [], 0, 0, cnt2 * 2
        return ret[::-1]
