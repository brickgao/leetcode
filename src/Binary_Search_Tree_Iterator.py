# -*- coding: utf-8 -*-


# Definition for a  binary tree node
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class BSTIterator:
    # @param root, a binary search tree's root node
    def __init__(self, root):
        self.l, self.cnt = [], 0
        if root:
            self.dfs(root)
        self.l = self.l[::-1]

    def dfs(self, root):
        if root.left:
            self.dfs(root.left)
        self.l.append(root.val)
        if root.right:
            self.dfs(root.right)

    # @return a boolean, whether we have a next smallest number
    def hasNext(self):
        if self.l == []:
            return False
        else:
            return True

    # @return an integer, the next smallest number
    def next(self):
        return self.l.pop()


# Your BSTIterator will be called like this:
# i, v = BSTIterator(root), []
# while i.hasNext(): v.append(i.next())
if __name__ == "__main__":
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    b.left, b.right = a, c
    i, v = BSTIterator(b), []
    while i.hasNext():
        v.append(i.next())
    print v
