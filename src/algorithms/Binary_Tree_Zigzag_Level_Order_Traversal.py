# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    # @param {TreeNode} root
    # @return {integer[][]}
    def zigzagLevelOrder(self, root):
        ret = []
        q, l = [root], []
        tag = False
        cnt1, cnt2, bound = 0, 0, 1
        while q != []:
            node = q[0]
            q = q[1:]
            cnt1 += 1
            if node:
                left, right = node.left, node.right
                q += [left, right]
                l.append(node.val)
                cnt2 += 1
            if cnt1 == bound:
                if l != []:
                    if tag:
                        l = l[::-1]
                    ret.append(list(l))
                l, cnt1, cnt2, bound = [], 0, 0, cnt2 * 2
                tag = not tag
        return ret


if __name__ == "__main__":
    solution = Solution()
    a = TreeNode(1)
    b, c = TreeNode(2), TreeNode(2)
    d, e = TreeNode(3), TreeNode(3)
    a.left, a.right = b, c
    b.right, c.left = d, e
    print solution.zigzagLevelOrder(a)
