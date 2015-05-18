# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param {TreeNode} root
    # @return {integer[]}
    def inorderTraversal(self, root):
        ret, st = [], []
        node = root
        while node or len(st) != 0:
            if node:
                st.append(node)
                node = node.left
            else:
                node = st.pop()
                ret.append(node.val)
                node = node.right
        return ret


if __name__ == "__main__":
    solution = Solution()
    a, b = TreeNode(1), TreeNode(2)
    c = TreeNode(3)
    a.right, b.left = b, c
    print solution.inorderTraversal(a)
