# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def build(self, inl, inr, postl, postr):
        root = self.postorder[postr - 1]
        index = self.inorder.index(root, inl, inr)
        root_node = TreeNode(root)
        if index - inl:
            root_node.left = self.build(
                inl, index,
                postl, postl + index - inl
            )
        if inr - index - 1:
            root_node.right = self.build(
                index + 1, inr,
                postl + index - inl, postr - 1
            )
        return root_node

    # @param {integer[]} inorder
    # @param {integer[]} postorder
    # @return {TreeNode}
    def buildTree(self, inorder, postorder):
        if postorder == [] and inorder == []:
            return None
        self.length = len(inorder)
        self.inorder, self.postorder = inorder, postorder
        return self.build(
            0, self.length,
            0, self.length
        )

if __name__ == "__main__":
    solution = Solution()
    node = solution.buildTree([2, 1, 3], [2, 3, 1])
    print node.val, node.left.val, node.right.val
