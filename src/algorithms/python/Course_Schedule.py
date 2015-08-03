# -*- coding: utf-8 -*-


class Solution:
    def dfs(self, src):
        self.vis[src], tag = True, True
        for dst in self.maps[src]:
            if not self.vis[dst]:
                tag = tag and self.dfs(dst)
            else:
                self.is_not_loop[src] = self.is_not_loop[dst]
                return self.is_not_loop[src]
        self.is_not_loop[src] = tag
        return self.is_not_loop[src]

    # @param {integer} numCourses
    # @param {integer[][]} prerequisites
    # @return {boolean}
    def canFinish(self, numCourses, prerequisites):
        self.maps = [[] for i in range(numCourses)]
        self.vis = [False for i in range(numCourses)]
        self.is_not_loop = [False for i in range(numCourses)]
        for src, dst in prerequisites:
            self.maps[src].append(dst)
        for i in range(numCourses):
            if not self.vis[i]:
                if not self.dfs(i):
                    return False
        return True


if __name__ == "__main__":
    solution = Solution()
    print solution.canFinish(2, [[1, 0]])
    print solution.canFinish(2, [[1, 0], [0, 1]])
