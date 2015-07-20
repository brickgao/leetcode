# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def pre_dfs(self, node):
        _left = self.pre_dfs(node.left) if node.left else 0
        node.left_cnt = _left + 1
        _right = self.pre_dfs(node.right) if node.right else 0
        return _left + _right + 1

    # @param {TreeNode} root
    # @param {integer} k
    # @return {integer}
    def kthSmallest(self, root, k):
        self.pre_dfs(root)
        node = root
        while True:
            if node.left_cnt < k:
                k -= node.left_cnt
                node = node.right
            elif node.left_cnt > k:
                node = node.left
            else:
                return node.val


if __name__ == "__main__":
    solution = Solution()
    l = [2, 1, 3]
    l = map(TreeNode, l)
    l[0].right, l[0].left = l[1], l[2]
    print solution.kthSmallest(l[0], 3)
