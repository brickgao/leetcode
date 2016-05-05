#!/bin/env python2
# -*- coding: utf-8 -* -


class Solution(object):
    def dfs(self, x, y, now):
        moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        for x_diff, y_diff in moves:
            _x, _y = x + x_diff, y + y_diff
            if (
                0 <= _x < self.m and
                0 <= _y < self.n and
                self.matrix[_x][_y] > self.matrix[x][y] and
                self.rec[_x][_y] < now + 1
            ):
                self.rec[_x][_y] = now + 1
                self.dfs(_x, _y, now + 1)

    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        if len(matrix) == 0:
            return 0
        self.matrix = matrix
        self.m, self.n = len(matrix), len(matrix[0])
        self.rec = [[0 for i in range(self.n)] for j in range(self.m)]
        for x in range(self.m):
            for y in range(self.n):
                if self.rec[x][y] <= 1:
                    self.rec[x][y] = 1
                    self.dfs(x, y, 1)
        return max(map(max, self.rec))
