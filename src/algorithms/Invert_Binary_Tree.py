# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root):
        _left, _right = root.left, root.right
        if _left:
            self.dfs(_left)
        if _right:
            self.dfs(_right)
        root.left, root.right = _right, _left

    # @param {TreeNode} root
    # @return {TreeNode}
    def invertTree(self, root):
        if root is None:
            return None
        self.dfs(root)
        return root


if __name__ == "__main__":
    soution = Solution()
