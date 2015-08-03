# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, root):
        if not self.tag:
            return (-1, -1)
        l = [root.val]
        if root.left and root.left.val >= root.val:
            self.tag = False
        if root.right and root.right.val <= root.val:
            self.tag = False
        if root.left:
            left_node = self.dfs(root.left)
            if left_node[1] >= root.val:
                self.tag = False
            l.append(left_node[0])
        if root.right:
            right_node = self.dfs(root.right)
            if right_node[0] <= root.val:
                self.tag = False
            l.append(right_node[1])
        return min(l), max(l)

    # @param {TreeNode} root
    # @return {boolean}
    def isValidBST(self, root):
        if root is None:
            return True
        self.tag = True
        self.dfs(root)
        return self.tag


if __name__ == "__main__":
    solution = Solution()
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    b.left, b.right = a, c
    print solution.isValidBST(b)
    b.left, b.right = c, a
    print solution.isValidBST(b)
