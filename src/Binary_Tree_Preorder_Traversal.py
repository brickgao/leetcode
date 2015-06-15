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
    def preorderTraversal(self, root):
        ret = []
        if not root:
            return ret
        st = []
        st.append(root)
        while len(st):
            node = st.pop()
            ret.append(node.val)
            if node.right:
                st.append(node.right)
            if node.left:
                st.append(node.left)
        return ret


if __name__ == "__main__":
    solution = Solution()
    a, b, c, d = TreeNode(1), TreeNode(4), TreeNode(3), TreeNode(2)
    a.left, a.right = b, c
    b.left = d
    print solution.preorderTraversal(a)
