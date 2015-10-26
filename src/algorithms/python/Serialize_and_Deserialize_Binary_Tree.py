# -*- coding: utf-8 -*-


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        if root is None:
            return repr([])
        ret_l, cnt = [], 0
        st, vis = [root], {}
        while st != []:
            now = st[-1]
            if now not in vis:
                vis[now] = -1
                if now.left:
                    st.append(now.left)
                if now.right:
                    st.append(now.right)
            else:
                st.pop()
                vis[now] = cnt
                cnt += 1
                children = [-1, -1]
                if now.left:
                    children[0] = vis[now.left]
                if now.right:
                    children[1] = vis[now.right]
                ret_l.extend([now.val, children[0], children[1]])
        return repr(ret_l)

    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        l, node_l = eval(data), []
        for index in xrange(0, len(l), 3):
            val, l_child, r_child = l[index], l[index + 1], l[index + 2]
            node = TreeNode(val)
            if l_child != -1:
                node.left = node_l[l_child]
            if r_child != -1:
                node.right = node_l[r_child]
            node_l.append(node)
        return node_l[-1] if node_l != [] else None


# Your Codec object will be instantiated and called as such:
if __name__ == "__main__":
    root = TreeNode(1)
    node21, node22 = TreeNode(2), TreeNode(3)
    node33, node34 = TreeNode(4), TreeNode(5)
    root.left, root.right = node21, node22
    node22.left, node22.right = node33, node34
    codec = Codec()
    print codec.serialize(root)
    print codec.serialize(None)
    ret = codec.deserialize(codec.serialize(root))
    print (ret.val, ret.left.val, ret.right.val,
           ret.right.left.val, ret.right.right.val)
