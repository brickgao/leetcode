# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root, cnt):
        self.l.append(root.val)
        if root.left:
            self.dfs(root.left, cnt + root.val)
        if root.right:
            self.dfs(root.right, cnt + root.val)
        if root.left is None and root.right is None:
            if cnt + root.val == self.sum:
                self.ret.append(list(self.l))
        self.l.pop()

    # @param {TreeNode} root
    # @param {integer} sum
    # @return {boolean}
    def pathSum(self, root, sum):
        if root is None:
            return []
        self.sum = sum
        self.l, self.ret = [], []
        self.dfs(root, 0)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    print solution.pathSum(None, 0)
    node = TreeNode(1)
    print solution.pathSum(node, 1)
