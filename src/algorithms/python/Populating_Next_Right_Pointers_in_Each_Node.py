# -*- coding: utf-8 -*-

from Queue import Queue


# Definition for binary tree with next pointer.
class TreeLinkNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
        self.next = None


class Solution:
    # @param root, a tree link node
    # @return nothing
    def connect(self, root):
        if root is None:
            return None
        q = Queue()
        q.put(root)
        pre = None
        cnt, now, nxt = 0, 1, 0
        while not q.empty():
            cnt += 1
            top = q.get()
            if pre is None:
                pre = top
            else:
                pre.next = top
                pre = top
            if top.left:
                nxt += 1
                q.put(top.left)
            if top.right:
                nxt += 1
                q.put(top.right)
            if cnt == now:
                cnt, now = 0, nxt
                nxt, pre = 0, None


if __name__ == "__main__":
    solution = Solution()
    a, b, c = TreeLinkNode(1), TreeLinkNode(2), TreeLinkNode(3)
    a.left, a.right = b, c
    solution.connect(a)
    print a.next is None
    print b.next is c, c.next is None
