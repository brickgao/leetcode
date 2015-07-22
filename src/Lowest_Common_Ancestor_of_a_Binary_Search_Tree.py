# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution:
    def dfs(self, node):
        _ret, _left, _right = 0, node.left, node.right
        if _left:
            _ret += self.dfs(_left)
        if _right:
            _ret += self.dfs(_right)
        if node == self.p or node == self.q:
            _ret += 1
        if _ret == 2 and not self.ret:
            self.ret = node
        return _ret

    # @param {TreeNode} root
    # @param {TreeNode} p
    # @param {TreeNode} q
    # @return {TreeNode}
    def lowestCommonAncestor(self, root, p, q):
        self.p, self.q, self.ret = p, q, None
        if self.dfs(root) == 2 and not self.ret:
            return root
        else:
            return self.ret


if __name__ == "__main__":
    solution = Solution()
    l = [1, 2, 3, 4, 5]
    l = map(TreeNode, l)
    l[0].left, l[0].right = l[1], l[2]
    l[1].left, l[1].right = l[3], l[4]
    print solution.lowestCommonAncestor(l[0], l[1], l[2]).val
    print solution.lowestCommonAncestor(l[0], l[3], l[4]).val
    print solution.lowestCommonAncestor(l[0], l[2], l[4]).val
