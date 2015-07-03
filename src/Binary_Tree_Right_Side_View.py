# -*- coding: utf-8 -*-

from Queue import Queue


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def bfs(self, root):
        q, ret = Queue(), []
        tmp, end = None, root
        q.put(root)
        while not q.empty():
            node = q.get()
            if node.left:
                q.put(node.left)
                tmp = node.left
            if node.right:
                q.put(node.right)
                tmp = node.right
            if node == end:
                end = tmp
                ret.append(node.val)
        return ret

    # @param {TreeNode} root
    # @return {integer[]}
    def rightSideView(self, root):
        if root is None:
            return []
        result = self.bfs(root)
        return result


if __name__ == "__main__":
    vals = [1, 2, 3, 4, 5]
    nodes = map(TreeNode, vals)
    nodes[0].left, nodes[0].right = nodes[1], nodes[2]
    nodes[1].right, nodes[2].right = nodes[4], nodes[3]
    solution = Solution()
    print solution.rightSideView(nodes[0])
