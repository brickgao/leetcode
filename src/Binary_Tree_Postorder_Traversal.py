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
    def postorderTraversal(self, root):
        if not root:
            return []
        st, ret = [root], []
        vis = {}
        while len(st) != 0:
            node = st.pop()
            if str(node) in vis:
                ret.append(node.val)
            else:
                vis[str(node)] = True
                st.append(node)
                if node.right:
                    st.append(node.right)
                if node.left:
                    st.append(node.left)
        return ret


if __name__ == "__main__":
    a, b, c = TreeNode(1), TreeNode(2), TreeNode(3)
    a.left, a.right = b, c
    solution = Solution()
    print solution.postorderTraversal(a)
