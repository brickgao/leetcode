# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, beg, end):
        res = []
        if beg > end:
            res.append(None)
            return res
        for root in range(beg, end + 1):
            l_list = self.dfs(beg, root - 1)
            r_list = self.dfs(root + 1, end)
            for l in range(0, len(l_list)):
                for r in range(0, len(r_list)):
                    node = TreeNode(root)
                    node.left = l_list[l]
                    node.right = r_list[r]
                    res.append(node)
        return res

    # @param {integer} n
    # @return {TreeNode[]}
    def generateTrees(self, n):
        return self.dfs(1, n)

if __name__ == "__main__":
    solution = Solution()
    ret = solution.generateTrees(3)
    print len(ret)
