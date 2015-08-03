# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def get_height(self, path):
        node, h, tmp = self.root, 0, 1 << (self.max_h - 2)
        while node:
            if tmp & path:
                node = node.right
            else:
                node = node.left
            tmp >>= 1
            h += 1
        return h

    # @param {TreeNode} root
    # @return {integer}
    def countNodes(self, root):
        if root is None:
            return 0
        if root.left is None:
            return 1
        self.root, self.max_h = root, 0
        node = root
        while node:
            node = node.left
            self.max_h += 1
        l, r = 0, (1 << (self.max_h - 1)) - 1
        while l < r - 1:
            mid = (l + r) >> 1
            _h = self.get_height(mid)
            if _h == self.max_h:
                l = mid
            else:
                r = mid
        l_h, r_h = self.get_height(l), self.get_height(r)
        if l_h == r_h:
            return 2 ** self.max_h - 1
        elif l_h == self.max_h - 1:
            return 2 ** (self.max_h - 1) + l - 1
        else:
            return 2 ** (self.max_h - 1) + r - 1


if __name__ == "__main__":
    solution = Solution()
    l = [1, 2, 3, 4]
    node = map(TreeNode, l)
    node[0].left, node[0].right = node[1], node[2]
    node[1].left = node[3]
    print solution.countNodes(node[0])
