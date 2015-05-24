# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def build(self, prel, prer, inl, inr):
        root = self.preorder[prel]
        index = self.inorder.index(root, inl, inr)
        root_node = TreeNode(root)
        if index - inl:
            root_node.left = self.build(
                prel + 1, prel + index - inl + 1,
                inl, index
            )
        if inr - index - 1:
            root_node.right = self.build(
                prel + index - inl + 1, prer,
                index + 1, inr
            )
        return root_node

    # @param {integer[]} preorder
    # @param {integer[]} inorder
    # @return {TreeNode}
    def buildTree(self, preorder, inorder):
        if preorder == [] and inorder == []:
            return None
        self.length = len(preorder)
        self.preorder, self.inorder = preorder, inorder
        return self.build(
            0, self.length,
            0, self.length
        )

if __name__ == "__main__":
    solution = Solution()
    node = solution.buildTree([1, 2, 3], [2, 1, 3])
    print node.val, node.left.val, node.right.val
