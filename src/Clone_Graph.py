# -*- coding: utf-8 -*-


# Definition for a undirected graph node
class UndirectedGraphNode:
    def __init__(self, x):
        self.label = x
        self.neighbors = []


class Solution:
    def dfs(self, root):
        ret = self.vis[root.label]
        for node in root.neighbors:
            if node.label not in self.vis:
                self.vis[node.label] = UndirectedGraphNode(node.label)
                self.dfs(node)
            ret.neighbors.append(self.vis[node.label])
        return ret

    # @param node, a undirected graph node
    # @return a undirected graph node
    def cloneGraph(self, node):
        if node is None:
            return None
        self.vis = {
            node.label: UndirectedGraphNode(node.label)
        }
        ret = self.dfs(node)
        return ret


if __name__ == "__main__":
    solution = Solution()
    a = UndirectedGraphNode(1)
    b = UndirectedGraphNode(2)
    c = UndirectedGraphNode(3)
    a.neighbors, b.neighbors, c.neighbors = [b], [c], [a]
    node = solution.cloneGraph(a)
    print (
        node.label,
        node.neighbors[-1].label,
        node.neighbors[-1].neighbors[-1].label,
        node.neighbors[-1].neighbors[-1].neighbors[-1].label
    )
