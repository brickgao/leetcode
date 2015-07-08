# -*- coding: utf-8 -*-


class Solution:
    # @param {integer} numCourses
    # @param {integer[][]} prerequisites
    # @return {integer[]}
    def findOrder(self, numCourses, prerequisites):
        ret, vis = [], [False for i in range(numCourses)]
        maps = [[] for i in range(numCourses)]
        degree_in = [0 for i in range(numCourses)]
        for v, u in prerequisites:
            maps[u].append(v)
            degree_in[v] += 1
        left = numCourses
        while True:
            tag = False
            for u in range(numCourses):
                if degree_in[u] == 0 and not vis[u]:
                    vis[u], left, tag = True, left - 1, True
                    ret.append(u)
                    for v in maps[u]:
                        degree_in[v] -= 1
            if not tag:
                return []
            if left <= 0:
                break
        return ret


if __name__ == "__main__":
    solution = Solution()
    print solution.findOrder(2, [[1, 0]])
    print solution.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]])
