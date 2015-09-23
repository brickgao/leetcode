# -*- coding: utf-8 -*-


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def dfs(self, root):
        self.path.append(str(root.val))
        if not root.left and not root.right:
            self.ret.append("->".join(self.path))
        if root.left:
            self.dfs(root.left)
        if root.right:
            self.dfs(root.right)
        self.path.pop()

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        """
        self.ret, self.path = [], []
        if root:
            self.dfs(root)
        return self.ret


if __name__ == "__main__":
    solution = Solution()
    node11 = TreeNode(1)
    node21, node22 = TreeNode(2), TreeNode(3)
    node31 = TreeNode(5)
    node11.left, node11.right = node21, node22
    node21.right = node31
    print solution.binaryTreePaths(node11)
