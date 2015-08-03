# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def search(self, root):
        pre, now = None, root
        st = []
        while st or now:
            while now:
                st.append(now)
                now = now.left
            tmp = st.pop()
            if pre and tmp.val <= pre.val:
                self.l.append((pre, tmp))
            pre, now = tmp, tmp.right

    # @param {TreeNode} root
    # @return {void} Do not return anything, modify root in-place instead.
    def recoverTree(self, root):
        self.l = []
        self.search(root)
        if len(self.l) == 1:
            pre, now = self.l[0]
            pre.val, now.val = now.val, pre.val
        else:
            self.l[0][0].val, self.l[1][1].val = (
                self.l[1][1].val, self.l[0][0].val
            )


if __name__ == "__main__":
    solution = Solution()
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    b.left, b.right = c, a
    node = solution.recoverTree(b)
    print node.left.val, node.right.val
