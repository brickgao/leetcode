# -*- coding: utf-8 -*-


class Solution(object):
    def dfs(self, u, len):
        if len > self.longest_len:
            self.longest_p, self.longest_len = u, len
        for v in self.mp[u]:
            if not self.vis[v]:
                self.vis[v] = True
                self.dfs(v, len + 1)
                self.vis[v] = False

    def dfs_longest_path(self, u, len):
        if len > self.longest_len:
            self.longest_path, self.longest_len = self.tmp_path[:], len
        for v in self.mp[u]:
            if not self.vis[v]:
                self.vis[v] = True
                self.tmp_path.append(v)
                self.dfs_longest_path(v, len + 1)
                self.tmp_path.pop()
                self.vis[v] = False

    def findMinHeightTrees(self, n, edges):
        """
        :type n: int
        :type edges: List[List[int]]
        :rtype: List[int]
        """
        if n == 1:
            return [0]
        self.mp = dict([(i, list()) for i in range(n)])
        for u, v in edges:
            self.mp[u].append(v)
            self.mp[v].append(u)
        self.vis = [False for i in range(n)]
        self.longest_p, self.longest_len = -1, 1
        self.vis[0] = True
        self.dfs(0, 1)
        self.vis[0] = False
        print self.longest_p, self.longest_len
        self.longest_path, self.longest_len = [], 0
        self.vis[self.longest_p] = True
        self.tmp_path = [self.longest_p]
        self.dfs_longest_path(self.longest_p, 1)
        self.tmp_path.pop()
        self.vis[self.longest_p] = False
        if len(self.longest_path) % 2 == 1:
            return [self.longest_path[len(self.longest_path) // 2]]
        else:
            ret = [
                self.longest_path[len(self.longest_path) / 2 - 1],
                self.longest_path[len(self.longest_path) / 2]
            ]
            ret.sort()
            return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.findMinHeightTrees(4, [[1, 0], [1, 2], [1, 3]])
